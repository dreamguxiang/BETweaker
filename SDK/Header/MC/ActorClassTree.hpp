// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ActorClassTree {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ACTORCLASSTREE
public:
    class ActorClassTree& operator=(class ActorClassTree const &) = delete;
    ActorClassTree(class ActorClassTree const &) = delete;
    ActorClassTree() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ACTORCLASSTREE
#endif
    MCAPI static enum ActorType getEntityTypeIdLegacy(enum ActorType);
    MCAPI static bool hasCategory(enum ActorCategory const &, enum ActorCategory);
    MCAPI static bool isHangingEntity(class Actor const &);
    MCAPI static bool isInstanceOf(class Actor const &, enum ActorType);
    MCAPI static bool isMob(enum ActorType);
    MCAPI static bool isMobLegacy(enum ActorType);
    MCAPI static bool isOfType(enum ActorType, enum ActorType);
    MCAPI static bool isTypeInstanceOf(enum ActorType, enum ActorType);

};