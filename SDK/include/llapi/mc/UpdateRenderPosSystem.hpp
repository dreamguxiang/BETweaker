// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class UpdateRenderPosSystem {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_UPDATERENDERPOSSYSTEM
public:
    class UpdateRenderPosSystem& operator=(class UpdateRenderPosSystem const &) = delete;
    UpdateRenderPosSystem(class UpdateRenderPosSystem const &) = delete;
    UpdateRenderPosSystem() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_UPDATERENDERPOSSYSTEM
#endif
    MCAPI static struct TickingSystemWithInfo createSystem();

//private:
    MCAPI static void _doUpdateRenderPosSystem(class StrictEntityContext const &, struct StateVectorComponent const &, struct RenderPositionComponent &);

private:

};