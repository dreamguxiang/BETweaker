// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"
#include "Item.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class BlockItem : public Item {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLOCKITEM
public:
    class BlockItem& operator=(class BlockItem const &) = delete;
    BlockItem(class BlockItem const &) = delete;
    BlockItem() = delete;
#endif


public:
    /*0*/ virtual ~BlockItem();
    /*7*/ virtual void __unk_vfn_7();
    /*11*/ virtual void __unk_vfn_11();
    /*14*/ virtual void __unk_vfn_14();
    /*16*/ virtual void __unk_vfn_16();
    /*52*/ virtual void __unk_vfn_52();
    /*54*/ virtual void __unk_vfn_54();
    /*57*/ virtual bool isDestructive(int) const;
    /*67*/ virtual void __unk_vfn_67();
    /*68*/ virtual bool isValidAuxValue(int) const;
    /*71*/ virtual void __unk_vfn_71();
    /*72*/ virtual void __unk_vfn_72();
    /*73*/ virtual void __unk_vfn_73();
    /*76*/ virtual void __unk_vfn_76();
    /*80*/ virtual void __unk_vfn_80();
    /*81*/ virtual void __unk_vfn_81();
    /*96*/ virtual std::string buildDescriptionId(class ItemDescriptor const &, class CompoundTag const *) const;
    /*122*/ virtual struct Brightness getLightEmission(int) const;
    /*123*/ virtual struct TextureUVCoordinateSet const & getIcon(class ItemStackBase const &, int, bool) const;
    /*124*/ virtual int getIconYOffset() const;
    /*135*/ virtual bool _calculatePlacePos(class ItemStackBase &, class Actor &, unsigned char &, class BlockPos &) const;
    /*136*/ virtual bool _useOn(class ItemStack &, class Actor &, class BlockPos, unsigned char, class Vec3 const &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_BLOCKITEM
#endif
    MCAPI BlockItem(std::string const &, int);



};