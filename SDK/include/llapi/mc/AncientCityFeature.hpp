// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "StructureFeature.hpp"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class AncientCityFeature : public StructureFeature {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ANCIENTCITYFEATURE
public:
    class AncientCityFeature& operator=(class AncientCityFeature const &) = delete;
    AncientCityFeature(class AncientCityFeature const &) = delete;
    AncientCityFeature() = delete;
#endif

public:
    /*0*/ virtual ~AncientCityFeature();
    /*3*/ virtual bool getNearestGeneratedFeature(class Dimension &, class BiomeSource const &, class BlockPos const &, class BlockPos &, class IPreliminarySurfaceProvider const &, bool);
    /*5*/ virtual bool isFeatureChunk(class BiomeSource const &, class Random &, class ChunkPos const &, unsigned int, class IPreliminarySurfaceProvider const &, class Dimension const &);
    /*6*/ virtual std::unique_ptr<class StructureStart> createStructureStart(class Dimension &, class BiomeSource const &, class Random &, class ChunkPos const &, class IPreliminarySurfaceProvider const &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ANCIENTCITYFEATURE
#endif
    MCAPI AncientCityFeature(unsigned int, class BaseGameVersion const &);

};