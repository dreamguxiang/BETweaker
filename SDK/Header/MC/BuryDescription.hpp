// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class BuryDescription {

#define AFTER_EXTRA

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BURYDESCRIPTION
public:
    class BuryDescription& operator=(class BuryDescription const &) = delete;
    BuryDescription(class BuryDescription const &) = delete;
    BuryDescription() = delete;
#endif


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_BURYDESCRIPTION
#endif
    MCAPI BuryDescription(class BoundingBox const &);
    MCAPI float calculateContribution(class BlockPos const &) const;



};