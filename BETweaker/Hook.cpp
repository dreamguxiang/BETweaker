#include "pch.h"
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
