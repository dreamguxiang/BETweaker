// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class NbtIo {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_NBTIO
public:
    class NbtIo& operator=(class NbtIo const &) = delete;
    NbtIo(class NbtIo const &) = delete;
    NbtIo() = delete;
#endif

public:
    MCAPI static std::unique_ptr<class CompoundTag> read(class IDataInput &);
    MCAPI static void write(class CompoundTag const *, class IDataOutput &);

protected:

private:

};