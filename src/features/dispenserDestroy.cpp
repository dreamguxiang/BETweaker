#include <global.h>

namespace DispenserDestroy {

    bool isTool(ItemStack* itemStack) {
        for (auto& tool : settings::DispenserDestroyItemList) {
            if (itemStack->getTypeName().find(tool) != std::string::npos) {
                return true;
            }
        }
        return false;
    }

    float getDestructionProgress(ItemStack& itemStack, Block* block, BlockPos position, BlockSource* blockSource) {
        auto slideDuration = ((CameraItemComponentLegacy*)block)->slideAwayDuration();
        float progress = 0.0;
        if (slideDuration >= 0.0)
        {
            if (slideDuration == 0.0)
            {
                progress = 1.0;
            }
            else {
                auto reciprocalDuration = 1.0 / slideDuration;
                auto& material = block->getMaterial();
                if (material.isAlwaysDestroyable())
                    return (float)(itemStack.getDestroySpeed(*Level::getBlock(position, blockSource)) * reciprocalDuration) * 0.033333335;
                if (itemStack.canDestroySpecial(*block))
                    return (float)(itemStack.getDestroySpeed(*Level::getBlock(position, blockSource)) * reciprocalDuration) * 0.033333335;
                else
                    return (float)(itemStack.getDestroySpeed(*Level::getBlock(position, blockSource)) * reciprocalDuration) * 0.0099999998;
            }
        }
        return progress;
    }

    bool destroyWithDispenser(BlockActor* blockActor, BlockSource* blockSource, BlockPos* position, ItemStack& itemStack, int slot, BlockPos* oldPosition) {
        if (itemStack) {
            if (isTool(&itemStack)) {
                if (blockActor->getCustomName() == "DestroyBlock-Open") {
                    auto block = Level::getBlock(position, blockSource);
                    if (block->getName().getString() == "minecraft:air") {
                        return true;
                    }
                    else {
                        auto canDestroy = block->getDestroySpeed() >= 0.0f;
                        if (!canDestroy)
                            return false;

                        auto& material = block->getMaterial();
                        bool shouldDrop = (material.isAlwaysDestroyable() || itemStack.canDestroySpecial(*block)) && !false;

                        if (shouldDrop) {
                            bool destructionResult = Global<Level>->destroyBlock(*blockSource, *position, shouldDrop);
                            if (settings::DispenserDestroyBreakItem) itemStack.hurtAndBreak(1, nullptr);
                        }
                        return true;
                    }
                }
            }
        }
        return false;
    }

    void toggleDispenserMode(BlockActor* blockActor, BlockSource* blockSource, Player* player) {
        if (blockActor->getCustomName() == "DestroyBlock-Close" || blockActor->getCustomName().empty()) {
            blockActor->setCustomName("DestroyBlock-Open");
            player->sendTextPacket("¡ìb[BETweaker-Dispenser] OPEN", TextType::JUKEBOX_POPUP);
        }
        else if (blockActor->getCustomName() == "DestroyBlock-Open") {
            blockActor->setCustomName("DestroyBlock-Close");
            player->sendTextPacket("¡ìb[BETweaker-Dispenser] CLOSE", TextType::JUKEBOX_POPUP);
        }
        auto updatePacket = blockActor->getServerUpdatePacket(*blockSource);
        Level::sendPacketForAllPlayers(*updatePacket);
    }

}

LL_AUTO_TYPED_INSTANCE_HOOK(
    DispenserDestroyHook,
    DispenserBlock,
    HookPriority::Normal,
    "?dispenseFrom@DispenserBlock@@MEBAXAEAVBlockSource@@AEBVBlockPos@@@Z",
    void,
    BlockSource* region, BlockPos* pos)
{
    if (!settings::DispenserDestroyBlock) return origin(region, pos);
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
            if (settings::DispenserDestroyBlock)
                if (DispenserDestroy::destroyWithDispenser((BlockActor*)dispenser, region, &newpos, const_cast<ItemStack&>(items), v9, pos)) return;
        }
    }
    return origin(region, pos);
}

