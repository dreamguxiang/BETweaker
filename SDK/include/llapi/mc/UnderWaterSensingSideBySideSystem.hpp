// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class UnderWaterSensingSideBySideSystem {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_UNDERWATERSENSINGSIDEBYSIDESYSTEM
public:
    class UnderWaterSensingSideBySideSystem& operator=(class UnderWaterSensingSideBySideSystem const &) = delete;
    UnderWaterSensingSideBySideSystem(class UnderWaterSensingSideBySideSystem const &) = delete;
    UnderWaterSensingSideBySideSystem() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_UNDERWATERSENSINGSIDEBYSIDESYSTEM
#endif
    MCAPI static struct TickingSystemWithInfo createSystem();

//private:
    MCAPI static void doUnderWaterSensing(class StrictEntityContext &, struct SideBySideLiquidSensingComponent const &, class EntityModifierT<class EntityRegistryBase, class StrictEntityContext, class FlagComponent<struct ActorHeadInWaterFlag>>);

private:

};