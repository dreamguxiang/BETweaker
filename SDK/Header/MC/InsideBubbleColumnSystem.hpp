// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class InsideBubbleColumnSystem {

#define AFTER_EXTRA

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_INSIDEBUBBLECOLUMNSYSTEM
public:
    class InsideBubbleColumnSystem& operator=(class InsideBubbleColumnSystem const &) = delete;
    InsideBubbleColumnSystem(class InsideBubbleColumnSystem const &) = delete;
    InsideBubbleColumnSystem() = delete;
#endif


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_INSIDEBUBBLECOLUMNSYSTEM
#endif
    MCAPI static struct TickingSystemWithInfo createBoatInsideBubbleColumnSystem();
    MCAPI static struct TickingSystemWithInfo createBubbleColumnMovementSystem();
    MCAPI static struct TickingSystemWithInfo createSpawnBubbleColumnParticlesSystem();



};