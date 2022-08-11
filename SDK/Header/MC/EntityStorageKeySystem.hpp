// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class EntityStorageKeySystem {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ENTITYSTORAGEKEYSYSTEM
public:
    class EntityStorageKeySystem& operator=(class EntityStorageKeySystem const &) = delete;
    EntityStorageKeySystem(class EntityStorageKeySystem const &) = delete;
    EntityStorageKeySystem() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ENTITYSTORAGEKEYSYSTEM
#endif
    MCAPI static std::string generateStorageKey(__int64);
    MCAPI static bool getIsDirtySinceSerialization(class EntityContext &, std::string const &);
    MCAPI static void setDirtyFromNonSerializedState(class EntityContext &);
    MCAPI static void setLastSerializedState(class EntityContext &, std::string const &);

};