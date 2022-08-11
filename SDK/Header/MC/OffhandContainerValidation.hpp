// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "ContainerValidationBase.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class OffhandContainerValidation : public ContainerValidationBase {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_OFFHANDCONTAINERVALIDATION
public:
    class OffhandContainerValidation& operator=(class OffhandContainerValidation const &) = delete;
    OffhandContainerValidation(class OffhandContainerValidation const &) = delete;
    OffhandContainerValidation() = delete;
#endif

public:
    /*0*/ virtual ~OffhandContainerValidation();
    /*1*/ virtual bool isValidSlotForContainer(class ContainerScreenContext const &, class Container const &, int);
    /*2*/ virtual bool isItemAllowedInSlot(class ContainerScreenContext const &, int, class ItemStackBase const &, int) const;
    /*3*/ virtual int getAvailableSetCount(int, class ItemStackBase const &);
    /*4*/ virtual void __unk_vfn_4();
    /*5*/ virtual bool isItemAllowedToRemove(class ContainerScreenContext const &, class ItemStackBase const &) const;
    /*6*/ virtual void __unk_vfn_6();
    /*7*/ virtual bool canDestroy(class ContainerScreenContext const &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_OFFHANDCONTAINERVALIDATION
    MCVAPI bool canItemMoveToContainer(class ItemStackBase const &) const;
    MCVAPI int getContainerOffset(class ContainerScreenContext const &) const;
#endif

};