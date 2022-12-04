#include "../Global.h"
#include <MC/SeedItemComponentLegacy.hpp>
#include <MC/BlockActor.hpp>
#include <MC/CameraItemComponentLegacy.hpp>
#include <MC/Material.hpp>
#include <MC/BlockActorDataPacket.hpp>

namespace Module {

	bool DispenserItemFunc(BlockSource* a2, Vec3* a3, FaceID a4, ItemStack* a5) {
        auto pos = a3->toBlockPos();
        if (!a5->isNull()) {
            if (a5->getItem()->isSeed()) {
                if (a2->getBlock(pos.add(0, -1, 0)).getTypeName() == "minecraft:farmland" &&
                    a2->getBlock(pos).getTypeName() == "minecraft:air") {
                    auto out = dAccess<Block*, 8>(dAccess<SeedItemComponentLegacy*, 512>(a5->getItem()));//IDA Item::_useOn
                    Level::setBlock(pos, a2->getDimensionId(), out);
                    a5->remove(1);
                    return true;
                }
            } 
            else if (Settings::CanDispenserItemList.count(a5->getTypeName()))
            {
                //Level::broadcastText(std::to_string(a5->getBlock()->mayPlaceOn(*a2, pos.add(0, -1, 0))), TextType::RAW);
                if (a5->isBlock()) {
                    if (a5->getBlock()->mayPlaceOn(*a2, pos.add(0, -1, 0)) &&
                        a2->getBlock(pos).getTypeName() == "minecraft:air")
                    {
                        Block* sapbl = const_cast<Block*>(a5->getBlock());
                        Level::setBlock(pos, a2->getDimensionId(), sapbl);
                        a5->remove(1);
                        return true;
                    }
                }
                else {
                }
            }
        }
        return false;
	}
    bool isToolItem(ItemStack* a5) {
        for (auto& toolitem : Settings::DispenserDestroyItemList) {
			if(a5->getTypeName().find(toolitem) != std::string::npos) {
				return true;
			}
		}
        return false;
    }
    float getDestroyProgress(ItemStack& a5, Block* block,BlockPos pos,BlockSource* a2) {
        auto v4 = ((CameraItemComponentLegacy*)block)->slideAwayDuration();
        float result = 0.0;
        if (v4 >= 0.0)
        {
            if (v4 == 0.0)
            {
                result = 1.0;
            }
            else {
                auto v6 = 1.0 / v4;
                v6 = 1.0 / v4;
                auto& Material = block->getMaterial();
                if (Material.isAlwaysDestroyable())
                    return (float)(a5.getDestroySpeed(*Level::getBlock(pos, a2)) * v6) * 0.033333335;
                if (a5.canDestroySpecial(*block))
                    return (float)(a5.getDestroySpeed(*Level::getBlock(pos, a2)) * v6) * 0.033333335;
                else
                    return (float)(a5.getDestroySpeed(*Level::getBlock(pos, a2)) * v6) * 0.0099999998;
            }
        }
        return result;
    }
    bool DispenserDestroy(BlockActor* ba,BlockSource* a2, BlockPos* pos, ItemStack& a5, int solt, BlockPos* old) {
        if(a5){
        if (isToolItem(&a5)) {
            if (ba->getCustomName() == "DestroyBlock-Open") {
                auto block = Level::getBlock(pos, a2);
                //auto out = getDestroyProgress(a5, block, *pos, a2);
                if (block->getTypeName() == "minecraft:air") {
                    return true;
                }
                else {
                    auto canDestroy = false || (block->getDestroySpeed() >= 0.0f);
                    if (!canDestroy)
                        return false;

                    auto& material = block->getMaterial();
                    bool shouldDrop = material.isAlwaysDestroyable() || a5.canDestroySpecial(*block);
                    shouldDrop = shouldDrop && !false;

                    if (shouldDrop) {
                        bool out = Global<Level>->destroyBlock(*a2, *pos, shouldDrop);
                        if (Settings::DispenserDestroyBreakItem) a5.hurtAndBreak(1, nullptr);
                    }
                    return true;
                }
            }
            }
        }
        return false;
    }

    void ChangeDispenserMode(BlockActor* ba,BlockSource* bs,Player* sp) {
        if (ba->getCustomName() == "DestroyBlock-Close" || ba->getCustomName().empty()) {
            ba->setCustomName("DestroyBlock-Open");
            sp->sendTextPacket("§b[BETweaker-Dispenser] OPEN", TextType::JUKEBOX_POPUP);
        }
        else if (ba->getCustomName() == "DestroyBlock-Open") {
            ba->setCustomName("DestroyBlock-Close");
            sp->sendTextPacket("§b[BETweaker-Dispenser] CLOSE", TextType::JUKEBOX_POPUP);
        }
        auto pkt = ba->getServerUpdatePacket(*bs);
        Level::sendPacketForAllPlayers(*pkt);
    }

}