// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

struct ItemInUseComponent {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ITEMINUSECOMPONENT
public:
    struct ItemInUseComponent& operator=(struct ItemInUseComponent const &) = delete;
    ItemInUseComponent(struct ItemInUseComponent const &) = delete;
    ItemInUseComponent() = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ITEMINUSECOMPONENT
#endif
    MCAPI struct ItemInUseComponent & operator=(struct ItemInUseComponent &&);
    MCAPI ~ItemInUseComponent();

};