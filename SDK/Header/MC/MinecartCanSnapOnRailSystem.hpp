// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class MinecartCanSnapOnRailSystem {

#define AFTER_EXTRA

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MINECARTCANSNAPONRAILSYSTEM
public:
    class MinecartCanSnapOnRailSystem& operator=(class MinecartCanSnapOnRailSystem const &) = delete;
    MinecartCanSnapOnRailSystem(class MinecartCanSnapOnRailSystem const &) = delete;
    MinecartCanSnapOnRailSystem() = delete;
#endif


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_MINECARTCANSNAPONRAILSYSTEM
#endif
    MCAPI static class std::optional<class BlockPos> getSnapOnRailBlockPos(class BlockPos const &, class Vec3 const &, class IConstBlockSource const &);



};