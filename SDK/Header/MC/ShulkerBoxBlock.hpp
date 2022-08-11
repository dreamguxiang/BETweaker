// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "ChestBlock.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ShulkerBoxBlock : public ChestBlock {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SHULKERBOXBLOCK
public:
    class ShulkerBoxBlock& operator=(class ShulkerBoxBlock const &) = delete;
    ShulkerBoxBlock(class ShulkerBoxBlock const &) = delete;
    ShulkerBoxBlock() = delete;
#endif

public:
    /*0*/ virtual ~ShulkerBoxBlock();
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
    /*59*/ virtual void __unk_vfn_59();
    /*60*/ virtual void __unk_vfn_60();
    /*69*/ virtual bool dispense(class BlockSource &, class Container &, int, class Vec3 const &, unsigned char) const;
    /*73*/ virtual void __unk_vfn_73();
    /*77*/ virtual void setupRedstoneComponent(class BlockSource &, class BlockPos const &);
    /*80*/ virtual void __unk_vfn_80();
    /*94*/ virtual bool breaksFallingBlocks(class Block const &, class BaseGameVersion) const;
    /*96*/ virtual bool playerWillDestroy(class Player &, class BlockPos const &, class Block const &) const;
    /*101*/ virtual class ItemInstance getResourceItem(class Randomize &, class Block const &, int) const;
    /*102*/ virtual class ItemInstance asItemInstance(class BlockSource &, class BlockPos const &, class Block const &) const;
    /*103*/ virtual void spawnResources(class BlockSource &, class BlockPos const &, class Block const &, class Randomize &, std::vector<class Item const *> *, float, int) const;
    /*105*/ virtual void __unk_vfn_105();
    /*106*/ virtual class Block const & getPlacementBlock(class Actor &, class BlockPos const &, unsigned char, class Vec3 const &, int) const;
    /*124*/ virtual void __unk_vfn_124();
    /*126*/ virtual void __unk_vfn_126();
    /*127*/ virtual void __unk_vfn_127();
    /*132*/ virtual void __unk_vfn_132();
    /*135*/ virtual bool isAuxValueRelevantForPicking();
    /*136*/ virtual int getColor(class Block const &) const;
    /*139*/ virtual int getColorForParticle(class BlockSource &, class BlockPos const &, class Block const &) const;
    /*148*/ virtual void __unk_vfn_148();
    /*157*/ virtual void __unk_vfn_157();
    /*168*/ virtual void __unk_vfn_168();
    /*169*/ virtual void __unk_vfn_169();
    /*170*/ virtual void __unk_vfn_170();
    /*177*/ virtual void __unk_vfn_177();
    /*187*/ virtual class mce::Color getMapColor(class BlockSource &, class BlockPos const &) const;
    /*188*/ virtual void __unk_vfn_188();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SHULKERBOXBLOCK
#endif
    MCAPI ShulkerBoxBlock(std::string const &, int);

//protected:
    MCAPI void spawnBoxInstance(class BlockSource &, class Level &, class BlockPos const &, class Block const &, std::string const &, std::unique_ptr<class CompoundTag>, int) const;

protected:
    MCAPI static class BaseGameVersion const SHULKER_BOX_DOESNT_BREAK_FALLING_BLOCK_VERSION;

};