// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

struct ClipParameters {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CLIPPARAMETERS
public:
    struct ClipParameters& operator=(struct ClipParameters const &) = delete;
    ClipParameters(struct ClipParameters const &) = delete;
    ClipParameters() = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CLIPPARAMETERS
#endif
    MCAPI ClipParameters(class Vec3 const &, class Vec3 const &, class std::function<bool (class BlockSource const &, class Block const &, bool)> const &);
    MCAPI ~ClipParameters();

};