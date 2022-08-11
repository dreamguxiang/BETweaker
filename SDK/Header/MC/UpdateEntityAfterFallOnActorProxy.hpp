// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class UpdateEntityAfterFallOnActorProxy {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_UPDATEENTITYAFTERFALLONACTORPROXY
public:
    class UpdateEntityAfterFallOnActorProxy& operator=(class UpdateEntityAfterFallOnActorProxy const &) = delete;
    UpdateEntityAfterFallOnActorProxy(class UpdateEntityAfterFallOnActorProxy const &) = delete;
    UpdateEntityAfterFallOnActorProxy() = delete;
#endif

public:
    /*0*/ virtual class Vec3 & getPosDeltaNonConst();
    /*1*/ virtual bool isSneaking() const;
    /*2*/ virtual void onBounceStarted(class BlockPos const &, class Block const &);
    /*3*/ virtual class Vec3 getPosition() const;
    /*4*/ virtual class IConstBlockSource const & getRegion() const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_UPDATEENTITYAFTERFALLONACTORPROXY
#endif
    MCAPI UpdateEntityAfterFallOnActorProxy(struct IActorMovementProxy &);

};