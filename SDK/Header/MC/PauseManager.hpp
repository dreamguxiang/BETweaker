// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PauseManager {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PAUSEMANAGER
public:
    class PauseManager& operator=(class PauseManager const &) = delete;
    PauseManager(class PauseManager const &) = delete;
    PauseManager() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_PAUSEMANAGER
#endif
    MCAPI static enum SimulationType const DEFAULT_SIMULATION_TYPE;
    MCAPI static enum SimulationType getSimulationType(class StackRefResultT<struct SharePtrRefTraits<class PauseManager const>>);

};