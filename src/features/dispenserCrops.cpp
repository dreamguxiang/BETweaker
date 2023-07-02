#include <global.h>

namespace DispenserCrops {
    bool dispenseItem(BlockSource* blockSource, Vec3* position, FaceID faceID, ItemStack* itemStack) {
        auto blockPos = position->toBlockPos();
        if (!itemStack->isNull()) {
            auto& block = blockSource->getBlock(blockPos);
            auto& blockBelow = blockSource->getBlock(blockPos.add(0, -1, 0));
            if (itemStack->getItem()->isSeed()) {
                if (blockBelow.getName().getString() == StaticVanillaBlocks::mFarmlandBlock->getName().getString() &&
                    block.getName().getString() == "minecraft:air") {
                    auto outputBlock = dAccess<Block*, 8>(dAccess<SeedItemComponentLegacy*, 512>(itemStack->getItem()));
                    Level::setBlock(blockPos, blockSource->getDimensionId(), outputBlock);
                    itemStack->remove(1);
                    return true;
                }
            }
            else if (settings::CanDispenserItemList.count(itemStack->getTypeName())) {
                if (itemStack->isBlock() && itemStack->getBlock()->mayPlaceOn(*blockSource, blockPos.add(0, -1, 0)) &&
                    block.getName().getString() == "minecraft:air") {
                    Block* saplingBlock = const_cast<Block*>(itemStack->getBlock());
                    Level::setBlock(blockPos, blockSource->getDimensionId(), saplingBlock);
                    itemStack->remove(1);
                    return true;
                }
            }
        }
        return false;
    }

    std::tuple<bool, bool> isDispenserBlockOrDropperBlock(void* a1) {
        if (!a1)
            return std::make_tuple(false, false);
        auto type = ((BlockLegacy*)a1)->getBlockEntityType();
        return std::make_tuple(type == BlockActorType::Dispenser, type == BlockActorType::Dropper);
    }
}

LL_AUTO_STATIC_HOOK(
    DispenserCropsHook1,
    HookPriority::Normal,
    "?ejectItem@DispenserBlock@@IEBAXAEAVBlockSource@@AEBVVec3@@EAEBVItemStack@@AEAVContainer@@HH@Z",
    void,
    void* a1,BlockSource* blockSource,Vec3* position, FaceID face,
    ItemStack* itemStack,Container* container,unsigned int slot,int count
) {
    auto [isDispenserBlock, isDropperBlock] = DispenserCrops::isDispenserBlockOrDropperBlock(a1);
    if (isDispenserBlock) {
        if (DispenserCrops::dispenseItem(blockSource, position, face, itemStack))
            return;
    }
    return origin(a1, blockSource, position, face, itemStack, container, slot, count);
}
