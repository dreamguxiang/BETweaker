// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class StructurePoolBlockPredicateTrueIfFound {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_STRUCTUREPOOLBLOCKPREDICATETRUEIFFOUND
public:
    class StructurePoolBlockPredicateTrueIfFound& operator=(class StructurePoolBlockPredicateTrueIfFound const &) = delete;
    StructurePoolBlockPredicateTrueIfFound(class StructurePoolBlockPredicateTrueIfFound const &) = delete;
    StructurePoolBlockPredicateTrueIfFound() = delete;
#endif

public:
    /*0*/ virtual ~StructurePoolBlockPredicateTrueIfFound();
    /*1*/ virtual bool test(class Block const &, class Randomize &) const;
    /*2*/ virtual bool test(class BlockPos const &, class BlockPos const &, class Randomize &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_STRUCTUREPOOLBLOCKPREDICATETRUEIFFOUND
#endif
    MCAPI StructurePoolBlockPredicateTrueIfFound(class std::set<class Block const *, struct std::less<class Block const *>, class std::allocator<class Block const *>> const &, float);

};