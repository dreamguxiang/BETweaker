// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PhotoItem {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PHOTOITEM
public:
    class PhotoItem& operator=(class PhotoItem const &) = delete;
    PhotoItem(class PhotoItem const &) = delete;
    PhotoItem() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_PHOTOITEM
#endif
    MCAPI static std::string const TAG_PHOTO_NAME;
    MCAPI static std::string const TAG_PHOTO_OWNER;
    MCAPI static std::string const TAG_PHOTO_UUID;

};