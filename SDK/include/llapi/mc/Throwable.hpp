// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"
#include "PredictableProjectile.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class Throwable : public PredictableProjectile {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_THROWABLE
public:
    class Throwable& operator=(class Throwable const &) = delete;
    Throwable(class Throwable const &) = delete;
    Throwable() = delete;
#endif

public:
    /*10*/ virtual void initializeComponents(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*14*/ virtual ~Throwable();
    /*40*/ virtual void __unk_vfn_40();
    /*46*/ virtual void lerpMotion(class Vec3 const &);
    /*60*/ virtual void __unk_vfn_60();
    /*67*/ virtual void __unk_vfn_67();
    /*78*/ virtual float getShadowHeightOffs();
    /*81*/ virtual void __unk_vfn_81();
    /*84*/ virtual void __unk_vfn_84();
    /*87*/ virtual void __unk_vfn_87();
    /*95*/ virtual void __unk_vfn_95();
    /*98*/ virtual void __unk_vfn_98();
    /*105*/ virtual void __unk_vfn_105();
    /*107*/ virtual void __unk_vfn_107();
    /*108*/ virtual void __unk_vfn_108();
    /*110*/ virtual void __unk_vfn_110();
    /*171*/ virtual struct ActorUniqueID getSourceUniqueID() const;
    /*181*/ virtual void __unk_vfn_181();
    /*195*/ virtual void __unk_vfn_195();
    /*220*/ virtual void __unk_vfn_220();
    /*221*/ virtual void __unk_vfn_221();
    /*247*/ virtual void __unk_vfn_247();
    /*250*/ virtual void __unk_vfn_250();
    /*268*/ virtual void __unk_vfn_268();
    /*272*/ virtual void readAdditionalSaveData(class CompoundTag const &, class DataLoadHelper &);
    /*273*/ virtual void addAdditionalSaveData(class CompoundTag &) const;
    /*276*/ virtual void __unk_vfn_276();
    /*283*/ virtual void __unk_vfn_283();
    /*284*/ virtual float getThrowPower();
    /*285*/ virtual void __unk_vfn_285();
    /*286*/ virtual float getThrowUpAngleOffset();
    /*287*/ virtual float getGravity();
    /*288*/ virtual enum ParticleType getParticleType();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_THROWABLE
    MCVAPI bool canMakeStepSound() const;
    MCVAPI void onHit(class HitResult const &);
    MCVAPI bool stopUponGroundCollision() const;
#endif
    MCAPI Throwable(class ActorDefinitionGroup *, struct ActorDefinitionIdentifier const &, class EntityContext &);
    MCAPI void shoot(class Mob &);
    MCAPI void shoot(class Vec3 const &, float, float, class Vec3 const &);

};