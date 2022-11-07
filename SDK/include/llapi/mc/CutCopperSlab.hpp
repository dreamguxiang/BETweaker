// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "SlabBlock.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class CutCopperSlab : public SlabBlock {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CUTCOPPERSLAB
public:
    class CutCopperSlab& operator=(class CutCopperSlab const &) = delete;
    CutCopperSlab(class CutCopperSlab const &) = delete;
    CutCopperSlab() = delete;
#endif

public:
    /*0*/ virtual ~CutCopperSlab();
    /*16*/ virtual void onLightningHit(class BlockSource &, class BlockPos const &) const;
    /*19*/ virtual void __unk_vfn_19();
    /*28*/ virtual class CopperBehavior const * tryGetCopperBehavior() const;
    /*29*/ virtual void __unk_vfn_29();
    /*30*/ virtual void __unk_vfn_30();
    /*32*/ virtual void __unk_vfn_32();
    /*33*/ virtual void __unk_vfn_33();
    /*34*/ virtual void __unk_vfn_34();
    /*36*/ virtual void __unk_vfn_36();
    /*37*/ virtual void __unk_vfn_37();
    /*38*/ virtual void __unk_vfn_38();
    /*39*/ virtual void __unk_vfn_39();
    /*40*/ virtual void __unk_vfn_40();
    /*41*/ virtual void __unk_vfn_41();
    /*42*/ virtual void __unk_vfn_42();
    /*44*/ virtual void __unk_vfn_44();
    /*45*/ virtual void __unk_vfn_45();
    /*46*/ virtual void __unk_vfn_46();
    /*47*/ virtual void __unk_vfn_47();
    /*48*/ virtual void __unk_vfn_48();
    /*49*/ virtual void __unk_vfn_49();
    /*54*/ virtual void __unk_vfn_54();
    /*60*/ virtual void __unk_vfn_60();
    /*61*/ virtual void __unk_vfn_61();
    /*75*/ virtual void __unk_vfn_75();
    /*82*/ virtual void __unk_vfn_82();
    /*105*/ virtual void __unk_vfn_105();
    /*123*/ virtual void __unk_vfn_123();
    /*125*/ virtual void __unk_vfn_125();
    /*126*/ virtual void __unk_vfn_126();
    /*131*/ virtual void __unk_vfn_131();
    /*156*/ virtual void __unk_vfn_156();
    /*167*/ virtual void __unk_vfn_167();
    /*168*/ virtual void __unk_vfn_168();
    /*169*/ virtual void __unk_vfn_169();
    /*174*/ virtual void randomTick(class BlockSource &, class BlockPos const &, class Random &) const;
    /*176*/ virtual void __unk_vfn_176();
    /*178*/ virtual bool use(class Player &, class BlockPos const &, unsigned char) const;
    /*187*/ virtual void __unk_vfn_187();
    /*193*/ virtual void __unk_vfn_193();
    /*194*/ virtual void __unk_vfn_194();
    /*195*/ virtual void __unk_vfn_195();
    /*196*/ virtual void __unk_vfn_196();
    /*197*/ virtual void __unk_vfn_197();
    /*198*/ MCAPI std::string const & getDescriptionId() const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CUTCOPPERSLAB
#endif
    MCAPI CutCopperSlab(std::string const &, int, bool, class HashedString const &, enum CopperType, class HashedString const &);
    MCAPI CutCopperSlab(std::string const &, int, bool, class HashedString const &, enum CopperType, class HashedString const &, class HashedString const &, class HashedString const &);

};