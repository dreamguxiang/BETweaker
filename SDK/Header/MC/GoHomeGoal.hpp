// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class GoHomeGoal {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_GOHOMEGOAL
public:
    class GoHomeGoal& operator=(class GoHomeGoal const &) = delete;
    GoHomeGoal(class GoHomeGoal const &) = delete;
    GoHomeGoal() = delete;
#endif

public:
    /*0*/ virtual ~GoHomeGoal();
    /*1*/ virtual bool canUse();
    /*2*/ virtual bool canContinueToUse();
    /*3*/ virtual void __unk_vfn_3();
    /*4*/ virtual void start();
    /*5*/ virtual void stop();
    /*6*/ virtual void tick();
    /*7*/ virtual void appendDebugInfo(std::string &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_GOHOMEGOAL
#endif
    MCAPI GoHomeGoal(class Mob &);

//private:
    MCAPI class AutomaticID<class Dimension, int> _getHomeDimension() const;
    MCAPI class BlockPos _getHomePos() const;
    MCAPI bool _hasRequiredComponents() const;
    MCAPI void _triggerOnFailedEvents();

private:

};