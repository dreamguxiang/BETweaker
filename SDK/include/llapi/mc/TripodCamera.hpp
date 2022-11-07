// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"
#include "Mob.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class TripodCamera : public Mob {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_TRIPODCAMERA
public:
    class TripodCamera& operator=(class TripodCamera const &) = delete;
    TripodCamera(class TripodCamera const &) = delete;
    TripodCamera() = delete;
#endif

public:
    /*8*/ virtual void reloadHardcoded(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*14*/ virtual ~TripodCamera();
    /*17*/ virtual void remove();
    /*40*/ virtual void __unk_vfn_40();
    /*60*/ virtual void __unk_vfn_60();
    /*67*/ virtual void __unk_vfn_67();
    /*78*/ virtual float getShadowHeightOffs();
    /*79*/ virtual float getShadowRadius() const;
    /*81*/ virtual void __unk_vfn_81();
    /*84*/ virtual void __unk_vfn_84();
    /*87*/ virtual void __unk_vfn_87();
    /*94*/ virtual bool isPickable();
    /*95*/ virtual void __unk_vfn_95();
    /*98*/ virtual void __unk_vfn_98();
    /*105*/ virtual void __unk_vfn_105();
    /*107*/ virtual void __unk_vfn_107();
    /*108*/ virtual void __unk_vfn_108();
    /*110*/ virtual void __unk_vfn_110();
    /*181*/ virtual void __unk_vfn_181();
    /*195*/ virtual void __unk_vfn_195();
    /*220*/ virtual void __unk_vfn_220();
    /*221*/ virtual void __unk_vfn_221();
    /*247*/ virtual void __unk_vfn_247();
    /*250*/ virtual void __unk_vfn_250();
    /*266*/ virtual void updateEntitySpecificMolangVariables(class RenderParams &);
    /*268*/ virtual void __unk_vfn_268();
    /*269*/ virtual bool _hurt(class ActorDamageSource const &, float, bool, bool);
    /*276*/ virtual void __unk_vfn_276();
    /*283*/ virtual void __unk_vfn_283();
    /*310*/ virtual void __unk_vfn_310();
    /*314*/ virtual void __unk_vfn_314();
    /*347*/ virtual bool canExistWhenDisallowMob() const;
    /*348*/ virtual void __unk_vfn_348();
    /*362*/ virtual void __unk_vfn_362();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_TRIPODCAMERA
    MCVAPI bool breaksFallingBlocks() const;
    MCVAPI bool interactPreventDefault();
    MCVAPI bool isTargetable() const;
#endif
    MCAPI TripodCamera(class ActorDefinitionGroup *, struct ActorDefinitionIdentifier const &, class EntityContext &);
    MCAPI bool interactWithPlayer(class Player &);
    MCAPI bool isActivated() const;
    MCAPI void startTakingPicture(class Player &);

};