// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ParticleOnHitSubcomponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PARTICLEONHITSUBCOMPONENT
public:
    class ParticleOnHitSubcomponent& operator=(class ParticleOnHitSubcomponent const &) = delete;
    ParticleOnHitSubcomponent(class ParticleOnHitSubcomponent const &) = delete;
#endif

public:
    /*0*/ virtual ~ParticleOnHitSubcomponent();
    /*1*/ virtual void readfromJSON(class Json::Value &, class SemVersion const &);
    /*2*/ virtual void writetoJSON(class Json::Value &) const;
    /*3*/ virtual void doOnHitEffect(class Actor &, class ProjectileComponent &);
    /*4*/ virtual char const * getName();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_PARTICLEONHITSUBCOMPONENT
#endif
    MCAPI ParticleOnHitSubcomponent();

//private:
    MCAPI bool isParticleTypeIconBreak() const;

private:

};