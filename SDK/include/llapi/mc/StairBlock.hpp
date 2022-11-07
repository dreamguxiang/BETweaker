// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "BlockLegacy.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class StairBlock : public BlockLegacy {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_STAIRBLOCK
public:
    class StairBlock& operator=(class StairBlock const &) = delete;
    StairBlock(class StairBlock const &) = delete;
    StairBlock() = delete;
#endif

public:
    /*0*/ virtual ~StairBlock();
    /*9*/ virtual void addAABBs(class Block const &, class BlockSource const &, class BlockPos const &, class AABB const *, std::vector<class AABB> &) const;
    /*11*/ virtual bool addCollisionShapes(class Block const &, class BlockSource const &, class BlockPos const &, class AABB const *, std::vector<class AABB> &, class optional_ref<class GetCollisionShapeInterface const>) const;
    /*13*/ virtual class AABB const & getOutline(class BlockSource &, class BlockPos const &, class AABB &) const;
    /*14*/ virtual bool getLiquidClipVolume(class BlockSource &, class BlockPos const &, class AABB &) const;
    /*17*/ virtual bool liquidCanFlowIntoFromDirection(unsigned char, class std::function<class Block const & (class BlockPos const &)> const &, class BlockPos const &) const;
    /*19*/ virtual void __unk_vfn_19();
    /*22*/ virtual bool canProvideSupport(class Block const &, unsigned char, enum BlockSupportType) const;
    /*25*/ virtual bool canConnect(class Block const &, unsigned char, class Block const &) const;
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
    /*80*/ virtual enum BlockProperty getRedstoneProperty(class BlockSource &, class BlockPos const &) const;
    /*82*/ virtual void __unk_vfn_82();
    /*89*/ virtual bool mayPick() const;
    /*90*/ virtual bool mayPick(class BlockSource const &, class Block const &, bool) const;
    /*91*/ virtual bool mayPlace(class BlockSource &, class BlockPos const &, unsigned char) const;
    /*96*/ virtual bool breaksFallingBlocks(class Block const &, class BaseGameVersion) const;
    /*97*/ virtual void destroy(class BlockSource &, class BlockPos const &, class Block const &, class Actor *) const;
    /*102*/ virtual class ItemInstance asItemInstance(class Block const &, class BlockActor const *) const;
    /*105*/ virtual void __unk_vfn_105();
    /*106*/ virtual class Block const & getPlacementBlock(class Actor &, class BlockPos const &, unsigned char, class Vec3 const &, int) const;
    /*109*/ virtual bool attack(class Player *, class BlockPos const &) const;
    /*110*/ virtual void handleEntityInside(class BlockSource &, class BlockPos const &, class Actor *, class Vec3 &) const;
    /*123*/ virtual void __unk_vfn_123();
    /*125*/ virtual void __unk_vfn_125();
    /*126*/ virtual void __unk_vfn_126();
    /*131*/ virtual void __unk_vfn_131();
    /*146*/ virtual int getVariant(class Block const &) const;
    /*151*/ virtual void animateTick(class BlockSource &, class BlockPos const &, class Random &) const;
    /*156*/ virtual void __unk_vfn_156();
    /*164*/ virtual void onRemove(class BlockSource &, class BlockPos const &) const;
    /*165*/ virtual void onExploded(class BlockSource &, class BlockPos const &, class Actor *) const;
    /*166*/ virtual void onStandOn(class EntityContext &, class BlockPos const &) const;
    /*167*/ virtual void __unk_vfn_167();
    /*168*/ virtual void __unk_vfn_168();
    /*169*/ virtual void __unk_vfn_169();
    /*170*/ virtual void onPlace(class BlockSource &, class BlockPos const &) const;
    /*173*/ virtual void tick(class BlockSource &, class BlockPos const &, class Random &) const;
    /*176*/ virtual void __unk_vfn_176();
    /*177*/ virtual class HitResult clip(class BlockSource const &, class BlockPos const &, class Vec3 const &, class Vec3 const &, bool) const;
    /*178*/ virtual bool use(class Player &, class BlockPos const &, unsigned char) const;
    /*187*/ virtual void __unk_vfn_187();
    /*188*/ virtual int getResourceCount(class Randomize &, class Block const &, int) const;
    /*189*/ virtual class ItemInstance getResourceItem(class Randomize &, class Block const &, int) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_STAIRBLOCK
    MCVAPI bool canBeSilkTouched() const;
    MCVAPI bool isStairBlock() const;
#endif
    MCAPI StairBlock(std::string const &, int, class BlockLegacy const &, int);
    MCAPI bool setInnerPieceShape(class Block const &, class BlockSource const &, class BlockPos const &, class AABB &, bool) const;
    MCAPI bool setStepShape(class Block const &, class BlockSource const &, class BlockPos const &, class AABB &, bool) const;
    MCAPI static unsigned char stairDirectionToFacing(int);

//protected:
    MCAPI void shapeZFightShrink(class AABB &) const;

protected:

};