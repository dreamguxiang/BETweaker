#include "../Global.h"
#include "Module.h"
#include "setting.h"

THook(void, "?updateSleepingPlayerList@ServerLevel@@UEAAXXZ", ServerLevel* self) {
    original(self);
    if(Settings::FastSleeping) 
        Module::FastSleep();
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
#include <MC/LogBlock.hpp>
THook(void, "?ejectItem@DispenserBlock@@IEBAXAEAVBlockSource@@AEBVVec3@@EAEBVItemStack@@AEAVContainer@@H@Z", DispenserBlock* a1,
     BlockSource* a2, Vec3* a3, FaceID a4,ItemStack* a5, Container* a6,unsigned int a7) {
    if(Module::DispenserItemFunc(a1, a2, a3, a4, a5, a6, a7))
        return ;
    return original(a1, a2, a3, a4, a5, a6, a7);
}

THook(void, "?onRemove@LeafBlock@@UEBAXAEAVBlockSource@@AEBVBlockPos@@@Z",
    LeafBlock* _this, BlockSource* a2, const BlockPos* a3) {
    if (Settings::FastLeafDecay)
        Module::FastLeafDecayFunc1(_this, a2, a3);
    return original(_this, a2, a3);
}

THook(void, "?onRemove@LogBlock@@UEBAXAEAVBlockSource@@AEBVBlockPos@@@Z",
    LogBlock* _this, BlockSource* a2, const BlockPos* a3) {
    if (Settings::FastLeafDecay)
        Module::FastLeafDecayFunc1((LeafBlock*)_this, a2, a3);
    return original(_this, a2, a3);
}


THook(void, "?tick@Level@@UEAAXXZ", Level* _this) {
    if (Settings::FastLeafDecay)
    {
        Module::FastLeafDecayFunc();
    }
    return original(_this);
}

TInstanceHook(void, "?_updateServer@FishingHook@@IEAAXXZ", FishingHook) {
    if (Settings::AutoFish)
    {
        Module::AutoFish(this);
    }
    return original(this);
}