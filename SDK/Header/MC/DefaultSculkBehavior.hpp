// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class DefaultSculkBehavior {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_DEFAULTSCULKBEHAVIOR
public:
    class DefaultSculkBehavior& operator=(class DefaultSculkBehavior const &) = delete;
    DefaultSculkBehavior(class DefaultSculkBehavior const &) = delete;
    DefaultSculkBehavior() = delete;
#endif

public:
    /*0*/ virtual int updateDecayDelay(int) const;
    /*1*/ virtual int updateFacingData(int, class Block const &) const;
    /*2*/ virtual bool canChangeBlockOnSpread() const;
    /*3*/ virtual bool attemptSpreadVeins(class IBlockWorldGenAPI &, class BlockPos const &, class Block const &, int, class SculkSpreader &) const;
    /*4*/ virtual int attemptUseCharge(class IBlockWorldGenAPI &, class BlockSource *, class BlockPos const &, class BlockPos const &, int, int, class Random &, class SculkSpreader &, bool) const;
    /*5*/ virtual void onDischarged(class IBlockWorldGenAPI &, class BlockSource *, class BlockPos const &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_DEFAULTSCULKBEHAVIOR
#endif

};