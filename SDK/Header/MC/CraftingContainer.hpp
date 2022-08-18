// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Container.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class CraftingContainer : public Container {

#define AFTER_EXTRA
// Add Member There
#define DISABLE_CONSTRUCTOR_PREVENTION_CRAFTINGCONTAINER
public:
    std::vector<ItemStack> mItems;
    int mWidth;
	
#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CRAFTINGCONTAINER
public:
    class CraftingContainer& operator=(class CraftingContainer const &) = default;
    CraftingContainer(class CraftingContainer const &) = default;
    CraftingContainer() = default;
#endif

public:
    /*0*/ virtual ~CraftingContainer();
    /*2*/ virtual void serverInitItemStackIds(int, int, class std::function<void (int, class ItemStack const &)>);
    /*5*/ virtual class ItemStack const & getItem(int) const;
    /*9*/ virtual void setItem(int, class ItemStack const &);
    /*14*/ virtual int getContainerSize() const;
    /*15*/ virtual int getMaxStackSize() const;
    /*16*/ virtual void startOpen(class Player &);
    /*17*/ virtual void stopOpen(class Player &);
    /*22*/ virtual void __unk_vfn_22();
    /*23*/ virtual void __unk_vfn_23();
    /*24*/ virtual void setContainerChanged(int);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CRAFTINGCONTAINER
#endif
    MCAPI CraftingContainer(int, int);
    MCAPI class ItemStack const & getItem(int, int) const;

};