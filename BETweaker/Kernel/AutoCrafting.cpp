#include "../Global.h"
#include <MC/Block.hpp>
#include <MC/SortItemInstanceIdAux.hpp>
#include <MC/ItemInstance.hpp>
#include <MC/Recipe.hpp>
#include <MC/CraftingContainer.hpp>
#include <mc/BlockActor.hpp>
#include <MC/DispenserBlockActor.hpp>
#include <MC/Recipes.hpp>
#include <MC/Spawner.hpp>
#include <MC/HopperBlockActor.hpp>


namespace Module {
    //std::unordered_map<int, std::map<string, std::shared_ptr<Recipe>>> RecipeList;
    std::map<string, std::shared_ptr<Recipe>> RecipeList;
    std::unordered_map<uint64_t, ItemInstance> TempCraftiingList;
    const Block* craftingTable = nullptr;
    const Block* Stone = nullptr;
    const Block* Cobblestone = nullptr;
    //std::unordered_map<string, std::shared_ptr<Recipe>> RecipeList;

    bool isBlackList(string a5) {
        for (auto& toolitem : Settings::AutoCraftingBlacklistItems) {
            if (a5.find(toolitem) != std::string::npos) {
                return true;
            }
        }
        return false;
    }

    void InitAutoCrafting() {

        auto recipesByOutputs = dAccess<std::map<HashedString const, std::map<std::string, std::shared_ptr<Recipe>>>>(&Global<Level>->getRecipes(), 16);
        for (auto recipesMap : recipesByOutputs) {
            if (recipesMap.first.getString() == "crafting_table") {
                if (recipesMap.second.empty()) continue;
                for (auto& i : recipesMap.second) {
                    if (!isBlackList(i.first)) {
                        RecipeList.emplace(i.first, i.second);
                    }
                }
            }
        }
        craftingTable = Block::create("minecraft:crafting_table", 0);
        Stone = Block::create("minecraft:stone", 0);
        Cobblestone = Block::create("minecraft:cobblestone", 0);
    }

    bool AutoCrafting(DispenserBlockActor* ba, BlockSource* a2, BlockPos pos) {
        auto outputpos = pos.add(0, -1);
        auto be = a2->getBlockEntity(outputpos);
        if (a2->getBlock(pos) == *craftingTable) {
            if (be) {
                if (be->getType() == BlockActorType::Hopper) {
                    uint64_t tempItem = 0;
                    auto cont = ba->getContainer();
                    auto itemlist = cont->getAllSlots();
                    for (auto i : itemlist) {
                        tempItem += i->getFullNameHash().getHash() + i->getAux();
                    }

                    if (TempCraftiingList.find(tempItem) != TempCraftiingList.end()) {
                        auto hpcont = ((HopperBlockActor*)be)->getContainer();
                        auto out = hpcont->addItem_s((ItemStack*)&TempCraftiingList[tempItem]);
                        if (!out) {
                            Global<Level>->getSpawner().spawnItem(*a2, *(ItemStack*)&TempCraftiingList[tempItem], nullptr, pos.toVec3(), 0);
                        }
                        cont->removeAllItems();
                        return false;
                    }

                    CraftingContainer ctn(3, 3);
                    for (auto i = 0; i < itemlist.size(); ++i) {
                        ctn.setItem(i, *itemlist[i]);
                    }
					
                    for (auto& i : RecipeList) {
                        bool match = i.second->matches(ctn, *Global<Level>);
                        if (!match) continue;
                        auto& recipeOutputs = i.second->assemble(ctn);
                        auto hpcont = ((HopperBlockActor*)be)->getContainer();
                        if (recipeOutputs.size() != 1) continue;
                        auto outresult = hpcont->addItem_s((ItemStack*)&recipeOutputs[0]);
						if (!outresult) {
                            Global<Level>->getSpawner().spawnItem(*a2, *(ItemStack*)&recipeOutputs[0], nullptr, pos.toVec3(), 0);
						}
                        TempCraftiingList.emplace(tempItem, recipeOutputs[0]);
                        cont->removeAllItems();
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