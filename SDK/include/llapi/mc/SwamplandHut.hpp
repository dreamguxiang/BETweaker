// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "StructurePiece.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class SwamplandHut : public StructurePiece {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SWAMPLANDHUT
public:
    class SwamplandHut& operator=(class SwamplandHut const &) = delete;
    SwamplandHut(class SwamplandHut const &) = delete;
    SwamplandHut() = delete;
#endif

public:
    /*0*/ virtual ~SwamplandHut();
    /*2*/ virtual enum StructurePieceType getType() const;
    /*4*/ virtual bool postProcess(class BlockSource &, class Random &, class BoundingBox const &);
    /*5*/ virtual void postProcessMobsAt(class BlockSource &, class Random &, class BoundingBox const &);
    /*12*/ virtual void addHardcodedSpawnAreas(class LevelChunk &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SWAMPLANDHUT
#endif
    MCAPI SwamplandHut(short, int, int);

//protected:
    MCAPI void placeCauldron(class BlockSource &, class Random &, int, int, int, class BoundingBox const &);

protected:

};