// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "ItemStackRequestActionTransferBase.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ItemStackRequestActionPlace : public ItemStackRequestActionTransferBase {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ITEMSTACKREQUESTACTIONPLACE
public:
    class ItemStackRequestActionPlace& operator=(class ItemStackRequestActionPlace const &) = delete;
    ItemStackRequestActionPlace(class ItemStackRequestActionPlace const &) = delete;
#endif

public:
    /*0*/ virtual ~ItemStackRequestActionPlace();
    /*1*/ virtual void __unk_vfn_1();
    /*2*/ virtual void __unk_vfn_2();
    /*3*/ virtual void __unk_vfn_3();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ITEMSTACKREQUESTACTIONPLACE
#endif
    MCAPI ItemStackRequestActionPlace();

};