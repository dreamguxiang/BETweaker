#include <global.h>

namespace AutoCrafting {
    std::map<string, std::shared_ptr<Recipe>> recipeList;
    std::unordered_map<uint64_t, ItemInstance> tempCraftingList;
    const Block* craftingTableBlock = nullptr;
    const Block* stoneBlock = nullptr;
    const Block* cobblestoneBlock = nullptr;

    bool isItemInBlackList(const string& itemName) {
        for (const auto& blacklistedItem : settings::AutoCraftingBlacklistItems) {
            if (itemName.find(blacklistedItem) != std::string::npos) {
                return true;
            }
        }
        return false;
    }

    void initializeAutoCrafting() {
        const auto& recipesByOutputs = dAccess<std::map<HashedString const, std::map<std::string, std::shared_ptr<Recipe>>>>(&Global<Level>->getRecipes(), 16);
        for (const auto& recipePair : recipesByOutputs) {
            if (recipePair.first.getString() == "crafting_table") {
                if (recipePair.second.empty()) continue;
                for (const auto& recipe : recipePair.second) {
                    if (!isItemInBlackList(recipe.first)) {
                        recipeList[recipe.first] = recipe.second;
                    }
                }
            }
        }
    }

    bool performAutoCrafting(DispenserBlockActor* dispenserBlockActor, BlockSource* blockSource, BlockPos position) {
        auto outputPosition = position.add(0, -1);
        auto blockEntity = blockSource->getBlockEntity(outputPosition);
        if (blockEntity) {
            if (blockSource->getBlock(position) == *StaticVanillaBlocks::mCraftingTable) {
                if (blockEntity->getType() == BlockActorType::Hopper) {
                    uint64_t tempItemHash = 0;
                    auto container = dispenserBlockActor->getContainer();
                    const auto& itemList = container->getAllSlots();
                    for (const auto& item : itemList) {
                        tempItemHash += item->getFullNameHash().getHash() + item->getAux();
                    }

                    if (tempCraftingList.find(tempItemHash) != tempCraftingList.end()) {
                        auto hopperContainer = ((HopperBlockActor*)blockEntity)->getContainer();
                        auto addResult = hopperContainer->addItem_s((ItemStack*)&tempCraftingList[tempItemHash]);
                        if (!addResult) {
                            Global<Level>->getSpawner().spawnItem(*blockSource, *(ItemStack*)&tempCraftingList[tempItemHash], nullptr, position.toVec3(), 0);
                        }
                        container->removeAllItems();
                        return false;
                    }

                    auto& craftingContainer = *ll::memory::createObject<CraftingContainer, 0x100>(3, 3);
                    for (auto i = 0; i < itemList.size(); ++i) {
                        craftingContainer.setItem(i, *itemList[i]);
                    }

                    for (const auto& recipe : recipeList) {
                        //CraftingContext()
                        char filler1[16];
                        auto levelInstance = SymCall("??$?0PEAVLevel@@X@?$not_null@V?$NonOwnerPointer@VILevel@@@Bedrock@@@gsl@@QEAA@AEBV?$"
                            "not_null@PEAVLevel@@@1@@Z",
                            void*, char*, Level**)(filler1, &Global<Level>);
                        char filler2[0x1E0];
                        auto globalCraftingContext = SymCall(
                            "??0CraftingContext@@QEAA@V?$not_null@V?$NonOwnerPointer@VILevel@@@Bedrock@@@gsl@@@Z",
                            CraftingContext*, char*, void*)(filler2, levelInstance);

                        bool match = recipe.second->matches(craftingContainer, *globalCraftingContext);
                        if (!match) continue;
                        const auto& recipeOutputs = recipe.second->assemble(craftingContainer, *globalCraftingContext);
                        auto hopperContainer = ((HopperBlockActor*)blockEntity)->getContainer();
                        if (recipeOutputs.size() != 1) continue;
                        auto addResult = hopperContainer->addItem_s((ItemStack*)&recipeOutputs[0]);
                        if (!addResult) {
                            Global<Level>->getSpawner().spawnItem(*blockSource, *(ItemStack*)&recipeOutputs[0], nullptr, position.toVec3(), 0);
                        }
                        tempCraftingList[tempItemHash] = recipeOutputs[0];
                        container->removeAllItems();
                        return false;
                    }
                }
            }
        }
        else {
            return true;
        }
        return false;
    }
}


LL_AUTO_TYPED_INSTANCE_HOOK(
    AutoCraftingHook1,
    DispenserBlock,
    HookPriority::Normal,
    "?dispenseFrom@DispenserBlock@@MEBAXAEAVBlockSource@@AEBVBlockPos@@@Z",
    void,
    BlockSource* region, BlockPos* pos)
{
    if (!settings::AutoCrafting) return origin(region, pos);
    DispenserBlockActor* dispenser = (DispenserBlockActor*)region->getBlockEntity(*pos);
    if (dispenser)
    {
        Level& level = region->getLevel();
        auto Container = dispenser->getContainer();
        ((RandomizableBlockActorContainerBase*)dispenser)->unPackLootTable(level, *Container, region->getDimensionId(), 0);
        int v9 = dispenser->getRandomSlot(level.getRandom());
        auto& items = Container->getItem(v9);
        if (!items.isNull() && items.getCount() > 0)
        {
            int face = getFacing(region->getBlock(*pos));
            auto newpos = pos->neighbor(face);
            if (settings::AutoCrafting)
                if (AutoCrafting::performAutoCrafting(dispenser, region, newpos)) return;
        }
    }
    return origin(region, pos);
}