// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class UnderWaterSensingSystem {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_UNDERWATERSENSINGSYSTEM
public:
    class UnderWaterSensingSystem& operator=(class UnderWaterSensingSystem const &) = delete;
    UnderWaterSensingSystem(class UnderWaterSensingSystem const &) = delete;
    UnderWaterSensingSystem() = delete;
#endif

public:
    /*0*/ virtual ~UnderWaterSensingSystem();
    /*1*/ virtual void __unk_vfn_1();
    /*2*/ virtual void __unk_vfn_2();
    /*3*/ virtual void tick(class StrictExecutionContext<struct Filter<class FlagComponent<struct ActorMovementTickNeededFlag>, class FlagComponent<struct UsesECSMovementFlag>, struct UpdateWaterStateRequestComponent, class FlagComponent<struct HorseFlag>, class FlagComponent<struct MobFlag>, class FlagComponent<struct ParrotFlag>, struct VehicleComponent, class FlagComponent<struct PlayerComponentFlag>>, struct Read<struct ConstBlockSourceComponent, struct MobBodyRotationComponent, struct PassengerComponent, struct RenderRotationComponent, struct StandAnimationComponent, struct AABBShapeComponent, struct ActorHeadRotationComponent, struct ActorRotationComponent, struct OffsetsComponent, struct StateVectorComponent, struct SynchedActorDataComponent>, struct Write<>, struct AddRemove<class FlagComponent<struct ActorHeadInWaterFlag>>, struct GlobalRead<>, struct GlobalWrite<>, struct EntityFactoryT<>> &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_UNDERWATERSENSINGSYSTEM
#endif
    MCAPI static struct TickingSystemWithInfo createSystem();

//private:
    MCAPI static void doUnderWaterSensing(class StrictEntityContext &, struct ConstBlockSourceComponent const &, struct StateVectorComponent const &, class EntityModifierT<class EntityRegistryBase, class StrictEntityContext, class FlagComponent<struct ActorHeadInWaterFlag>>, class StrictExecutionContext<struct Filter<class FlagComponent<struct ActorMovementTickNeededFlag>, class FlagComponent<struct UsesECSMovementFlag>, struct UpdateWaterStateRequestComponent, class FlagComponent<struct HorseFlag>, class FlagComponent<struct MobFlag>, class FlagComponent<struct ParrotFlag>, struct VehicleComponent, class FlagComponent<struct PlayerComponentFlag>>, struct Read<struct ConstBlockSourceComponent, struct MobBodyRotationComponent, struct PassengerComponent, struct RenderRotationComponent, struct StandAnimationComponent, struct AABBShapeComponent, struct ActorHeadRotationComponent, struct ActorRotationComponent, struct OffsetsComponent, struct StateVectorComponent, struct SynchedActorDataComponent>, struct Write<>, struct AddRemove<class FlagComponent<struct ActorHeadInWaterFlag>>, struct GlobalRead<>, struct GlobalWrite<>, struct EntityFactoryT<>> &);

private:

};