// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "BlockLegacy.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class LiquidBlock : public BlockLegacy {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_LIQUIDBLOCK
public:
    class LiquidBlock& operator=(class LiquidBlock const &) = delete;
    LiquidBlock(class LiquidBlock const &) = delete;
    LiquidBlock() = delete;
#endif

public:
    /*0*/ virtual ~LiquidBlock();
    /*10*/ virtual class AABB const & getAABB(class IConstBlockSource const &, class BlockPos const &, class Block const &, class AABB &, bool) const;
    /*19*/ virtual void __unk_vfn_19();
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
    /*62*/ virtual bool canContainLiquid() const;
    /*69*/ virtual bool checkIsPathable(class Actor &, class BlockPos const &, class BlockPos const &) const;
    /*75*/ virtual void __unk_vfn_75();
    /*82*/ virtual void __unk_vfn_82();
    /*90*/ virtual bool mayPick(class BlockSource const &, class Block const &, bool) const;
    /*100*/ virtual void neighborChanged(class BlockSource &, class BlockPos const &, class BlockPos const &) const;
    /*105*/ virtual void __unk_vfn_105();
    /*110*/ virtual void handleEntityInside(class BlockSource &, class BlockPos const &, class Actor *, class Vec3 &) const;
    /*123*/ virtual void __unk_vfn_123();
    /*125*/ virtual void __unk_vfn_125();
    /*126*/ virtual void __unk_vfn_126();
    /*131*/ virtual void __unk_vfn_131();
    /*135*/ virtual int getColor(class Block const &) const;
    /*137*/ virtual int getColorAtPos(class BlockSource &, class BlockPos const &) const;
    /*140*/ virtual void onGraphicsModeChanged(struct BlockGraphicsModeChangeContext const &);
    /*151*/ virtual void animateTick(class BlockSource &, class BlockPos const &, class Random &) const;
    /*156*/ virtual void __unk_vfn_156();
    /*167*/ virtual void __unk_vfn_167();
    /*168*/ virtual void __unk_vfn_168();
    /*169*/ virtual void __unk_vfn_169();
    /*170*/ virtual void onPlace(class BlockSource &, class BlockPos const &) const;
    /*176*/ virtual void __unk_vfn_176();
    /*186*/ virtual class mce::Color getMapColor(class BlockSource &, class BlockPos const &) const;
    /*187*/ virtual void __unk_vfn_187();
    /*188*/ virtual int getResourceCount(class Randomize &, class Block const &, int) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_LIQUIDBLOCK
    MCVAPI bool canBeSilkTouched() const;
#endif
    MCAPI LiquidBlock(std::string const &, int, class Material const &);
    MCAPI int getTickDelay(class BlockSource &) const;
    MCAPI static float getHeightFromDepth(int);
    MCAPI static void handleEntityInside(class IConstBlockSource const &, class BlockPos const &, class Vec3 &, class Material const &);

//protected:
    MCAPI void emitFizzParticle(class BlockSource &, class BlockPos const &) const;
    MCAPI void solidify(class BlockSource &, class BlockPos const &, class BlockPos const &) const;
    MCAPI void trySpreadFire(class BlockSource &, class BlockPos const &, class Random &) const;
    MCAPI static int getDepth(class IConstBlockSource const &, class BlockPos const &, class Material const &);
    MCAPI static int getRenderedDepth(class IConstBlockSource const &, class BlockPos const &, class Material const &);

//private:
    MCAPI void _solidify(class BlockSource &, class BlockPos const &, class BlockPos const &) const;
    MCAPI static class Vec3 _getFlow(class IConstBlockSource const &, class BlockPos const &, class Material const &);

protected:

private:

};