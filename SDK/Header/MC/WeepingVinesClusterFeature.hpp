// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Feature.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class WeepingVinesClusterFeature : public Feature {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_WEEPINGVINESCLUSTERFEATURE
public:
    class WeepingVinesClusterFeature& operator=(class WeepingVinesClusterFeature const &) = delete;
    WeepingVinesClusterFeature(class WeepingVinesClusterFeature const &) = delete;
    WeepingVinesClusterFeature() = delete;
#endif

public:
    /*0*/ virtual ~WeepingVinesClusterFeature();
    /*3*/ virtual bool place(class BlockSource &, class BlockPos const &, class Random &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_WEEPINGVINESCLUSTERFEATURE
#endif

//private:
    MCAPI bool _isInvalidPlacementLocation(class BlockSource &, class BlockPos const &) const;
    MCAPI void _placeRoofNetherWart(class BlockSource &, class BlockPos const &, class Random &) const;
    MCAPI void _placeRoofWeepingVines(class BlockSource &, class BlockPos const &, class Random &) const;

private:

};