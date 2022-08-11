// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class InventoryMenu {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_INVENTORYMENU
public:
    class InventoryMenu& operator=(class InventoryMenu const &) = delete;
    InventoryMenu(class InventoryMenu const &) = delete;
    InventoryMenu() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_INVENTORYMENU
    MCVAPI class Container * _getContainer() const;
    MCVAPI std::vector<class ItemStack> getItemCopies() const;
    MCVAPI class ItemStack const & getSlot(int) const;
    MCVAPI void removeSlot(int, int);
    MCVAPI void serverInitItemStackIds();
    MCVAPI void setSlot(int, class ItemStack const &, bool);
    MCVAPI ~InventoryMenu();
#endif
    MCAPI InventoryMenu(class Player &, class Container *);

};