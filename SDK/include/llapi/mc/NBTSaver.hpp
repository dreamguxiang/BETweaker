// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class NBTSaver {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_NBTSAVER
public:
    class NBTSaver& operator=(class NBTSaver const &) = delete;
    NBTSaver(class NBTSaver const &) = delete;
    NBTSaver() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_NBTSAVER
#endif
    MCAPI class CompoundTag getSavedCompoundTag();

};