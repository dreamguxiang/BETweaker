// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class ResetPositionModeSystem {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_RESETPOSITIONMODESYSTEM
public:
    class ResetPositionModeSystem& operator=(class ResetPositionModeSystem const &) = delete;
    ResetPositionModeSystem(class ResetPositionModeSystem const &) = delete;
    ResetPositionModeSystem() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_RESETPOSITIONMODESYSTEM
#endif
    MCAPI static struct TickingSystemWithInfo createResetPositionModeSystem();

};