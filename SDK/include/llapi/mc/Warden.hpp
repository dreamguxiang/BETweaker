// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"
#include "Monster.hpp"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class Warden : public Monster {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_WARDEN
public:
    class Warden& operator=(class Warden const &) = delete;
    Warden(class Warden const &) = delete;
    Warden() = delete;
#endif

public:
    /*14*/ virtual ~Warden();
    /*40*/ virtual void __unk_vfn_40();
    /*42*/ virtual bool canDisableShield();
    /*48*/ virtual void normalTick();
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
    /*113*/ virtual void setTarget(class Actor *);
    /*134*/ virtual bool isInvulnerableTo(class ActorDamageSource const &) const;
    /*181*/ virtual void __unk_vfn_181();
    /*190*/ virtual void onSynchedDataUpdate(int);
    /*195*/ virtual void __unk_vfn_195();
    /*220*/ virtual void __unk_vfn_220();
    /*221*/ virtual void __unk_vfn_221();
    /*247*/ virtual void __unk_vfn_247();
    /*250*/ virtual void __unk_vfn_250();
    /*259*/ virtual void onPush(class Actor &);
    /*268*/ virtual void __unk_vfn_268();
    /*269*/ virtual bool _hurt(class ActorDamageSource const &, float, bool, bool);
    /*276*/ virtual void __unk_vfn_276();
    /*283*/ virtual void __unk_vfn_283();
    /*302*/ virtual bool checkSpawnRules(bool);
    /*303*/ virtual bool checkSpawnObstruction() const;
    /*310*/ virtual void __unk_vfn_310();
    /*313*/ virtual bool doHurtTarget(class Actor *, enum ActorDamageCause const &);
    /*314*/ virtual void __unk_vfn_314();
    /*348*/ virtual void __unk_vfn_348();
    /*362*/ virtual void __unk_vfn_362();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_WARDEN
#endif
    MCAPI Warden(class ActorDefinitionGroup *, struct ActorDefinitionIdentifier const &, class EntityContext &);

};