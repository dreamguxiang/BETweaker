// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class Randomize {

#define AFTER_EXTRA
// Add Member There
public:
    char size[16];
#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_RANDOMIZE
public:
    class Randomize& operator=(class Randomize const&) = default;
    Randomize(class Randomize const&) = default;
    Randomize() = default;
#endif

public:
    MCAPI Randomize(class Random&);
    MCAPI bool chance(int, int) const;
    MCAPI bool chanceAllButOneIn(int) const;
    MCAPI bool chanceFloatGreaterThan(float) const;
    MCAPI bool chanceFloatLessThan(float) const;
    MCAPI bool chanceOneIn(int) const;
    MCAPI float nextFloat() const;
    MCAPI int nextIntInclusive(int, int) const;
    MCAPI ~Randomize();
    MCAPI static float const ChanceFloatGreaterThan_MinExcessiveImprobability;

protected:

private:

};