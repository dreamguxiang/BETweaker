// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"
#include "Item.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class TridentItem : public Item {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_TRIDENTITEM
public:
    class TridentItem& operator=(class TridentItem const &) = delete;
    TridentItem(class TridentItem const &) = delete;
    TridentItem() = delete;
#endif

public:
    /*0*/ virtual ~TridentItem();
    /*7*/ virtual void __unk_vfn_7();
    /*11*/ virtual void __unk_vfn_11();
    /*14*/ virtual void __unk_vfn_14();
    /*16*/ virtual void __unk_vfn_16();
    /*23*/ virtual bool isThrowable();
    /*48*/ virtual short getMaxDamage() const;
    /*49*/ virtual int getAttackDamage() const;
    /*52*/ virtual void __unk_vfn_52();
    /*54*/ virtual void __unk_vfn_54();
    /*56*/ virtual bool canDestroyInCreative();
    /*61*/ virtual void appendFormattedHovertext(class ItemStackBase const &, class Level &, std::string &, bool) const;
    /*63*/ virtual int getEnchantSlot() const;
    /*64*/ virtual int getEnchantValue();
    /*67*/ virtual void __unk_vfn_67();
    /*71*/ virtual void __unk_vfn_71();
    /*72*/ virtual void __unk_vfn_72();
    /*73*/ virtual void __unk_vfn_73();
    /*76*/ virtual void __unk_vfn_76();
    /*80*/ virtual void __unk_vfn_80();
    /*81*/ virtual void __unk_vfn_81();
    /*85*/ virtual class ItemStack & use(class ItemStack &, class Player &) const;
    /*86*/ virtual bool dispense(class BlockSource &, class Container &, int, class Vec3 const &, unsigned char) const;
    /*88*/ virtual void releaseUsing(class ItemStack &, class Player *, int) const;
    /*90*/ virtual void hurtActor(class ItemStack &, class Actor &, class Mob &) const;
    /*130*/ virtual void __unk_vfn_130();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_TRIDENTITEM
#endif
    MCAPI TridentItem(std::string const &, int);
    MCAPI static int const CHARGE_THRESHOLD_TIME;
    MCAPI static int const THROW_THRESHOLD_TIME;

//private:
    MCAPI class Actor * _setupProjectile(class Actor *, class ItemStack, bool) const;

private:

};