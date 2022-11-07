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
    /*84*/ virtual void __unk_vfn_84();
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
    /*210*/ virtual bool canBeAffected(unsigned int) const;
    /*220*/ virtual void __unk_vfn_220();
    /*221*/ virtual void __unk_vfn_221();
    /*247*/ virtual void __unk_vfn_247();
    /*250*/ virtual void __unk_vfn_250();
    /*252*/ virtual void die(class ActorDamageSource const &);
    /*268*/ virtual void __unk_vfn_268();
    /*269*/ virtual bool _hurt(class ActorDamageSource const &, float, bool, bool);
    /*276*/ virtual void __unk_vfn_276();
    /*282*/ virtual void _onSizeUpdated();
    /*283*/ virtual void __unk_vfn_283();
    /*284*/ virtual void knockback(class Actor *, int, float, float, float, float, float);
    /*310*/ virtual void __unk_vfn_310();
    /*314*/ virtual void __unk_vfn_314();
    /*347*/ virtual bool canExistWhenDisallowMob() const;
    /*348*/ virtual void __unk_vfn_348();
    /*357*/ virtual void newServerAiStep();
    /*358*/ virtual void _serverAiMobStep();
    /*362*/ virtual void __unk_vfn_362();
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