// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class StructureFeature {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_STRUCTUREFEATURE
public:
    class StructureFeature& operator=(class StructureFeature const &) = delete;
    StructureFeature(class StructureFeature const &) = delete;
    StructureFeature() = delete;
#endif

public:
    /*0*/ virtual ~StructureFeature();
    /*1*/ virtual bool shouldAddHardcodedSpawnAreas();
    /*2*/ virtual bool shouldPostProcessMobs();
    /*3*/ virtual bool getNearestGeneratedFeature(class Dimension &, class BiomeSource const &, class BlockPos const &, class BlockPos &, class IPreliminarySurfaceProvider const &, bool);
    /*4*/ virtual void initMobSpawnTypes(class HardcodedSpawnAreaRegistry &);
    /*5*/ virtual bool isFeatureChunk(class BiomeSource const &, class Random &, class ChunkPos const &, unsigned int, class IPreliminarySurfaceProvider const &, class Dimension const &);
    /*6*/ virtual std::unique_ptr<class StructureStart> createStructureStart(class Dimension &, class BiomeSource const &, class Random &, class ChunkPos const &, class IPreliminarySurfaceProvider const &);
    /*7*/ virtual class StructureStart * getStructureAt(int, int, int);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_STRUCTUREFEATURE
#endif
    MCAPI StructureFeature(unsigned int, enum StructureFeatureType);
    MCAPI void addHardcodedSpawnAreas(class LevelChunk &);
    MCAPI class BlockPos chunkStartAtSurfaceLevel(class IPreliminarySurfaceProvider const &, class ChunkPos, int);
    MCAPI void createBlueprints(class Dimension &, class ChunkPos const &, class BiomeSource const &, class IPreliminarySurfaceProvider const &);
    MCAPI void debugRender();
    MCAPI std::vector<class ChunkPos> findFarAwayStructures(class buffer_span<class ChunkPos>, unsigned int);
    MCAPI void foreachIntersectingStructureStart(class BoundingBox const &, class std::function<void (class StructureStart &)>);
    MCAPI void garbageCollectBlueprints(class buffer_span<class ChunkPos>, unsigned int);
    MCAPI enum StructureFeatureType getType() const;
    MCAPI bool isInsideBoundingFeature(int, int, int);
    MCAPI bool postProcess(class BlockSource &, class Random &, int, int);
    MCAPI void postProcessMobsAt(class BlockSource &, int, int, class Random &);
    MCAPI void waitForFeatureBlueprints();
    MCAPI static bool findNearestFeaturePositionBySpacing(class Dimension &, class IPreliminarySurfaceProvider const &, class StructureFeature &, class BiomeSource const &, class BlockPos const &, class BlockPos &, int, int, int, bool, int, bool);
    MCAPI static class ChunkPos getChunkPosInSpace(class ChunkPos const &, class Random &, unsigned int, int, int, int, bool);
    MCAPI static void setRandomSeedFor(class Random &, int, int, int, unsigned int);

//protected:
    MCAPI void addFeature(class Dimension &, class Random &, class ChunkPos const &, class BiomeSource const &, class IPreliminarySurfaceProvider const &);

protected:

};