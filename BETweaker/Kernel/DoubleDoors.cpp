#include "../Global.h"

namespace Module {
	bool DoubleDoors(DoorBlock *a1, Player* pl, BlockPos* a3, UCHAR a4) {
        auto bs = pl->getBlockSource();
        auto bl = Level::getBlock(a3, bs);
        /*SymCall("??$getState@_N@Block@@QEBA_NAEBVItemState@@@Z", bool, Block*, ItemState*)(bl, (ItemState*) & VanillaStates::DoorHingeBit);*/
        auto isUpperBlock = bl->getNbt()->getCompound("states")->getBoolean("upper_block_bit");
        auto NowPos = a3;
    isUpperNow:
        if (!isUpperBlock)
        {
            *NowPos = (a3->add(0, 1, 0));
            bl = Level::getBlock(NowPos, bs);
            isUpperBlock = bl->getNbt()->getCompound("states")->getBoolean("upper_block_bit");
            if (!bl->isDoorBlock())
                return true;
            goto isUpperNow;
        }
        auto hasHinge = bl->getNbt()->getCompound("states")->getBoolean("door_hinge_bit");
        for (size_t i = 2; i < 6; i++)
        {
            BlockPos pos = (*NowPos).neighbor(i);
            auto bs = pl->getBlockSource();
            auto bl1 = Level::getBlock(pos, bs);
            //logger.info << pos.toString() << " " << bl1->getTypeName() << logger.endl;
            if (bl1->isDoorBlock())
            {
                if (bl1->getNbt()->getCompound("states")->getBoolean("door_hinge_bit") != hasHinge && bl1->getTypeName() != "minecraft:iron_door")
                {
                    auto tog = a1->isToggled(*(IConstBlockSource*)bs, *a3);
                    a1->setToggled(*bs, pos, pl,!tog);
                    return  true;
                }
            }
        }
	}
}