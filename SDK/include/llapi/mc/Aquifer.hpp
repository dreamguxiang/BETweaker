/**
 * @file  Aquifer.hpp
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
 * @brief MC class Aquifer.
 *
 */
class Aquifer {

#define AFTER_EXTRA
// Add Member There
public:
struct FluidSample {
    FluidSample() = delete;
    FluidSample(FluidSample const&) = delete;
    FluidSample(FluidSample const&&) = delete;
};

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_AQUIFER
public:
    class Aquifer& operator=(class Aquifer const &) = delete;
    Aquifer(class Aquifer const &) = delete;
    Aquifer() = delete;
#endif

public:
    /**
     * @symbol ??0Aquifer@@QEAA@AEBVChunkPos@@AEBVAquiferNoises@@AEBUOverworldNoises3d@@AEBVSurfaceLevelCache@@HHH@Z
     * @hash   -210342240
     */
    MCAPI Aquifer(class ChunkPos const &, class AquiferNoises const &, struct OverworldNoises3d const &, class SurfaceLevelCache const &, int, int, int);
    /**
     * @symbol ?computeAt@Aquifer@@QEAAXAEBVBlockPos@@@Z
     * @hash   425830010
     */
    MCAPI void computeAt(class BlockPos const &);
    /**
     * @symbol ?getLastBarrier@Aquifer@@QEBAMXZ
     * @hash   324405722
     */
    MCAPI float getLastBarrier() const;
    /**
     * @symbol ?getLastFluidBlockType@Aquifer@@QEBAPEBVBlock@@_N@Z
     * @hash   -1944547856
     */
    MCAPI class Block const * getLastFluidBlockType(bool) const;
    /**
     * @symbol ?getLastFluidLevel@Aquifer@@QEBAHXZ
     * @hash   2028526116
     */
    MCAPI int getLastFluidLevel() const;
    /**
     * @symbol ?shouldScheduleFluidUpdate@Aquifer@@QEBA_NXZ
     * @hash   1536022496
     */
    MCAPI bool shouldScheduleFluidUpdate() const;

//private:
    /**
     * @symbol ?_computeAquifer@Aquifer@@AEBA?AUFluidSample@1@AEBVBlockPos@@@Z
     * @hash   1055780156
     */
    MCAPI struct Aquifer::FluidSample _computeAquifer(class BlockPos const &) const;

private:
    /**
     * @symbol ?chunkOffset@Aquifer@@0V?$array@U?$pair@HH@std@@$0N@@std@@B
     * @hash   934034731
     */
    MCAPI static class std::array<struct std::pair<int, int>, 13> const chunkOffset;

};