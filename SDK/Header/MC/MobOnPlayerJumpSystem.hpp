// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class MobOnPlayerJumpSystem {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MOBONPLAYERJUMPSYSTEM
public:
    class MobOnPlayerJumpSystem& operator=(class MobOnPlayerJumpSystem const &) = delete;
    MobOnPlayerJumpSystem(class MobOnPlayerJumpSystem const &) = delete;
    MobOnPlayerJumpSystem() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_MOBONPLAYERJUMPSYSTEM
#endif
    MCAPI static float getPlayerJumpPendingScale(int);

};