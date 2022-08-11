// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct DirtyTicksCounter {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_DIRTYTICKSCOUNTER
public:
    struct DirtyTicksCounter& operator=(struct DirtyTicksCounter const &) = delete;
    DirtyTicksCounter(struct DirtyTicksCounter const &) = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_DIRTYTICKSCOUNTER
#endif
    MCAPI DirtyTicksCounter();
    MCAPI int getTicksSinceLastChange() const;
    MCAPI int getTotalDirtyTicks() const;
    MCAPI struct DirtyTicksCounter & operator++();
    MCAPI void reset();
    MCAPI void touch();
    MCAPI static struct DirtyTicksCounter max();

};