/**
 * @file  SnapToSurfaceFeature.hpp
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
 * @brief MC class SnapToSurfaceFeature.
 *
 */
class SnapToSurfaceFeature {

#define AFTER_EXTRA
// Add Member There
public:
enum class Surface;

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SNAPTOSURFACEFEATURE
public:
    class SnapToSurfaceFeature& operator=(class SnapToSurfaceFeature const &) = delete;
    SnapToSurfaceFeature(class SnapToSurfaceFeature const &) = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   -362468840
     */
    virtual ~SnapToSurfaceFeature();
    /**
     * @vftbl  1
     * @symbol ?place@SnapToSurfaceFeature@@UEBA?AV?$optional@VBlockPos@@@std@@AEAVIBlockWorldGenAPI@@AEBVBlockPos@@AEAVRandom@@AEAVRenderParams@@@Z
     * @hash   -179184961
     */
    virtual class std::optional<class BlockPos> place(class IBlockWorldGenAPI &, class BlockPos const &, class Random &, class RenderParams &) const;
    /**
     * @symbol ??0SnapToSurfaceFeature@@QEAA@XZ
     * @hash   -571127894
     */
    MCAPI SnapToSurfaceFeature();

//private:
    /**
     * @symbol ?_findSnapPos@SnapToSurfaceFeature@@AEBA?AV?$optional@VBlockPos@@@std@@AEAVIBlockWorldGenAPI@@AEBVBlockPos@@W4Surface@1@@Z
     * @hash   913827145
     */
    MCAPI class std::optional<class BlockPos> _findSnapPos(class IBlockWorldGenAPI &, class BlockPos const &, enum class SnapToSurfaceFeature::Surface) const;

private:

};