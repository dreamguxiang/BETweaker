// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ContainerModel {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CONTAINERMODEL
public:
    class ContainerModel& operator=(class ContainerModel const &) = delete;
    ContainerModel(class ContainerModel const &) = delete;
    ContainerModel() = delete;
#endif

public:
    /*0*/ virtual void containerContentChanged(int);
    /*1*/ virtual ~ContainerModel();
    /*2*/ virtual void postInit();
    /*3*/ virtual void releaseResources();
    /*4*/ virtual int getContainerSize() const;
    /*5*/ virtual int getFilteredContainerSize() const;
    /*6*/ virtual void __unk_vfn_6();
    /*7*/ virtual class ContainerWeakRef getContainerWeakRef() const;
    /*8*/ virtual class ItemStack const & getItemStack(int) const;
    /*9*/ virtual std::vector<class ItemStack> const & getItems() const;
    /*10*/ virtual class ItemInstance const & getItemInstance(int) const;
    /*11*/ virtual class ItemStackBase const & getItemStackBase(int) const;
    /*12*/ virtual void __unk_vfn_12();
    /*13*/ virtual void setItem(int, class ItemStack const &);
    /*14*/ virtual bool isValid();
    /*15*/ virtual void __unk_vfn_15();
    /*16*/ virtual void __unk_vfn_16();
    /*17*/ virtual enum ContainerExpandStatus getItemExpandStatus(int);
    /*18*/ virtual std::string const & getItemGroupName(int) const;
    /*19*/ virtual void __unk_vfn_19();
    /*20*/ virtual class Container * _getContainer();
    /*21*/ virtual int _getContainerOffset();
    /*22*/ virtual void _onItemChanged(int, class ItemStack const &, class ItemStack const &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CONTAINERMODEL
    MCVAPI enum ContainerExpandStatus getItemExpandStatus(int) const;
    MCVAPI bool isExpanableItemFiltered(int) const;
    MCVAPI bool isItemFiltered(class ItemStackBase const &) const;
    MCVAPI bool isItemInstanceBased() const;
    MCVAPI void switchItemExpando(int);
    MCVAPI void tick(int);
#endif
    MCAPI ContainerModel(enum ContainerEnumName, int, enum ContainerCategory, bool);
    MCAPI bool _useLegacyTransactions() const;
    MCAPI enum ContainerEnumName getContainerEnumName() const;
    MCAPI int getContainerSlot(int) const;
    MCAPI std::string const & getContainerStringName() const;
    MCAPI int getModelSlot(int) const;
    MCAPI void initContainerRuntimeId();
    MCAPI bool isContainerSlotInRange(int) const;
    MCAPI bool isIntermediaryCategory() const;
    MCAPI void networkUpdateItem(int, class ItemStack const &, class ItemStack const &);
    MCAPI void registerOnContainerChangedCallback(class std::function<void (int, class ItemStack const &, class ItemStack const &)>);
    MCAPI void registerPlayerNotificationCallback(class std::function<void (int, class ItemStack const &, class ItemStack const &)>);
    MCAPI void serverInitItemStackIds();
    MCAPI void setClientUIContainer(class SparseContainerClient *);
    MCAPI void setItemSource(int, struct SlotData const &);

//protected:
    MCAPI void _init();
    MCAPI void _notifyPlayer(int, class ItemStack const &, class ItemStack const &);

//private:
    MCAPI void _onClientUIItemNetworkChanged(int, class ItemStack const &, class ItemStack const &);

protected:

private:

};