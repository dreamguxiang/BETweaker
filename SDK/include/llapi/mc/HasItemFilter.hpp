// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

struct HasItemFilter {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_HASITEMFILTER
public:
    struct HasItemFilter& operator=(struct HasItemFilter const &) = delete;
    HasItemFilter(struct HasItemFilter const &) = delete;
    HasItemFilter() = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_HASITEMFILTER
#endif
    MCAPI HasItemFilter(struct HasItemFilter &&);
    MCAPI ~HasItemFilter();

};