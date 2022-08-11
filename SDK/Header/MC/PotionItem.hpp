// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"
#include "Potion.hpp"
#include "Item.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PotionItem : public Item {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_POTIONITEM
public:
    class PotionItem& operator=(class PotionItem const &) = delete;
    PotionItem(class PotionItem const &) = delete;
    PotionItem() = delete;
#endif

public:
    /*0*/ virtual ~PotionItem();
    /*7*/ virtual void __unk_vfn_7();
    /*11*/ virtual void __unk_vfn_11();
    /*14*/ virtual void __unk_vfn_14();
    /*16*/ virtual void __unk_vfn_16();
    /*51*/ virtual bool isGlint(class ItemStackBase const &) const;
    /*52*/ virtual void __unk_vfn_52();
    /*54*/ virtual void __unk_vfn_54();
    /*57*/ virtual bool isDestructive(int) const;
    /*61*/ virtual void appendFormattedHovertext(class ItemStackBase const &, class Level &, std::string &, bool) const;
    /*67*/ virtual void __unk_vfn_67();
    /*68*/ virtual bool isValidAuxValue(int) const;
    /*71*/ virtual void __unk_vfn_71();
    /*72*/ virtual void __unk_vfn_72();
    /*73*/ virtual void __unk_vfn_73();
    /*76*/ virtual void __unk_vfn_76();
    /*80*/ virtual void __unk_vfn_80();
    /*81*/ virtual void __unk_vfn_81();
    /*85*/ virtual class ItemStack & use(class ItemStack &, class Player &) const;
    /*86*/ virtual bool dispense(class BlockSource &, class Container &, int, class Vec3 const &, unsigned char) const;
    /*87*/ virtual enum ItemUseMethod useTimeDepleted(class ItemStack &, class Level *, class Player *) const;
    /*96*/ virtual std::string buildDescriptionId(class ItemDescriptor const &, class CompoundTag const *) const;
    /*97*/ virtual std::string buildEffectDescriptionName(class ItemStackBase const &) const;
    /*123*/ virtual struct TextureUVCoordinateSet const & getIcon(class ItemStackBase const &, int, bool) const;
    /*125*/ virtual class Item & setIcon(std::string const &, int);
    /*130*/ virtual void __unk_vfn_130();
    /*136*/ virtual bool _useOn(class ItemStack &, class Actor &, class BlockPos, unsigned char, class Vec3 const &) const;
    /*137*/ virtual enum Potion::PotionType getPotionType();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_POTIONITEM
    MCVAPI bool uniqueAuxValues() const;
#endif
    MCAPI PotionItem(std::string const &, int);
    MCAPI static void applyEffect(class ThrownPotion *, class ItemStack const &);
    MCAPI static bool isDestructivePotion(enum Potion::PotionVariant);

};