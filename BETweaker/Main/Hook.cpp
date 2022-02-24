#include "../pch.h"
#include "Moudle.h"
#include "setting.h"


THook(void, "?updateSleepingPlayerList@ServerLevel@@UEAAXXZ", ServerLevel* self) {
    original(self);
    if(Settings::FastSleeping) 
        FastSleep();
}

THook(void, "?transformOnFall@FarmBlock@@UEBAXAEAVBlockSource@@AEBVBlockPos@@PEAVActor@@M@Z", void* __this, void* a2,
    void* a3, void* a4, float a5) {
    if (Settings::NoFarmDestroy) {
        return;
    }
    return original(__this, a2, a3, a4, a5);
}

#include <MC/DispenserBlock.hpp>
#include <MC/SeedItemComponentLegacy.hpp>
THook(void, "?ejectItem@DispenserBlock@@IEBAXAEAVBlockSource@@AEBVVec3@@EAEBVItemStack@@AEAVContainer@@H@Z", DispenserBlock* a1,
     BlockSource* a2, Vec3* a3, FaceID a4,ItemStack* a5, Container* a6,unsigned int a7) {
    auto pos = a3->toBlockPos();
    if (a5->getItem()->isSeed()) {
        if (a2->getBlock(pos.add(0, -1, 0)).getTypeName() == VanillaBlocks::mFarmland->getTypeName() &&
            a2->getBlock(pos).getTypeName() == "minecraft:air") {
            auto out = dAccess<Block*, 8>(dAccess<SeedItemComponentLegacy*, 488>(a5->getItem()));
            Level::setBlock(pos, a2->getDimensionId(), out);
            a5->remove(1);
            return ;
        }
    }
    return original(a1, a2, a3, a4, a5, a6, a7);
}