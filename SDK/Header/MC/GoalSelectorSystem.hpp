// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class GoalSelectorSystem {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_GOALSELECTORSYSTEM
public:
    class GoalSelectorSystem& operator=(class GoalSelectorSystem const &) = delete;
    GoalSelectorSystem(class GoalSelectorSystem const &) = delete;
    GoalSelectorSystem() = delete;
#endif

public:
    /*0*/ virtual ~GoalSelectorSystem();
    /*1*/ virtual void __unk_vfn_1();
    /*2*/ virtual void tick(class EntityRegistry &);

protected:

private:
    MCAPI static void _tickGoalSelectorComponent(class ViewedEntityContextT<class EntityContext, class FlagComponent<struct ActorTickedFlag>, class FlagComponent<struct ActorFlag>, class GoalSelectorComponent> &);

};