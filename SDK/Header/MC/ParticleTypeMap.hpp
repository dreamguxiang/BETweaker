// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ParticleTypeMap {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PARTICLETYPEMAP
public:
    class ParticleTypeMap& operator=(class ParticleTypeMap const &) = delete;
    ParticleTypeMap(class ParticleTypeMap const &) = delete;
    ParticleTypeMap() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_PARTICLETYPEMAP
#endif
    MCAPI static std::string const & getParticleName(enum ParticleType);
    MCAPI static enum ParticleType getParticleTypeId(std::string const &);

//private:

private:
    MCAPI static class BidirectionalUnorderedMap<enum ParticleType, std::string> const map;

};