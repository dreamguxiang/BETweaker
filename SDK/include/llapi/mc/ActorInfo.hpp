// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct ActorInfo {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ACTORINFO
public:
    ActorInfo() = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ACTORINFO
#endif
    MCAPI ActorInfo(struct ActorInfo const &);
    MCAPI void load(class CompoundTag const *);
    MCAPI struct ActorInfo & operator=(struct ActorInfo const &);
    MCAPI std::unique_ptr<class CompoundTag> save() const;
    MCAPI ~ActorInfo();

};