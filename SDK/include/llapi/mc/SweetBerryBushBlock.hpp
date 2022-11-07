// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "BushBlock.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class SweetBerryBushBlock : public BushBlock {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SWEETBERRYBUSHBLOCK
public:
    class SweetBerryBushBlock& operator=(class SweetBerryBushBlock const &) = delete;
    SweetBerryBushBlock(class SweetBerryBushBlock const &) = delete;
    SweetBerryBushBlock() = delete;
#endif

public:
    /*0*/ virtual ~SweetBerryBushBlock();
    /*4*/ virtual bool hasTag(class BlockSource &, class BlockPos const &, class Block const &, std::string const &) const;
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
    /*86*/ virtual bool onFertilized(class BlockSource &, class BlockPos const &, class Actor *, enum FertilizerType) const;
    /*88*/ virtual bool canBeFertilized(class BlockSource &, class BlockPos const &, class Block const &) const;
    /*92*/ virtual bool mayPlace(class BlockSource &, class BlockPos const &) const;
    /*93*/ virtual bool mayPlaceOn(class BlockSource &, class BlockPos const &) const;
    /*102*/ virtual class ItemInstance asItemInstance(class Block const &, class BlockActor const *) const;
    /*103*/ virtual void spawnResources(class BlockSource &, class BlockPos const &, class Block const &, class Randomize &, struct ResourceDropsContext const &, std::vector<class Item const *> *) const;
    /*105*/ virtual void __unk_vfn_105();
    /*109*/ virtual bool attack(class Player *, class BlockPos const &) const;
    /*113*/ virtual void entityInside(class BlockSource &, class BlockPos const &, class Actor &) const;
    /*118*/ virtual void executeEvent(class BlockSource &, class BlockPos const &, class Block const &, std::string const &, class Actor &) const;
    /*123*/ virtual void __unk_vfn_123();
    /*125*/ virtual void __unk_vfn_125();
    /*126*/ virtual void __unk_vfn_126();
    /*131*/ virtual void __unk_vfn_131();
    /*143*/ virtual class AABB const & getVisualShape(class Block const &, class AABB &, bool) const;
    /*146*/ virtual int getVariant(class Block const &) const;
    /*156*/ virtual void __unk_vfn_156();
    /*159*/ virtual bool dealsContactDamage(class Actor const &, class Block const &, bool) const;
    /*167*/ virtual void __unk_vfn_167();
    /*168*/ virtual void __unk_vfn_168();
    /*169*/ virtual void __unk_vfn_169();
    /*174*/ virtual void randomTick(class BlockSource &, class BlockPos const &, class Random &) const;
    /*176*/ virtual void __unk_vfn_176();
    /*178*/ virtual bool use(class Player &, class BlockPos const &, unsigned char) const;
    /*179*/ virtual bool canSurvive(class BlockSource &, class BlockPos const &) const;
    /*180*/ virtual enum BlockRenderLayer getRenderLayer() const;
    /*181*/ virtual enum BlockRenderLayer getRenderLayer(class Block const &, class BlockSource &, class BlockPos const &) const;
    /*187*/ virtual void __unk_vfn_187();
    /*188*/ virtual int getResourceCount(class Randomize &, class Block const &, int) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SWEETBERRYBUSHBLOCK
    MCVAPI bool canBeSilkTouched() const;
    MCVAPI bool isInteractiveBlock() const;
#endif
    MCAPI SweetBerryBushBlock(std::string const &, int);
    MCAPI static class Vec3 const SLOWDOWN_MULTIPLIER;

//private:
    MCAPI bool _growBush(class BlockSource &, class BlockPos const &) const;
    MCAPI bool _pickBerries(class BlockSource &, class BlockPos const &, class Block const &) const;
    MCAPI void _popBerries(class BlockSource &, class BlockPos const &, int const &, std::vector<class Item const *> *) const;

private:

};