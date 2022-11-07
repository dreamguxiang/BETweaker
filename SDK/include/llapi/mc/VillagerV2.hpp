// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"
#include "VillagerBase.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class VillagerV2 : public VillagerBase {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_VILLAGERV2
public:
    class VillagerV2& operator=(class VillagerV2 const &) = delete;
    VillagerV2(class VillagerV2 const &) = delete;
    VillagerV2() = delete;
#endif

public:
    /*8*/ virtual void reloadHardcoded(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*14*/ virtual ~VillagerV2();
    /*17*/ virtual void remove();
    /*19*/ virtual bool isRuntimePredictedMovementEnabled() const;
    /*40*/ virtual void __unk_vfn_40();
    /*60*/ virtual void __unk_vfn_60();
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
    /*195*/ virtual void __unk_vfn_195();
    /*202*/ virtual void buildDebugInfo(std::string &) const;
    /*220*/ virtual void __unk_vfn_220();
    /*221*/ virtual void __unk_vfn_221();
    /*237*/ virtual bool getInteraction(class Player &, class ActorInteraction &, class Vec3 const &);
    /*247*/ virtual void __unk_vfn_247();
    /*250*/ virtual void __unk_vfn_250();
    /*252*/ virtual void die(class ActorDamageSource const &);
    /*266*/ virtual void updateEntitySpecificMolangVariables(class RenderParams &);
    /*268*/ virtual void __unk_vfn_268();
    /*276*/ virtual void __unk_vfn_276();
    /*283*/ virtual void __unk_vfn_283();
    /*294*/ virtual void travel(float, float, float);
    /*310*/ virtual void __unk_vfn_310();
    /*314*/ virtual void __unk_vfn_314();
    /*348*/ virtual void __unk_vfn_348();
    /*357*/ virtual void newServerAiStep();
    /*362*/ virtual void __unk_vfn_362();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_VILLAGERV2
#endif
    MCAPI VillagerV2(class ActorDefinitionGroup *, struct ActorDefinitionIdentifier const &, class EntityContext &);

};