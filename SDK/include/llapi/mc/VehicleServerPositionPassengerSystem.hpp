// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class VehicleServerPositionPassengerSystem {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_VEHICLESERVERPOSITIONPASSENGERSYSTEM
public:
    class VehicleServerPositionPassengerSystem& operator=(class VehicleServerPositionPassengerSystem const &) = delete;
    VehicleServerPositionPassengerSystem(class VehicleServerPositionPassengerSystem const &) = delete;
    VehicleServerPositionPassengerSystem() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_VEHICLESERVERPOSITIONPASSENGERSYSTEM
#endif
    MCAPI static void _rotateMobPassenger(class ViewedEntityContextT<class StrictEntityContext, struct ActorHeadRotationComponent const, struct SynchedActorDataComponent const, struct ActorRotationComponent, struct MobBodyRotationComponent, struct PassengerYRotLimitComponent>, class OptionalComponentWrapper<class StrictEntityContext, class FlagComponent<struct PlayerComponentFlag> const>, struct ActorRotationComponent const &);
    MCAPI static struct TickingSystemWithInfo createSystem();

};