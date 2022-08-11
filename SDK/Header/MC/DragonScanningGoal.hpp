// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class DragonScanningGoal {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_DRAGONSCANNINGGOAL
public:
    class DragonScanningGoal& operator=(class DragonScanningGoal const &) = delete;
    DragonScanningGoal(class DragonScanningGoal const &) = delete;
    DragonScanningGoal() = delete;
#endif

public:
    /*0*/ virtual ~DragonScanningGoal();
    /*1*/ virtual bool canUse();
    /*2*/ virtual bool canContinueToUse();
    /*3*/ virtual void __unk_vfn_3();
    /*4*/ virtual void start();
    /*5*/ virtual void stop();
    /*6*/ virtual void tick();
    /*7*/ virtual void appendDebugInfo(std::string &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_DRAGONSCANNINGGOAL
#endif
    MCAPI DragonScanningGoal(class EnderDragon &);

//private:

private:
    MCAPI static float SITTING_ATTACK_VIEW_RANGE;
    MCAPI static float SITTING_CHARGE_VIEW_RANGE;
    MCAPI static int SITTING_SCANNING_IDLE_TICKS;

};