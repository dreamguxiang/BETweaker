// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct LibraryScreenCapabilities {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_LIBRARYSCREENCAPABILITIES
public:
    struct LibraryScreenCapabilities& operator=(struct LibraryScreenCapabilities const &) = delete;
    LibraryScreenCapabilities(struct LibraryScreenCapabilities const &) = delete;
    LibraryScreenCapabilities() = delete;
#endif
public:
    /*0*/ virtual ~LibraryScreenCapabilities();
    /*1*/ virtual bool isOfType(class typeid_t<class IScreenCapabilities>);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_LIBRARYSCREENCAPABILITIES
#endif

};