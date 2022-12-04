/**
 * @file  CoralHangFeature.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Feature.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class CoralHangFeature.
 *
 */
class CoralHangFeature : public Feature {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CORALHANGFEATURE
public:
    class CoralHangFeature& operator=(class CoralHangFeature const &) = delete;
    CoralHangFeature(class CoralHangFeature const &) = delete;
    CoralHangFeature() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   -1727494403
     */
    virtual ~CoralHangFeature();
    /**
     * @vftbl  3
     * @symbol ?place@CoralHangFeature@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@AEAVRandom@@@Z
     * @hash   1205437229
     */
    virtual bool place(class BlockSource &, class BlockPos const &, class Random &) const;

};