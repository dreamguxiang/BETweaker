// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "MoveControl.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class DolphinMoveControl : public MoveControl {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_DOLPHINMOVECONTROL
public:
    class DolphinMoveControl& operator=(class DolphinMoveControl const &) = delete;
    DolphinMoveControl(class DolphinMoveControl const &) = delete;
#endif

public:
    /*0*/ virtual ~DolphinMoveControl();
    /*2*/ virtual void tick(class MoveControlComponent &, class Mob &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_DOLPHINMOVECONTROL
#endif
    MCAPI DolphinMoveControl();

//private:
    MCAPI float _calcRotX(float, float, float);
    MCAPI float _calcRotY(float, float);
    MCAPI bool _clearOfObstacles(class Mob const &, float, float, int) const;
    MCAPI bool _isInWater(class Mob const &) const;
    MCAPI void _setupBreach(class Mob &);

private:

};