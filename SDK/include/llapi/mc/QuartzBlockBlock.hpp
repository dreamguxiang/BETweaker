// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "BlockLegacy.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class QuartzBlockBlock : public BlockLegacy {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_QUARTZBLOCKBLOCK
public:
    class QuartzBlockBlock& operator=(class QuartzBlockBlock const &) = delete;
    QuartzBlockBlock(class QuartzBlockBlock const &) = delete;
    QuartzBlockBlock() = delete;
#endif

public:
    /*0*/ virtual ~QuartzBlockBlock();
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
    /*102*/ virtual class ItemInstance asItemInstance(class Block const &, class BlockActor const *) const;
    /*105*/ virtual void __unk_vfn_105();
    /*106*/ virtual class Block const & getPlacementBlock(class Actor &, class BlockPos const &, unsigned char, class Vec3 const &, int) const;
    /*123*/ virtual void __unk_vfn_123();
    /*125*/ virtual void __unk_vfn_125();
    /*126*/ virtual void __unk_vfn_126();
    /*131*/ virtual void __unk_vfn_131();
    /*133*/ virtual std::string buildDescriptionId(class Block const &) const;
    /*134*/ virtual bool isAuxValueRelevantForPicking() const;
    /*146*/ virtual int getVariant(class Block const &) const;
    /*149*/ virtual unsigned char getMappedFace(unsigned char, class Block const &) const;
    /*156*/ virtual void __unk_vfn_156();
    /*157*/ virtual class ItemInstance getSilkTouchItemInstance(class Block const &) const;
    /*167*/ virtual void __unk_vfn_167();
    /*168*/ virtual void __unk_vfn_168();
    /*169*/ virtual void __unk_vfn_169();
    /*176*/ virtual void __unk_vfn_176();
    /*187*/ virtual void __unk_vfn_187();
    /*189*/ virtual class ItemInstance getResourceItem(class Randomize &, class Block const &, int) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_QUARTZBLOCKBLOCK
#endif
    MCAPI QuartzBlockBlock(std::string const &, int);

};