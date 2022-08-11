// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"
#include "Fireball.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class DragonFireball : public Fireball {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_DRAGONFIREBALL
public:
    class DragonFireball& operator=(class DragonFireball const &) = delete;
    DragonFireball(class DragonFireball const &) = delete;
    DragonFireball() = delete;
#endif

public:
    /*14*/ virtual ~DragonFireball();
    /*41*/ virtual void __unk_vfn_41();
    /*61*/ virtual void __unk_vfn_61();
    /*68*/ virtual void __unk_vfn_68();
    /*82*/ virtual void __unk_vfn_82();
    /*85*/ virtual void __unk_vfn_85();
    /*88*/ virtual void __unk_vfn_88();
    /*95*/ virtual bool isPickable();
    /*96*/ virtual void __unk_vfn_96();
    /*99*/ virtual void __unk_vfn_99();
    /*106*/ virtual void __unk_vfn_106();
    /*108*/ virtual void __unk_vfn_108();
    /*109*/ virtual void __unk_vfn_109();
    /*111*/ virtual void __unk_vfn_111();
    /*182*/ virtual void __unk_vfn_182();
    /*196*/ virtual void __unk_vfn_196();
    /*222*/ virtual void __unk_vfn_222();
    /*223*/ virtual void __unk_vfn_223();
    /*248*/ virtual void __unk_vfn_248();
    /*251*/ virtual void __unk_vfn_251();
    /*269*/ virtual void __unk_vfn_269();
    /*270*/ virtual bool _hurt(class ActorDamageSource const &, float, bool, bool);
    /*277*/ virtual void __unk_vfn_277();
    /*285*/ virtual void __unk_vfn_285();
    /*287*/ virtual void __unk_vfn_287();
    /*288*/ virtual enum ParticleType getTrailParticle();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_DRAGONFIREBALL
    MCVAPI bool shouldBurn();
#endif
    MCAPI DragonFireball(class ActorDefinitionGroup *, struct ActorDefinitionIdentifier const &, class EntityContext &);
    MCAPI static float SPLASH_RANGE;

};