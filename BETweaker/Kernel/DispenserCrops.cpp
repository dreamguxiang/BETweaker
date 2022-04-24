#include "../Global.h"
#include <MC/SeedItemComponentLegacy.hpp>
#include "../Main/setting.h"
namespace Module {

	bool DispenserItemFunc(DispenserBlock* a1,BlockSource* a2, Vec3* a3, FaceID a4, ItemStack* a5, Container* a6, unsigned int a7) {
        auto pos = a3->toBlockPos();
        if (!Settings::DispenserCrops)
            return false;
        else if (a5->getItem()->isSeed()) {
            if (a2->getBlock(pos.add(0, -1, 0)).getTypeName() == VanillaBlocks::mFarmland->getTypeName() &&
                a2->getBlock(pos).getTypeName() == "minecraft:air") {
                auto out = dAccess<Block*, 8>(dAccess<SeedItemComponentLegacy*, 488>(a5->getItem()));//IDA Item::_useOn
                Level::setBlock(pos, a2->getDimensionId(), out);
                a5->remove(1);
                return true;
            }
        }
        else if (Settings::CanDispenserItemList.count(a5->getTypeName()))
        {
            //Level::broadcastText(std::to_string(a5->getBlock()->mayPlaceOn(*a2, pos.add(0, -1, 0))), TextType::RAW);
            if (a5->getBlock()->mayPlaceOn(*a2, pos.add(0, -1, 0)) &&
                a2->getBlock(pos).getTypeName() == "minecraft:air")
            {
                Block* sapbl = const_cast<Block*>(a5->getBlock());
                Level::setBlock(pos, a2->getDimensionId(), sapbl);
                a5->remove(1);
                return true;
            }
        }
        return false;
	}
}