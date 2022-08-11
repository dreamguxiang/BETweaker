// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class RollGoal {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ROLLGOAL
public:
    class RollGoal& operator=(class RollGoal const &) = delete;
    RollGoal(class RollGoal const &) = delete;
    RollGoal() = delete;
#endif

public:
    /*0*/ virtual ~RollGoal();
    /*1*/ virtual bool canUse();
    /*2*/ virtual bool canContinueToUse();
    /*3*/ virtual bool canBeInterrupted();
    /*4*/ virtual void start();
    /*5*/ virtual void stop();
    /*6*/ virtual void tick();
    /*7*/ virtual void appendDebugInfo(std::string &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ROLLGOAL
#endif
    MCAPI RollGoal(class Mob &, float);

//private:
    MCAPI void _handleRoll(int, class Vec3 &, float &, float &) const;

private:

};