// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class LadderResetFallDamageSystem {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_LADDERRESETFALLDAMAGESYSTEM
public:
    class LadderResetFallDamageSystem& operator=(class LadderResetFallDamageSystem const &) = delete;
    LadderResetFallDamageSystem(class LadderResetFallDamageSystem const &) = delete;
    LadderResetFallDamageSystem() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_LADDERRESETFALLDAMAGESYSTEM
#endif
    MCAPI static struct TickingSystemWithInfo createLadderResetFallDamageSystem();

};