// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class InsideWaterlilyBlockSystem {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_INSIDEWATERLILYBLOCKSYSTEM
public:
    class InsideWaterlilyBlockSystem& operator=(class InsideWaterlilyBlockSystem const &) = delete;
    InsideWaterlilyBlockSystem(class InsideWaterlilyBlockSystem const &) = delete;
    InsideWaterlilyBlockSystem() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_INSIDEWATERLILYBLOCKSYSTEM
#endif
    MCAPI static struct TickingSystemWithInfo createDestroyWaterlilySystem();
    MCAPI static struct TickingSystemWithInfo createMovementSystem();

};