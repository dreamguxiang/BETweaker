// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Feature.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class WaterlilyFeature : public Feature {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_WATERLILYFEATURE
public:
    class WaterlilyFeature& operator=(class WaterlilyFeature const &) = delete;
    WaterlilyFeature(class WaterlilyFeature const &) = delete;
    WaterlilyFeature() = delete;
#endif

public:
    /*0*/ virtual ~WaterlilyFeature();
    /*3*/ virtual bool place(class BlockSource &, class BlockPos const &, class Random &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_WATERLILYFEATURE
#endif

};