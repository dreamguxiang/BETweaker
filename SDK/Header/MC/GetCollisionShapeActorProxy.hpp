// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class GetCollisionShapeActorProxy {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_GETCOLLISIONSHAPEACTORPROXY
public:
    class GetCollisionShapeActorProxy& operator=(class GetCollisionShapeActorProxy const &) = delete;
    GetCollisionShapeActorProxy(class GetCollisionShapeActorProxy const &) = delete;
    GetCollisionShapeActorProxy() = delete;
#endif

public:
    /*0*/ virtual ~GetCollisionShapeActorProxy();
    /*1*/ virtual float getFeetAttachPosY() const;
    /*2*/ virtual bool canDescendThroughBlock() const;
    /*3*/ virtual float getFallDistance() const;
    /*4*/ virtual enum ActorType getEntityTypeId() const;
    /*5*/ virtual bool isWearingLeatherBoots() const;
    /*6*/ virtual bool hasLightWeightFamilyTag() const;
    /*7*/ virtual class AABB const & getAABB() const;
    /*8*/ virtual bool isWorldBuilder() const;
    /*9*/ virtual bool isRiding() const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_GETCOLLISIONSHAPEACTORPROXY
    MCVAPI bool hasPassenger() const;
#endif
    MCAPI GetCollisionShapeActorProxy(struct IActorMovementProxy const &);

};