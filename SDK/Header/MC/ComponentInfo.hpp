// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

struct ComponentInfo {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_COMPONENTINFO
public:
    ComponentInfo(struct ComponentInfo const &) = delete;
    ComponentInfo() = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_COMPONENTINFO
#endif
    MCAPI struct ComponentInfo & operator=(struct ComponentInfo &&);
    MCAPI struct ComponentInfo & operator=(struct ComponentInfo const &);
    MCAPI ~ComponentInfo();
    MCAPI static void bindType();

};