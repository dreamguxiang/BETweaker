// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Util.hpp"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class BlockCollisionBoxProcessor {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLOCKCOLLISIONBOXPROCESSOR
public:
    class BlockCollisionBoxProcessor& operator=(class BlockCollisionBoxProcessor const &) = delete;
    BlockCollisionBoxProcessor(class BlockCollisionBoxProcessor const &) = delete;
    BlockCollisionBoxProcessor() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_BLOCKCOLLISIONBOXPROCESSOR
#endif
    MCAPI static void _tryBake(struct BlockRotationComponent const *, struct BlockCollisionBoxComponent *);
    MCAPI static std::unique_ptr<class Util::EntityComponentProcessor> getProcessor();

};