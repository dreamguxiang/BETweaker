/**
 * @file  CurseBindingEnchant.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Enchant.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class CurseBindingEnchant.
 *
 */
class CurseBindingEnchant : public Enchant {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CURSEBINDINGENCHANT
public:
    class CurseBindingEnchant& operator=(class CurseBindingEnchant const &) = delete;
    CurseBindingEnchant(class CurseBindingEnchant const &) = delete;
    CurseBindingEnchant() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   -903891052
     */
    virtual ~CurseBindingEnchant();
    /**
     * @vftbl  2
     * @symbol ?getMinCost@CurseBindingEnchant@@UEBAHH@Z
     * @hash   -390383729
     */
    virtual int getMinCost(int) const;
    /**
     * @vftbl  3
     * @symbol ?getMaxCost@CurseBindingEnchant@@UEBAHH@Z
     * @hash   1108525021
     */
    virtual int getMaxCost(int) const;
    /**
     * @vftbl  10
     * @hash   -242808173
     */
    virtual void __unk_vfn_10();
    /**
     * @vftbl  11
     * @hash   -241884652
     */
    virtual void __unk_vfn_11();
    /**
     * @vftbl  12
     * @hash   -233503771
     */
    virtual void __unk_vfn_12();
    /**
     * @vftbl  13
     * @hash   -232580250
     */
    virtual void __unk_vfn_13();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CURSEBINDINGENCHANT
    /**
     * @symbol ?isTreasureOnly@CurseBindingEnchant@@UEBA_NXZ
     * @hash   1615664551
     */
    MCVAPI bool isTreasureOnly() const;
#endif
    /**
     * @symbol ??0CurseBindingEnchant@@QEAA@W4Type@Enchant@@W4Frequency@2@V?$basic_string_span@$$CBD$0?0@gsl@@2H_NH@Z
     * @hash   -296326188
     */
    MCAPI CurseBindingEnchant(enum class Enchant::Type, enum class Enchant::Frequency, class gsl::basic_string_span<char const, -1>, class gsl::basic_string_span<char const, -1>, int, bool, int);

};