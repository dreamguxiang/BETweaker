// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"
#include "Animal.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class Horse : public Animal {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_HORSE
public:
    class Horse& operator=(class Horse const &) = delete;
    Horse(class Horse const &) = delete;
    Horse() = delete;
#endif

public:
    /*8*/ virtual void reloadHardcoded(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*14*/ virtual ~Horse();
    /*35*/ virtual class Vec3 getInterpolatedRidingOffset(float) const;
    /*40*/ virtual void __unk_vfn_40();
    /*48*/ virtual void normalTick();
    /*51*/ virtual void positionPassenger(class Actor &, float);
    /*60*/ virtual void __unk_vfn_60();
    /*67*/ virtual void __unk_vfn_67();
    /*79*/ virtual float getShadowRadius() const;
    /*81*/ virtual void __unk_vfn_81();
    /*84*/ virtual void __unk_vfn_84();
    /*87*/ virtual void __unk_vfn_87();
    /*91*/ virtual bool isImmobile() const;
    /*95*/ virtual void __unk_vfn_95();
    /*98*/ virtual void __unk_vfn_98();
    /*105*/ virtual void __unk_vfn_105();
    /*107*/ virtual void __unk_vfn_107();
    /*108*/ virtual void __unk_vfn_108();
    /*110*/ virtual void __unk_vfn_110();
    /*121*/ virtual void onFailedTame();
    /*125*/ virtual void setStanding(bool);
    /*140*/ virtual void feed(int);
    /*141*/ virtual void handleEntityEvent(enum ActorEvent, int);
    /*173*/ virtual bool canFreeze() const;
    /*181*/ virtual void __unk_vfn_181();
    /*183*/ virtual struct ActorUniqueID getControllingPlayer() const;
    /*185*/ virtual void causeFallDamage(float, float, class ActorDamageSource);
    /*186*/ virtual void handleFallDistanceOnServer(float, float, bool);
    /*190*/ virtual void onSynchedDataUpdate(int);
    /*195*/ virtual void __unk_vfn_195();
    /*217*/ virtual void openContainerComponent(class Player &);
    /*220*/ virtual void __unk_vfn_220();
    /*221*/ virtual void __unk_vfn_221();
    /*247*/ virtual void __unk_vfn_247();
    /*250*/ virtual void __unk_vfn_250();
    /*252*/ virtual void die(class ActorDamageSource const &);
    /*266*/ virtual void updateEntitySpecificMolangVariables(class RenderParams &);
    /*268*/ virtual void __unk_vfn_268();
    /*269*/ virtual bool _hurt(class ActorDamageSource const &, float, bool, bool);
    /*274*/ virtual void _playStepSound(class BlockPos const &, class Block const &);
    /*276*/ virtual void __unk_vfn_276();
    /*283*/ virtual void __unk_vfn_283();
    /*294*/ virtual void travel(float, float, float);
    /*297*/ virtual void aiStep();
    /*310*/ virtual void __unk_vfn_310();
    /*314*/ virtual void __unk_vfn_314();
    /*319*/ virtual int getArmorValue() const;
    /*348*/ virtual void __unk_vfn_348();
    /*362*/ virtual void __unk_vfn_362();
    /*364*/ virtual void setType(int);
    /*365*/ virtual int getType() const;
    /*366*/ virtual void setHorseEating(bool);
    /*367*/ virtual float getStandAnim(float) const;
    /*368*/ virtual bool isAdult() const;
    /*369*/ virtual bool isHorseEating() const;
    /*370*/ virtual bool isMouthOpen() const;
    /*371*/ virtual bool isTailMoving() const;
    /*372*/ virtual void makeMad();
    /*373*/ virtual bool tameToPlayer(class Player &, bool);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_HORSE
    MCVAPI bool useNewAi() const;
#endif
    MCAPI Horse(class ActorDefinitionGroup *, struct ActorDefinitionIdentifier const &, class EntityContext &);
    MCAPI void postNormalTick();
    MCAPI void postTravel(class Actor *, bool, enum HorsePostTravelType);
    MCAPI static int const DONKEY_CHEST_COUNT;
    MCAPI static class Vec3 getInterpolatedRidingOffset(struct RenderRotationComponent const &, struct StandAnimationComponent const &, float);
    MCAPI static class Vec3 getInterpolatedRidingOffset(class Vec2 const &, float, float, float);

//private:
    MCAPI void setHorseFlag(enum HorseFlags, bool);
    MCAPI bool setHorseType(enum ActorType &);

private:
    MCAPI static int const DATA_AGE;

};