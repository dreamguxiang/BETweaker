// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class NormalTickFilterSystem {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_NORMALTICKFILTERSYSTEM
public:
    class NormalTickFilterSystem& operator=(class NormalTickFilterSystem const &) = delete;
    NormalTickFilterSystem(class NormalTickFilterSystem const &) = delete;
    NormalTickFilterSystem() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_NORMALTICKFILTERSYSTEM
#endif
    MCAPI static struct TickingSystemWithInfo createGenericSystem();

};