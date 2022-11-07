// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ExperienceOrb : public Actor {

#define AFTER_EXTRA
// Add Member There
public:
enum DropType;

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_EXPERIENCEORB
public:
    class ExperienceOrb& operator=(class ExperienceOrb const &) = delete;
    ExperienceOrb(class ExperienceOrb const &) = delete;
    ExperienceOrb() = delete;
#endif

public:
    /*8*/ virtual void reloadHardcoded(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*14*/ virtual ~ExperienceOrb();
    /*40*/ virtual void __unk_vfn_40();
    /*48*/ virtual void normalTick();
    /*60*/ virtual void __unk_vfn_60();
    /*67*/ virtual void __unk_vfn_67();
    /*79*/ virtual float getShadowRadius() const;
    /*81*/ virtual void __unk_vfn_81();
    /*84*/ virtual void __unk_vfn_84();
    /*87*/ virtual void __unk_vfn_87();
    /*88*/ virtual void playerTouch(class Player &);
    /*95*/ virtual void __unk_vfn_95();
    /*98*/ virtual void __unk_vfn_98();
    /*105*/ virtual void __unk_vfn_105();
    /*107*/ virtual void __unk_vfn_107();
    /*108*/ virtual void __unk_vfn_108();
    /*110*/ virtual void __unk_vfn_110();
    /*134*/ virtual bool isInvulnerableTo(class ActorDamageSource const &) const;
    /*181*/ virtual void __unk_vfn_181();
    /*195*/ virtual void __unk_vfn_195();
    /*220*/ virtual void __unk_vfn_220();
    /*221*/ virtual void __unk_vfn_221();
    /*247*/ virtual void __unk_vfn_247();
    /*250*/ virtual void __unk_vfn_250();
    /*263*/ virtual void doWaterSplashEffect();
    /*268*/ virtual void __unk_vfn_268();
    /*269*/ virtual bool _hurt(class ActorDamageSource const &, float, bool, bool);
    /*272*/ virtual void readAdditionalSaveData(class CompoundTag const &, class DataLoadHelper &);
    /*273*/ virtual void addAdditionalSaveData(class CompoundTag &) const;
    /*274*/ virtual void _playStepSound(class BlockPos const &, class Block const &);
    /*276*/ virtual void __unk_vfn_276();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_EXPERIENCEORB
#endif
    MCAPI ExperienceOrb(class ActorDefinitionGroup *, struct ActorDefinitionIdentifier const &, class EntityContext &);
    MCAPI int getIconIndex() const;
    MCAPI void postNormalTick();
    MCAPI void setValue(int);
    MCAPI static void spawnOrbs(class BlockSource &, class Vec3 const &, int, int, enum ExperienceOrb::DropType, class Player *);
    MCAPI static void spawnOrbs(class BlockSource &, class Vec3 const &, int, enum ExperienceOrb::DropType, class Player *);

//private:
    MCAPI void _handleMending(class Player &);

private:
    MCAPI static int const LIFETIME;

};