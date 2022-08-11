// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ActorDefinitionEventSubcomponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ACTORDEFINITIONEVENTSUBCOMPONENT
public:
    class ActorDefinitionEventSubcomponent& operator=(class ActorDefinitionEventSubcomponent const &) = delete;
    ActorDefinitionEventSubcomponent(class ActorDefinitionEventSubcomponent const &) = delete;
#endif

public:
    /*0*/ virtual ~ActorDefinitionEventSubcomponent();
    /*1*/ virtual void readfromJSON(class Json::Value &, class SemVersion const &);
    /*2*/ virtual void writetoJSON(class Json::Value &) const;
    /*3*/ virtual void doOnHitEffect(class Actor &, class ProjectileComponent &);
    /*4*/ virtual char const * getName();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ACTORDEFINITIONEVENTSUBCOMPONENT
#endif
    MCAPI ActorDefinitionEventSubcomponent();

};