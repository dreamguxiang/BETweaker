// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class NameableComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_NAMEABLECOMPONENT
public:
    class NameableComponent& operator=(class NameableComponent const &) = delete;
    NameableComponent(class NameableComponent const &) = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_NAMEABLECOMPONENT
#endif
    MCAPI NameableComponent();
    MCAPI bool getInteraction(class Actor &, class Player &, class ActorInteraction &);
    MCAPI void nameEntity(class Actor &, std::string const &);

};