// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class EndPortalShape {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ENDPORTALSHAPE
public:
    class EndPortalShape& operator=(class EndPortalShape const &) = delete;
    EndPortalShape(class EndPortalShape const &) = delete;
    EndPortalShape() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ENDPORTALSHAPE
#endif
    MCAPI EndPortalShape(class BlockSource &, class BlockPos);
    MCAPI class BlockPos getOrigin() const;
    MCAPI bool isValid(class BlockSource &);
    MCAPI ~EndPortalShape();

};