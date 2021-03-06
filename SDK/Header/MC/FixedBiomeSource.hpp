// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class FixedBiomeSource {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_FIXEDBIOMESOURCE
public:
    class FixedBiomeSource& operator=(class FixedBiomeSource const &) = delete;
    FixedBiomeSource(class FixedBiomeSource const &) = delete;
    FixedBiomeSource() = delete;
#endif


public:
    /*0*/ virtual ~FixedBiomeSource();
    /*1*/ virtual void fillBiomes(class LevelChunk &, class ChunkLocalNoiseCache const &) const;
    /*2*/ virtual class BiomeArea getBiomeArea(class BoundingBox const &, unsigned int) const;
    /*3*/ virtual class BiomeArea getBiomeArea(class BoundingBox const &, unsigned int, struct GetBiomeOptions const &) const;
    /*4*/ virtual bool containsOnly(int, int, int, int, class gsl::span<int const, -1>) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_FIXEDBIOMESOURCE
    MCVAPI class Biome const * getBiome(int, int, int) const;
    MCVAPI class Biome const * getBiome(struct GetBiomeOptions const &) const;
    MCVAPI class Biome const * getBiome(class BlockPos const &) const;
#endif
    MCAPI FixedBiomeSource(class Biome const &);



};