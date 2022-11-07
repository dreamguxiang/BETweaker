// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"
#include "Item.hpp"
#include "DiggerItem.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class HatchetItem : public DiggerItem {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_HATCHETITEM
public:
    class HatchetItem& operator=(class HatchetItem const &) = delete;
    HatchetItem(class HatchetItem const &) = delete;
    HatchetItem() = delete;
#endif

public:
    /*0*/ virtual ~HatchetItem();
    /*7*/ virtual void __unk_vfn_7();
    /*10*/ virtual void executeEvent(class ItemStackBase &, std::string const &, class RenderParams &) const;
    /*11*/ virtual void __unk_vfn_11();
    /*14*/ virtual void __unk_vfn_14();
    /*16*/ virtual void __unk_vfn_16();
    /*51*/ virtual void __unk_vfn_51();
    /*53*/ virtual void __unk_vfn_53();
    /*62*/ virtual int getEnchantSlot() const;
    /*66*/ virtual void __unk_vfn_66();
    /*70*/ virtual void __unk_vfn_70();
    /*71*/ virtual void __unk_vfn_71();
    /*72*/ virtual void __unk_vfn_72();
    /*75*/ virtual void __unk_vfn_75();
    /*79*/ virtual void __unk_vfn_79();
    /*80*/ virtual void __unk_vfn_80();
    /*88*/ virtual float getDestroySpeed(class ItemStackBase const &, class Block const &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_HATCHETITEM
#endif
    MCAPI HatchetItem(std::string const &, int, class Item::Tier const &);

};