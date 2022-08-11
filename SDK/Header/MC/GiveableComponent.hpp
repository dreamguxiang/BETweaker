// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class GiveableComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_GIVEABLECOMPONENT
public:
    class GiveableComponent& operator=(class GiveableComponent const &) = delete;
    GiveableComponent(class GiveableComponent const &) = delete;
    GiveableComponent() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_GIVEABLECOMPONENT
#endif
    MCAPI bool getInteraction(class Actor &, class Player &, class ActorInteraction &);
    MCAPI ~GiveableComponent();

};