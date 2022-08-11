// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class NoiseCellInterpolator {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_NOISECELLINTERPOLATOR
public:
    class NoiseCellInterpolator& operator=(class NoiseCellInterpolator const &) = delete;
    NoiseCellInterpolator(class NoiseCellInterpolator const &) = delete;
    NoiseCellInterpolator() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_NOISECELLINTERPOLATOR
#endif
    MCAPI NoiseCellInterpolator(class gsl::span<float const, -1>);
    MCAPI NoiseCellInterpolator(class gsl::span<float const, -1>, int, int);
    MCAPI float getLerpedValue() const;
    MCAPI void selectCellXZ(int, int, int, int);
    MCAPI void updateForX(unsigned char);
    MCAPI void updateForZ(unsigned char);

};