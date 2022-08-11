// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PlayerInventory {

#define AFTER_EXTRA
// Add Member There
public:
struct SlotData {
    SlotData() = delete;
    SlotData(SlotData const&) = delete;
    SlotData(SlotData const&&) = delete;
};

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PLAYERINVENTORY
public:
    class PlayerInventory& operator=(class PlayerInventory const &) = delete;
    PlayerInventory(class PlayerInventory const &) = delete;
    PlayerInventory() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_PLAYERINVENTORY
    MCVAPI void containerContentChanged(int);
    MCVAPI void containerSizeChanged(int);
    MCVAPI void createTransactionContext(class std::function<void (class Container &, int, class ItemStack const &, class ItemStack const &)>, class std::function<void (void)>);
#endif
    MCAPI PlayerInventory(std::unique_ptr<class Inventory>);
    MCAPI class std::weak_ptr<class HudContainerManagerModel> _getHudContainerManagerModel();
    MCAPI bool add(class ItemStack &, bool);
    MCAPI void addListener(class ContainerContentChangeListener *);
    MCAPI bool canAdd(class ItemStack const &) const;
    MCAPI int clearInventory(int);
    MCAPI void clearSlot(int, enum ContainerID);
    MCAPI void clearVanishEnchantedItemsOnDeath();
    MCAPI void dropAllOnDeath(bool);
    MCAPI std::vector<enum ContainerID> const & getAllContainerIds();
    MCAPI std::vector<class ItemStack> const & getComplexItems(enum ContainerID) const;
    MCAPI class Container & getContainer();
    MCAPI int getContainerSize(enum ContainerID) const;
    MCAPI int getFirstEmptySlot() const;
    MCAPI int getHotbarSize() const;
    MCAPI class ItemStack const & getItem(int, enum ContainerID) const;
    MCAPI int getItemCount(class std::function<bool (class ItemStack const &)>);
    MCAPI enum ContainerID getSelectedContainerId();
    MCAPI class ItemStack const & getSelectedItem();
    MCAPI struct PlayerInventory::SlotData getSelectedSlot() const;
    MCAPI int getSlotWithItem(class ItemStack const &, bool, bool) const;
    MCAPI bool hasResource(int);
    MCAPI void init(class std::weak_ptr<class HudContainerManagerModel>);
    MCAPI void load(class ListTag const &, class SemVersion const &, class Level &);
    MCAPI void removeItem(int, int, enum ContainerID);
    MCAPI void removeListener(class ContainerContentChangeListener *);
    MCAPI int removeResource(class ItemStack const &, bool, bool, int);
    MCAPI bool removeResource(int);
    MCAPI std::unique_ptr<class ListTag> save();
    MCAPI bool selectSlot(int, enum ContainerID);
    MCAPI void serverInitItemStackId(int);
    MCAPI void serverInitItemStackIds(int, int, class std::function<void (int, class ItemStack const &)>);
    MCAPI void setContainerChanged(int);
    MCAPI void setItem(int, class ItemStack const &, enum ContainerID, bool);
    MCAPI void setSelectedItem(class ItemStack const &);
    MCAPI void setupDefaultInventory();
    MCAPI void swapSlots(int, int);
    MCAPI void tick();

};