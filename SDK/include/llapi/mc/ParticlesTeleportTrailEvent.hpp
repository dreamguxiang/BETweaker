// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ParticlesTeleportTrailEvent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PARTICLESTELEPORTTRAILEVENT
public:
    class ParticlesTeleportTrailEvent& operator=(class ParticlesTeleportTrailEvent const &) = delete;
    ParticlesTeleportTrailEvent(class ParticlesTeleportTrailEvent const &) = delete;
    ParticlesTeleportTrailEvent() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_PARTICLESTELEPORTTRAILEVENT
#endif
    MCAPI std::unique_ptr<class CompoundTag> save() const;

};