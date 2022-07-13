// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"
#include "Mob.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class Npc : public Mob {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_NPC
public:
    class Npc& operator=(class Npc const &) = delete;
    Npc(class Npc const &) = delete;
    Npc() = delete;
#endif


public:
    /*8*/ virtual void reloadHardcoded(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*10*/ virtual void initializeComponents(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*14*/ virtual ~Npc();
    /*40*/ virtual void __unk_vfn_40();
    /*59*/ virtual bool canShowNameTag() const;
    /*60*/ virtual void __unk_vfn_60();
    /*64*/ virtual std::string getFormattedNameTag() const;
    /*67*/ virtual void __unk_vfn_67();
    /*81*/ virtual void __unk_vfn_81();
    /*87*/ virtual void __unk_vfn_87();
    /*95*/ virtual void __unk_vfn_95();
    /*98*/ virtual void __unk_vfn_98();
    /*105*/ virtual void __unk_vfn_105();
    /*107*/ virtual void __unk_vfn_107();
    /*108*/ virtual void __unk_vfn_108();
    /*110*/ virtual void __unk_vfn_110();
    /*181*/ virtual void __unk_vfn_181();
    /*193*/ virtual bool canBePulledIntoVehicle() const;
    /*195*/ virtual void __unk_vfn_195();
    /*202*/ virtual void buildDebugInfo(std::string &) const;
    /*211*/ virtual bool canBeAffected(class MobEffectInstance const &) const;
    /*220*/ virtual void __unk_vfn_220();
    /*221*/ virtual void __unk_vfn_221();
    /*246*/ virtual void __unk_vfn_246();
    /*249*/ virtual void __unk_vfn_249();
    /*251*/ virtual void die(class ActorDamageSource const &);
    /*267*/ virtual void __unk_vfn_267();
    /*268*/ virtual bool _hurt(class ActorDamageSource const &, float, bool, bool);
    /*275*/ virtual void __unk_vfn_275();
    /*283*/ virtual void _onSizeUpdated();
    /*284*/ virtual void __unk_vfn_284();
    /*285*/ virtual void knockback(class Actor *, int, float, float, float, float, float);
    /*312*/ virtual void __unk_vfn_312();
    /*316*/ virtual void __unk_vfn_316();
    /*349*/ virtual bool canExistWhenDisallowMob() const;
    /*350*/ virtual void __unk_vfn_350();
    /*359*/ virtual void newServerAiStep();
    /*360*/ virtual void _serverAiMobStep();
    /*364*/ virtual void __unk_vfn_364();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_NPC
    MCVAPI bool breaksFallingBlocks() const;
    MCVAPI bool interactPreventDefault();
    MCVAPI bool isFishable() const;
    MCVAPI bool isTargetable() const;
    MCVAPI bool useNewAi() const;
#endif
    MCAPI Npc(class ActorDefinitionGroup *, struct ActorDefinitionIdentifier const &, class EntityContext &);
    MCAPI static std::string const SKIN_ID_TAG;
    MCAPI static std::vector<struct std::pair<std::string, std::string>> const Skins;



};