// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class LevelEventCoordinator {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_LEVELEVENTCOORDINATOR
public:
    class LevelEventCoordinator& operator=(class LevelEventCoordinator const &) = delete;
    LevelEventCoordinator(class LevelEventCoordinator const &) = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_LEVELEVENTCOORDINATOR
#endif
    MCAPI LevelEventCoordinator();
    MCAPI void registerLevelGameplayHandler(std::unique_ptr<class LevelGameplayHandler> &&);
    MCAPI void sendEvent(class EventRef<struct LevelGameplayEvent<void>> const &);
    MCAPI void sendLevelBiomesRegistered(class IWorldRegistriesProvider &);
    MCAPI void sendLevelInitialized(class Level &);
    MCAPI void sendLevelRemovedActor(class Level &, class Actor &);
    MCAPI void sendLevelScriptTick(class Level &);
    MCAPI void sendLevelTick(class Level &);
    MCAPI void sendLevelWeatherChanged(std::string const &, bool, bool);

};