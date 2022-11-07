// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct SpawnActorParameters {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SPAWNACTORPARAMETERS
public:
    struct SpawnActorParameters& operator=(struct SpawnActorParameters const &) = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SPAWNACTORPARAMETERS
#endif
    MCAPI SpawnActorParameters();
    MCAPI SpawnActorParameters(struct SpawnActorParameters const &);
    MCAPI SpawnActorParameters(struct SpawnActorParameters &&);
    MCAPI void setItem(class ItemDescriptor const &);
    MCAPI void setSpawnEntity(std::string const &);
    MCAPI void setSpawnEvent(std::string const &);
    MCAPI void setSpawnSound(std::string const &);
    MCAPI void setSpawnTimeMax(int const &);
    MCAPI void setSpawnTimeMin(int const &);
    MCAPI bool spawnsItemStack() const;
    MCAPI ~SpawnActorParameters();

};