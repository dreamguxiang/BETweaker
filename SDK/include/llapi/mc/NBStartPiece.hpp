// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "NBBridgeCrossing.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class NBStartPiece : public NBBridgeCrossing {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_NBSTARTPIECE
public:
    class NBStartPiece& operator=(class NBStartPiece const &) = delete;
    NBStartPiece(class NBStartPiece const &) = delete;
    NBStartPiece() = delete;
#endif

public:
    /*0*/ virtual ~NBStartPiece();
    /*2*/ virtual enum StructurePieceType getType() const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_NBSTARTPIECE
#endif
    MCAPI NBStartPiece(class Random &, int, int);

};