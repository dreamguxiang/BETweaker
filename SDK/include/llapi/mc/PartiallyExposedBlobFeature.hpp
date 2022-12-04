/**
 * @file  PartiallyExposedBlobFeature.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class PartiallyExposedBlobFeature.
 *
 */
class PartiallyExposedBlobFeature {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PARTIALLYEXPOSEDBLOBFEATURE
public:
    class PartiallyExposedBlobFeature& operator=(class PartiallyExposedBlobFeature const &) = delete;
    PartiallyExposedBlobFeature(class PartiallyExposedBlobFeature const &) = delete;
    PartiallyExposedBlobFeature() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   1431427221
     */
    virtual ~PartiallyExposedBlobFeature();
    /**
     * @vftbl  1
     * @symbol ?place@PartiallyExposedBlobFeature@@UEBA?AV?$optional@VBlockPos@@@std@@AEAVIBlockWorldGenAPI@@AEBVBlockPos@@AEAVRandom@@AEAVRenderParams@@@Z
     * @hash   -1285109210
     */
    virtual class std::optional<class BlockPos> place(class IBlockWorldGenAPI &, class BlockPos const &, class Random &, class RenderParams &) const;

//private:
    /**
     * @symbol ?isWaterOrAir@PartiallyExposedBlobFeature@@CA_NAEBVIBlockWorldGenAPI@@AEBVBlockPos@@@Z
     * @hash   -746958066
     */
    MCAPI static bool isWaterOrAir(class IBlockWorldGenAPI const &, class BlockPos const &);

private:

};