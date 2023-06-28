#include <global.h>

namespace DoubleDoors {
    bool isUpperBlock(Block* bl) {
        return bl->getNbt()->getCompound("states")->getBoolean("upper_block_bit");
    }

    bool hasHinge(Block* bl) {
        return bl->getNbt()->getCompound("states")->getBoolean("door_hinge_bit");
    }

    bool isIronDoor(Block* bl) {
        return bl->getTypeName() == "minecraft:iron_door";
    }

    bool isDoorBlock(Block* bl) {
        return bl->isDoorBlock();
    }

    bool toggleDoor(DoorBlock* a1, BlockSource* bs, const BlockPos& pos, Player* pl) {
        auto tog = a1->isToggled(*(IConstBlockSource*)bs, pos);
        a1->setToggled(*bs, pos, pl, !tog);
        return true;
    }

    bool doubleDoors(DoorBlock* a1, Player* pl, BlockPos* a3, UCHAR a4) {
        auto bs = pl->getBlockSource();
        auto bl = Level::getBlock(a3, bs);

        while (!isUpperBlock(bl)) {
            *a3 = a3->add(0, 1, 0);
            bl = Level::getBlock(a3, bs);
            if (!isDoorBlock(bl))
                return true;
        }

        auto hinge = hasHinge(bl);

        for (size_t i = 2; i < 6; i++) {
            BlockPos pos = a3->neighbor(i);
            auto bl1 = Level::getBlock(pos, bs);
            if (isDoorBlock(bl1)) {
                if (hasHinge(bl1) != hinge && !isIronDoor(bl1)) {
                    return toggleDoor(a1, bs, pos, pl);
                }
            }
        }
        return false;
    }
}

LL_AUTO_TYPED_INSTANCE_HOOK(
    DoubleDoorsHook,
    DoorBlock,
    HookPriority::High,
    "?use@DoorBlock@@UEBA_NAEAVPlayer@@AEBVBlockPos@@E@Z",
    bool,
    Player* pl, BlockPos* a3, UCHAR a4)
{
    if (settings::DoubleDoors && this->getTypeName() != StaticVanillaBlocks::mIronDoor->getName().getString()) {
        try {
            DoubleDoors::doubleDoors(this, pl, a3, a4);
        }
        catch (...) {
            return origin(pl, a3, a4);
        }
    }
    return origin(pl, a3, a4);
}