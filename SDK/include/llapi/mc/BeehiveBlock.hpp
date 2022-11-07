// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "FaceDirectionalActorBlock.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class BeehiveBlock : public FaceDirectionalActorBlock {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BEEHIVEBLOCK
public:
    class BeehiveBlock& operator=(class BeehiveBlock const &) = delete;
    BeehiveBlock(class BeehiveBlock const &) = delete;
    BeehiveBlock() = delete;
#endif

public:
    /*0*/ virtual ~BeehiveBlock();
    /*3*/ virtual class Block const * getNextBlockPermutation(class Block const &) const;
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
    /*75*/ virtual void __unk_vfn_75();
    /*82*/ virtual void __unk_vfn_82();
    /*98*/ virtual bool playerWillDestroy(class Player &, class BlockPos const &, class Block const &) const;
    /*102*/ virtual class ItemInstance asItemInstance(class Block const &, class BlockActor const *) const;
    /*105*/ virtual void __unk_vfn_105();
    /*118*/ virtual void executeEvent(class BlockSource &, class BlockPos const &, class Block const &, std::string const &, class Actor &) const;
    /*123*/ virtual void __unk_vfn_123();
    /*125*/ virtual void __unk_vfn_125();
    /*126*/ virtual void __unk_vfn_126();
    /*127*/ virtual int getComparatorSignal(class BlockSource &, class BlockPos const &, class Block const &, unsigned char) const;
    /*131*/ virtual void __unk_vfn_131();
    /*146*/ virtual int getVariant(class Block const &) const;
    /*149*/ virtual unsigned char getMappedFace(unsigned char, class Block const &) const;
    /*151*/ virtual void animateTick(class BlockSource &, class BlockPos const &, class Random &) const;
    /*156*/ virtual void __unk_vfn_156();
    /*167*/ virtual void __unk_vfn_167();
    /*168*/ virtual void __unk_vfn_168();
    /*169*/ virtual void __unk_vfn_169();
    /*176*/ virtual void __unk_vfn_176();
    /*178*/ virtual bool use(class Player &, class BlockPos const &, unsigned char) const;
    /*187*/ virtual void __unk_vfn_187();
    /*189*/ virtual class ItemInstance getResourceItem(class Randomize &, class Block const &, int) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_BEEHIVEBLOCK
    MCVAPI bool canBeSilkTouched() const;
    MCVAPI bool hasComparatorSignal() const;
#endif
    MCAPI BeehiveBlock(std::string const &, int);
    MCAPI void emitHoneyComb(class BlockSource &, class BlockPos const &) const;
    MCAPI void evictAll(class BlockSource &, class BlockPos const &, bool) const;
    MCAPI void onPlayerPlace(class BlockSource &, class BlockPos const &) const;
    MCAPI static void deliverNectar(class BlockSource &, class Block const &, class BlockPos const &);
    MCAPI static bool hasHoneyToHarvest(class Block const &);
    MCAPI static void resetHoneyLevel(class BlockSource &, class Block const &, class BlockPos const &);

//private:
    MCAPI void _fillHoneyBottle(class Player &, class ItemStack &, class ItemStack &, class BlockSource &, class BlockPos const &) const;

private:

};