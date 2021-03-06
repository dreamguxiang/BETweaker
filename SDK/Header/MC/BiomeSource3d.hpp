// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class BiomeSource3d {

#define AFTER_EXTRA

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BIOMESOURCE3D
public:
    class BiomeSource3d& operator=(class BiomeSource3d const &) = delete;
    BiomeSource3d(class BiomeSource3d const &) = delete;
    BiomeSource3d() = delete;
#endif


public:
    /*0*/ virtual ~BiomeSource3d();
    /*1*/ virtual void fillBiomes(class LevelChunk &, class ChunkLocalNoiseCache const &) const;
    /*2*/ virtual class BiomeArea getBiomeArea(class BoundingBox const &, unsigned int) const;
    /*3*/ virtual class BiomeArea getBiomeArea(class BoundingBox const &, unsigned int, struct GetBiomeOptions const &) const;
    /*4*/ virtual bool containsOnly(int, int, int, int, class gsl::span<int const, -1>) const;
    /*5*/ virtual class Biome const * getBiome(class BlockPos const &) const;
    /*6*/ virtual class Biome const * getBiome(struct GetBiomeOptions const &) const;
    /*7*/ virtual class Biome const * getBiome(int, int, int) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_BIOMESOURCE3D
#endif



};