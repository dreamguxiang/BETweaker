// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "BlockLegacy.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PowderSnowBlock : public BlockLegacy {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_POWDERSNOWBLOCK
public:
    class PowderSnowBlock& operator=(class PowderSnowBlock const &) = delete;
    PowderSnowBlock(class PowderSnowBlock const &) = delete;
    PowderSnowBlock() = delete;
#endif


public:
    /*0*/ virtual ~PowderSnowBlock();
    /*5*/ virtual bool getCollisionShape(class AABB &, class Block const &, class IConstBlockSource const &, class BlockPos const &, class optional_ref<class GetCollisionShapeInterface const>) const;
    /*10*/ virtual class AABB const & getAABB(class IConstBlockSource const &, class BlockPos const &, class Block const &, class AABB &, bool) const;
    /*19*/ virtual void __unk_vfn_19();
    /*22*/ virtual bool canProvideSupport(class Block const &, unsigned char, enum BlockSupportType) const;
    /*25*/ virtual bool canConnect(class Block const &, unsigned char, class Block const &) const;
    /*29*/ virtual void __unk_vfn_29();
    /*30*/ virtual void __unk_vfn_30();
    /*31*/ virtual bool isClimbable(struct IActorMovementProxy const &) const;
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
    /*53*/ virtual bool canBeAscendedByJumping(class Actor const &, class BlockPos const &) const;
    /*59*/ virtual void __unk_vfn_59();
    /*60*/ virtual void __unk_vfn_60();
    /*61*/ virtual bool canContainLiquid() const;
    /*73*/ virtual void __unk_vfn_73();
    /*80*/ virtual void __unk_vfn_80();
    /*94*/ virtual bool breaksFallingBlocks(class Block const &, class BaseGameVersion) const;
    /*100*/ virtual int getResourceCount(class Randomize &, class Block const &, int) const;
    /*101*/ virtual class ItemInstance getResourceItem(class Randomize &, class Block const &, int) const;
    /*102*/ virtual class ItemInstance asItemInstance(class BlockSource &, class BlockPos const &, class Block const &) const;
    /*104*/ virtual void trySpawnResourcesOnExplosion(class BlockSource &, class BlockPos const &, class Block const &, class Randomize &, std::vector<class Item const *> *, float, int) const;
    /*105*/ virtual void __unk_vfn_105();
    /*113*/ virtual void entityInside(class BlockSource &, class BlockPos const &, class Actor &) const;
    /*124*/ virtual void __unk_vfn_124();
    /*126*/ virtual void __unk_vfn_126();
    /*127*/ virtual void __unk_vfn_127();
    /*132*/ virtual void __unk_vfn_132();
    /*148*/ virtual void __unk_vfn_148();
    /*165*/ virtual void __unk_vfn_165();
    /*178*/ virtual void __unk_vfn_178();
    /*179*/ virtual void __unk_vfn_179();
    /*180*/ virtual void __unk_vfn_180();
    /*182*/ virtual void onFallOn(class BlockSource &, class BlockPos const &, class Actor &, float) const;
    /*187*/ virtual void __unk_vfn_187();
    /*199*/ virtual void __unk_vfn_199();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_POWDERSNOWBLOCK
    MCVAPI bool canBeDestroyedByWaterSpread() const;
    MCVAPI bool canBeSilkTouched() const;
    MCVAPI bool causesFreezeEffect() const;
#endif
    MCAPI PowderSnowBlock(std::string const &, int, class Material const &);
    MCAPI static bool canWalkOnTop(struct IActorMovementProxy const &);
    MCAPI static bool canWalkOnTop(class GetCollisionShapeInterface const &);
    MCAPI static void clearFire(class BlockSource &, class BlockPos const &, class Block const &);



};