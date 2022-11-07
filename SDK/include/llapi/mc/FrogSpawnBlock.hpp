// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "BlockLegacy.hpp"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class FrogSpawnBlock : public BlockLegacy {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_FROGSPAWNBLOCK
public:
    class FrogSpawnBlock& operator=(class FrogSpawnBlock const &) = delete;
    FrogSpawnBlock(class FrogSpawnBlock const &) = delete;
    FrogSpawnBlock() = delete;
#endif

public:
    /*0*/ virtual ~FrogSpawnBlock();
    /*10*/ virtual class AABB const & getAABB(class IConstBlockSource const &, class BlockPos const &, class Block const &, class AABB &, bool) const;
    /*19*/ virtual void __unk_vfn_19();
    /*22*/ virtual bool canProvideSupport(class Block const &, unsigned char, enum BlockSupportType) const;
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
    /*69*/ virtual bool checkIsPathable(class Actor &, class BlockPos const &, class BlockPos const &) const;
    /*75*/ virtual void __unk_vfn_75();
    /*82*/ virtual void __unk_vfn_82();
    /*93*/ virtual bool mayPlaceOn(class BlockSource &, class BlockPos const &) const;
    /*98*/ virtual bool playerWillDestroy(class Player &, class BlockPos const &, class Block const &) const;
    /*100*/ virtual void neighborChanged(class BlockSource &, class BlockPos const &, class BlockPos const &) const;
    /*105*/ virtual void __unk_vfn_105();
    /*113*/ virtual void entityInside(class BlockSource &, class BlockPos const &, class Actor &) const;
    /*123*/ virtual void __unk_vfn_123();
    /*125*/ virtual void __unk_vfn_125();
    /*126*/ virtual void __unk_vfn_126();
    /*131*/ virtual void __unk_vfn_131();
    /*133*/ virtual std::string buildDescriptionId(class Block const &) const;
    /*134*/ virtual bool isAuxValueRelevantForPicking() const;
    /*156*/ virtual void __unk_vfn_156();
    /*167*/ virtual void __unk_vfn_167();
    /*168*/ virtual void __unk_vfn_168();
    /*169*/ virtual void __unk_vfn_169();
    /*170*/ virtual void onPlace(class BlockSource &, class BlockPos const &) const;
    /*173*/ virtual void tick(class BlockSource &, class BlockPos const &, class Random &) const;
    /*176*/ virtual void __unk_vfn_176();
    /*179*/ virtual bool canSurvive(class BlockSource &, class BlockPos const &) const;
    /*187*/ virtual void __unk_vfn_187();
    /*188*/ virtual int getResourceCount(class Randomize &, class Block const &, int) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_FROGSPAWNBLOCK
    MCVAPI bool canBeSilkTouched() const;
#endif
    MCAPI FrogSpawnBlock(std::string const &, int);

};