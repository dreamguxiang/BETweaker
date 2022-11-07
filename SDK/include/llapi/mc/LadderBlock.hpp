// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "BlockLegacy.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class LadderBlock : public BlockLegacy {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_LADDERBLOCK
public:
    class LadderBlock& operator=(class LadderBlock const &) = delete;
    LadderBlock(class LadderBlock const &) = delete;
    LadderBlock() = delete;
#endif

public:
    /*0*/ virtual ~LadderBlock();
    /*10*/ virtual class AABB const & getAABB(class IConstBlockSource const &, class BlockPos const &, class Block const &, class AABB &, bool) const;
    /*14*/ virtual bool getLiquidClipVolume(class BlockSource &, class BlockPos const &, class AABB &) const;
    /*19*/ virtual void __unk_vfn_19();
    /*29*/ virtual void __unk_vfn_29();
    /*30*/ virtual void __unk_vfn_30();
    /*32*/ virtual void __unk_vfn_32();
    /*33*/ virtual void __unk_vfn_33();
    /*34*/ virtual void __unk_vfn_34();
    /*35*/ virtual bool isWaterBlocking() const;
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
    /*57*/ virtual class Block const & sanitizeFillBlock(class BlockSource &, class BlockPos const &, class Block const &) const;
    /*60*/ virtual void __unk_vfn_60();
    /*61*/ virtual void __unk_vfn_61();
    /*62*/ virtual bool canContainLiquid() const;
    /*75*/ virtual void __unk_vfn_75();
    /*82*/ virtual void __unk_vfn_82();
    /*91*/ virtual bool mayPlace(class BlockSource &, class BlockPos const &, unsigned char) const;
    /*100*/ virtual void neighborChanged(class BlockSource &, class BlockPos const &, class BlockPos const &) const;
    /*105*/ virtual void __unk_vfn_105();
    /*106*/ virtual class Block const & getPlacementBlock(class Actor &, class BlockPos const &, unsigned char, class Vec3 const &, int) const;
    /*123*/ virtual void __unk_vfn_123();
    /*125*/ virtual void __unk_vfn_125();
    /*126*/ virtual void __unk_vfn_126();
    /*131*/ virtual void __unk_vfn_131();
    /*143*/ virtual class AABB const & getVisualShape(class Block const &, class AABB &, bool) const;
    /*156*/ virtual void __unk_vfn_156();
    /*167*/ virtual void __unk_vfn_167();
    /*168*/ virtual void __unk_vfn_168();
    /*169*/ virtual void __unk_vfn_169();
    /*173*/ virtual void tick(class BlockSource &, class BlockPos const &, class Random &) const;
    /*176*/ virtual void __unk_vfn_176();
    /*179*/ virtual bool canSurvive(class BlockSource &, class BlockPos const &) const;
    /*187*/ virtual void __unk_vfn_187();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_LADDERBLOCK
    MCVAPI bool canBeSilkTouched() const;
    MCVAPI bool waterSpreadCausesSpawn() const;
#endif
    MCAPI LadderBlock(std::string const &, int);

};