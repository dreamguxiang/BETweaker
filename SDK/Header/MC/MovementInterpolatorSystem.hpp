// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class MovementInterpolatorSystem {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MOVEMENTINTERPOLATORSYSTEM
public:
    class MovementInterpolatorSystem& operator=(class MovementInterpolatorSystem const &) = delete;
    MovementInterpolatorSystem(class MovementInterpolatorSystem const &) = delete;
    MovementInterpolatorSystem() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_MOVEMENTINTERPOLATORSYSTEM
#endif
    MCAPI static void onGroundPostTick(struct MovementInterpolatorComponent const &, struct StateVectorComponent &);
    MCAPI static void tick(class Actor &);

};