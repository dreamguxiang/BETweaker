// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class DesiredMoveDirectionSystem {

#define AFTER_EXTRA

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_DESIREDMOVEDIRECTIONSYSTEM
public:
    class DesiredMoveDirectionSystem& operator=(class DesiredMoveDirectionSystem const &) = delete;
    DesiredMoveDirectionSystem(class DesiredMoveDirectionSystem const &) = delete;
    DesiredMoveDirectionSystem() = delete;
#endif


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_DESIREDMOVEDIRECTIONSYSTEM
#endif
    MCAPI static void rotateTowardsControllingPassenger(bool, class Vec2 &, class Vec2 &, float &, float &, class Vec2 const &);
    MCAPI static void updateLocalMoveVelocity(float &, float &, float &, float, float, float);



};