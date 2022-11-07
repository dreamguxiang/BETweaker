// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
#include "LayeredAbilities.hpp"
#undef BEFORE_EXTRA

struct SerializedAbilitiesData {

#define AFTER_EXTRA
public:
     ActorUniqueID mUid;
	 LayeredAbilities mAbilities;
	
#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SERIALIZEDABILITIESDATA
public:
    struct SerializedAbilitiesData& operator=(struct SerializedAbilitiesData const &) = delete;
    SerializedAbilitiesData(struct SerializedAbilitiesData const &) = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SERIALIZEDABILITIESDATA
#endif
    MCAPI SerializedAbilitiesData();
    MCAPI SerializedAbilitiesData(struct ActorUniqueID, class LayeredAbilities const &);
    MCAPI void fillIn(class LayeredAbilities &) const;
    MCAPI struct ActorUniqueID getTargetPlayer() const;
    MCAPI ~SerializedAbilitiesData();

//private:

};