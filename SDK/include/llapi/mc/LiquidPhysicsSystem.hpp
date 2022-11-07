// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class LiquidPhysicsSystem {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_LIQUIDPHYSICSSYSTEM
public:
    class LiquidPhysicsSystem& operator=(class LiquidPhysicsSystem const &) = delete;
    LiquidPhysicsSystem(class LiquidPhysicsSystem const &) = delete;
    LiquidPhysicsSystem() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_LIQUIDPHYSICSSYSTEM
#endif
    MCAPI static bool applyPhysics(enum MaterialType, class IConstBlockSource const &, class AABB const &, struct StateVectorComponent &);
    MCAPI static struct TickingSystemWithInfo createApplyFlowSystem();
    MCAPI static struct TickingSystemWithInfo createFilterSystem(bool);
    MCAPI static struct TickingSystemWithInfo createLiquidFetchingSystem();

};