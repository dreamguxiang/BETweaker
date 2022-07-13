// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"
#include "Animal.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class Pig : public Animal {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PIG
public:
    class Pig& operator=(class Pig const &) = delete;
    Pig(class Pig const &) = delete;
    Pig() = delete;
#endif


public:
    /*14*/ virtual ~Pig();
    /*40*/ virtual void __unk_vfn_40();
    /*48*/ virtual void normalTick();
    /*60*/ virtual void __unk_vfn_60();
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
    /*195*/ virtual void __unk_vfn_195();
    /*220*/ virtual void __unk_vfn_220();
    /*221*/ virtual void __unk_vfn_221();
    /*246*/ virtual void __unk_vfn_246();
    /*249*/ virtual void __unk_vfn_249();
    /*267*/ virtual void __unk_vfn_267();
    /*268*/ virtual bool _hurt(class ActorDamageSource const &, float, bool, bool);
    /*273*/ virtual void _playStepSound(class BlockPos const &, class Block const &);
    /*275*/ virtual void __unk_vfn_275();
    /*284*/ virtual void __unk_vfn_284();
    /*312*/ virtual void __unk_vfn_312();
    /*316*/ virtual void __unk_vfn_316();
    /*350*/ virtual void __unk_vfn_350();
    /*364*/ virtual void __unk_vfn_364();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_PIG
    MCVAPI bool useNewAi() const;
#endif
    MCAPI Pig(class ActorDefinitionGroup *, struct ActorDefinitionIdentifier const &, class EntityContext &);



};