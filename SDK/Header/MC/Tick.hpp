// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct Tick {

#define AFTER_EXTRA
// Add Member There
unsigned long long t;
#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_TICK
public:
    struct Tick& operator=(struct Tick const &) = delete;
    Tick(struct Tick const &) = delete;
    Tick() = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_TICK
#endif
    MCAPI static struct Tick const MAX;

};