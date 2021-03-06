// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class Boat : public Actor {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BOAT
public:
    class Boat& operator=(class Boat const &) = delete;
    Boat(class Boat const &) = delete;
    Boat() = delete;
#endif


public:
    /*8*/ virtual void reloadHardcoded(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*9*/ virtual void reloadHardcodedClient(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*14*/ virtual ~Boat();
    /*18*/ virtual void remove();
    /*40*/ virtual void __unk_vfn_40();
    /*48*/ virtual void normalTick();
    /*55*/ virtual std::string getExitTip(std::string const &, enum InputMode) const;
    /*60*/ virtual void __unk_vfn_60();
    /*67*/ virtual void __unk_vfn_67();
    /*78*/ virtual float getShadowHeightOffs();
    /*79*/ virtual float getShadowRadius() const;
    /*81*/ virtual void __unk_vfn_81();
    /*87*/ virtual void __unk_vfn_87();
    /*89*/ virtual void onAboveBubbleColumn(bool);
    /*94*/ virtual bool isPickable();
    /*95*/ virtual void __unk_vfn_95();
    /*98*/ virtual void __unk_vfn_98();
    /*105*/ virtual void __unk_vfn_105();
    /*107*/ virtual void __unk_vfn_107();
    /*108*/ virtual void __unk_vfn_108();
    /*110*/ virtual void __unk_vfn_110();
    /*134*/ virtual bool isInvulnerableTo(class ActorDamageSource const &) const;
    /*181*/ virtual void __unk_vfn_181();
    /*183*/ virtual struct ActorUniqueID getControllingPlayer() const;
    /*191*/ virtual bool canAddPassenger(class Actor &) const;
    /*195*/ virtual void __unk_vfn_195();
    /*220*/ virtual void __unk_vfn_220();
    /*221*/ virtual void __unk_vfn_221();
    /*224*/ virtual float getPassengerYRotation(class Actor const &) const;
    /*246*/ virtual void __unk_vfn_246();
    /*249*/ virtual void __unk_vfn_249();
    /*267*/ virtual void __unk_vfn_267();
    /*268*/ virtual bool _hurt(class ActorDamageSource const &, float, bool, bool);
    /*275*/ virtual void __unk_vfn_275();
    /*284*/ virtual void __unk_vfn_284();
    /*285*/ virtual void destroy(class Actor *);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_BOAT
#endif
    MCAPI Boat(class ActorDefinitionGroup *, struct ActorDefinitionIdentifier const &, class EntityContext &);
    MCAPI void computePaddleForcesBasedOnGaze(class Vec3 &, float &, float &, float, float);
    MCAPI float getRowingTime(enum Side) const;
    MCAPI unsigned char getWoodID() const;
    MCAPI void postNormalTick();
    MCAPI bool setPaddleForce(enum Side, float);
    MCAPI bool setPaddleState(enum Side, bool);
    MCAPI void setRowingTime(enum Side, float);

//private:
    MCAPI void _computePaddleForce(float &, float &, float, float);
    MCAPI void _control();
    MCAPI void _move();
    MCAPI void _paddleControl(enum Side, class Vec3 &, class Vec3 &);


private:


};