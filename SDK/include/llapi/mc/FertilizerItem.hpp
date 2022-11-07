// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"
#include "Item.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class FertilizerItem : public Item {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_FERTILIZERITEM
public:
    class FertilizerItem& operator=(class FertilizerItem const &) = delete;
    FertilizerItem(class FertilizerItem const &) = delete;
    FertilizerItem() = delete;
#endif

public:
    /*0*/ virtual ~FertilizerItem();
    /*7*/ virtual void __unk_vfn_7();
    /*10*/ virtual void executeEvent(class ItemStackBase &, std::string const &, class RenderParams &) const;
    /*11*/ virtual void __unk_vfn_11();
    /*14*/ virtual void __unk_vfn_14();
    /*16*/ virtual void __unk_vfn_16();
    /*21*/ virtual bool isFertilizer() const;
    /*51*/ virtual void __unk_vfn_51();
    /*53*/ virtual void __unk_vfn_53();
    /*66*/ virtual void __unk_vfn_66();
    /*70*/ virtual void __unk_vfn_70();
    /*71*/ virtual void __unk_vfn_71();
    /*72*/ virtual void __unk_vfn_72();
    /*75*/ virtual void __unk_vfn_75();
    /*79*/ virtual void __unk_vfn_79();
    /*80*/ virtual void __unk_vfn_80();
    /*85*/ virtual bool dispense(class BlockSource &, class Container &, int, class Vec3 const &, unsigned char) const;
    /*132*/ virtual bool _useOn(class ItemStack &, class Actor &, class BlockPos, unsigned char, class Vec3 const &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_FERTILIZERITEM
#endif
    MCAPI FertilizerItem(std::string const &, int, enum FertilizerType);
    MCAPI enum FertilizerType getFertilizerType() const;

};