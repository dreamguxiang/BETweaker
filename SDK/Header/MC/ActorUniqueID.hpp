// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct ActorUniqueID {

#define AFTER_EXTRA
// Add Member There

    long long id;
    ActorUniqueID()
    {
        id = -1;
    }

    ActorUniqueID(long long i)
    {
        id = i;
    }

    inline long long get() const
    {
        return id;
    }

    inline operator long long() const
    {
        return id;
    }
#define DISABLE_CONSTRUCTOR_PREVENTION_ACTORUNIQUEID
#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ACTORUNIQUEID
public:
    struct ActorUniqueID& operator=(struct ActorUniqueID const &) = delete;
    ActorUniqueID(struct ActorUniqueID const &) = delete;
    ActorUniqueID() = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ACTORUNIQUEID
#endif
    MCAPI static struct ActorUniqueID const INVALID_ID;

};