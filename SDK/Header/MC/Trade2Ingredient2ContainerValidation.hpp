// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "ContainerValidationBase.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class Trade2Ingredient2ContainerValidation : public ContainerValidationBase {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_TRADE2INGREDIENT2CONTAINERVALIDATION
public:
    class Trade2Ingredient2ContainerValidation& operator=(class Trade2Ingredient2ContainerValidation const &) = delete;
    Trade2Ingredient2ContainerValidation(class Trade2Ingredient2ContainerValidation const &) = delete;
    Trade2Ingredient2ContainerValidation() = delete;
#endif

public:
    /*0*/ virtual ~Trade2Ingredient2ContainerValidation();
    /*1*/ virtual bool isValidSlotForContainer(class ContainerScreenContext const &, class Container const &, int);
    /*2*/ virtual void __unk_vfn_2();
    /*3*/ virtual int getAvailableSetCount(int, class ItemStackBase const &);
    /*4*/ virtual void __unk_vfn_4();
    /*5*/ virtual void __unk_vfn_5();
    /*6*/ virtual bool canItemMoveToContainer(class ItemStackBase const &);
    /*7*/ virtual bool canDestroy(class ContainerScreenContext const &);
    /*8*/ virtual int getContainerOffset(class ContainerScreenContext const &) const;
    /*9*/ virtual int getContainerSize(class ContainerScreenContext const &, class Container const &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_TRADE2INGREDIENT2CONTAINERVALIDATION
#endif

};