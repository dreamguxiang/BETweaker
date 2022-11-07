// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ShareItemsGoal {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SHAREITEMSGOAL
public:
    class ShareItemsGoal& operator=(class ShareItemsGoal const &) = delete;
    ShareItemsGoal(class ShareItemsGoal const &) = delete;
    ShareItemsGoal() = delete;
#endif

public:
    /*0*/ virtual ~ShareItemsGoal();
    /*1*/ virtual bool canUse();
    /*2*/ virtual bool canContinueToUse();
    /*3*/ virtual void __unk_vfn_3();
    /*4*/ virtual void start();
    /*5*/ virtual void stop();
    /*6*/ virtual void tick();
    /*7*/ virtual void appendDebugInfo(std::string &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SHAREITEMSGOAL
#endif
    MCAPI ShareItemsGoal(class Mob &, std::vector<struct MobDescriptor> const &, float, int, float);

//protected:
    MCAPI struct std::pair<int, class ItemStack> selectEntityToShareWith(std::vector<struct std::pair<int, class ItemStack>> const &);

protected:

};