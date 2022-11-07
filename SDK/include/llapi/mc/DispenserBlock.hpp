// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "ActorBlock.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class DispenserBlock : public ActorBlock {

#define AFTER_EXTRA
// Add Member There
public:
    inline unsigned char getFacing_s(class Block const& a1) const {
        return getFacing(a1);
    }
#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_DISPENSERBLOCK
public:
    class DispenserBlock& operator=(class DispenserBlock const &) = delete;
    DispenserBlock(class DispenserBlock const &) = delete;
    DispenserBlock() = delete;
#endif

public:
    /*0*/ virtual ~DispenserBlock();
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
    /*73*/ virtual void onRedstoneUpdate(class BlockSource &, class BlockPos const &, int, bool) const;
    /*75*/ virtual void __unk_vfn_75();
    /*79*/ virtual void setupRedstoneComponent(class BlockSource &, class BlockPos const &) const;
    /*82*/ virtual void __unk_vfn_82();
    /*102*/ virtual class ItemInstance asItemInstance(class Block const &, class BlockActor const *) const;
    /*105*/ virtual void __unk_vfn_105();
    /*106*/ virtual class Block const & getPlacementBlock(class Actor &, class BlockPos const &, unsigned char, class Vec3 const &, int) const;
    /*123*/ virtual void __unk_vfn_123();
    /*125*/ virtual void __unk_vfn_125();
    /*126*/ virtual void __unk_vfn_126();
    /*127*/ virtual int getComparatorSignal(class BlockSource &, class BlockPos const &, class Block const &, unsigned char) const;
    /*131*/ virtual void __unk_vfn_131();
    /*146*/ virtual int getVariant(class Block const &) const;
    /*149*/ virtual unsigned char getMappedFace(unsigned char, class Block const &) const;
    /*156*/ virtual void __unk_vfn_156();
    /*157*/ virtual class ItemInstance getSilkTouchItemInstance(class Block const &) const;
    /*164*/ virtual void onRemove(class BlockSource &, class BlockPos const &) const;
    /*167*/ virtual void __unk_vfn_167();
    /*168*/ virtual void __unk_vfn_168();
    /*169*/ virtual void __unk_vfn_169();
    /*170*/ virtual void onPlace(class BlockSource &, class BlockPos const &) const;
    /*173*/ virtual void tick(class BlockSource &, class BlockPos const &, class Random &) const;
    /*176*/ virtual void __unk_vfn_176();
    /*178*/ virtual bool use(class Player &, class BlockPos const &, unsigned char) const;
    /*187*/ virtual void __unk_vfn_187();
    /*189*/ virtual class ItemInstance getResourceItem(class Randomize &, class Block const &, int) const;
    /*194*/ virtual int getTickDelay() const;
    /*195*/ virtual void dispenseFrom(class BlockSource &, class BlockPos const &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_DISPENSERBLOCK
    MCVAPI bool hasComparatorSignal() const;
    MCVAPI bool isContainerBlock() const;
    MCVAPI bool isInteractiveBlock() const;
#endif
    MCAPI DispenserBlock(std::string const &, int);
    MCAPI static void ejectItem(class BlockSource &, class Vec3 const &, unsigned char, class ItemStack const &);

//protected:
    MCAPI void ejectItem(class BlockSource &, class Vec3 const &, unsigned char, class ItemStack const &, class Container &, int) const;
    MCAPI class Vec3 getDispensePosition(class BlockSource &, class Vec3 const &) const;
    MCAPI unsigned char getFacing(class Block const &) const;

protected:

};