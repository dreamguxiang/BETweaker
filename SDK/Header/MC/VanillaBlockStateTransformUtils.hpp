// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Facing.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class VanillaBlockStateTransformUtils {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_VANILLABLOCKSTATETRANSFORMUTILS
public:
    class VanillaBlockStateTransformUtils& operator=(class VanillaBlockStateTransformUtils const &) = delete;
    VanillaBlockStateTransformUtils(class VanillaBlockStateTransformUtils const &) = delete;
    VanillaBlockStateTransformUtils() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_VANILLABLOCKSTATETRANSFORMUTILS
#endif
    MCAPI static class Block const * transformBlock(class Block const &, enum CommonDirection);
    MCAPI static class Block const * transformBlock(class Block const &, enum Facing::Name);
    MCAPI static class Block const * transformBlock(class Block const &, enum Rotation, enum Mirror);

//private:
    MCAPI static enum CommonDirection _mirror(enum CommonDirection, enum Mirror);
    MCAPI static enum CommonDirection _mirrorFrontBack(enum CommonDirection);
    MCAPI static enum CommonDirection _mirrorLeftRight(enum CommonDirection);
    MCAPI static enum CommonDirection _rotate(enum CommonDirection, enum Rotation);

private:

};