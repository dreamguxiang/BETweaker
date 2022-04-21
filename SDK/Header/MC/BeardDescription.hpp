// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class BeardDescription {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BEARDDESCRIPTION
public:
    class BeardDescription& operator=(class BeardDescription const &) = delete;
    BeardDescription(class BeardDescription const &) = delete;
    BeardDescription() = delete;
#endif

public:
    MCAPI BeardDescription(class BeardingDescriptionCache, struct BeardKernel const &);
    MCAPI float calculateContribution(class BlockPos const &) const;

protected:

private:

};