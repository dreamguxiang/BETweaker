// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class BlockIntersectionConstraint {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLOCKINTERSECTIONCONSTRAINT
public:
    class BlockIntersectionConstraint& operator=(class BlockIntersectionConstraint const &) = delete;
    BlockIntersectionConstraint(class BlockIntersectionConstraint const &) = delete;
    BlockIntersectionConstraint() = delete;
#endif

public:
    /*0*/ virtual ~BlockIntersectionConstraint();
    /*1*/ virtual bool isSatisfied(class IBlockWorldGenAPI const &, class BlockPos const &, enum Rotation const &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_BLOCKINTERSECTIONCONSTRAINT
#endif
    MCAPI BlockIntersectionConstraint(class StructureTemplate &);

};