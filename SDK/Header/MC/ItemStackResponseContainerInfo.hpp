// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

struct ItemStackResponseContainerInfo {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ITEMSTACKRESPONSECONTAINERINFO
public:
    struct ItemStackResponseContainerInfo& operator=(struct ItemStackResponseContainerInfo const &) = delete;
    ItemStackResponseContainerInfo(struct ItemStackResponseContainerInfo const &) = delete;
    ItemStackResponseContainerInfo() = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ITEMSTACKRESPONSECONTAINERINFO
#endif
    MCAPI ItemStackResponseContainerInfo(enum ContainerEnumName);
    MCAPI ~ItemStackResponseContainerInfo();

};