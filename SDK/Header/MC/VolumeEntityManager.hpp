// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class VolumeEntityManager {

#define AFTER_EXTRA
// Add Member There
public:
struct VolumeEntityDefinition {
    VolumeEntityDefinition() = delete;
    VolumeEntityDefinition(VolumeEntityDefinition const&) = delete;
    VolumeEntityDefinition(VolumeEntityDefinition const&&) = delete;
};

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_VOLUMEENTITYMANAGER
public:
    class VolumeEntityManager& operator=(class VolumeEntityManager const &) = delete;
    VolumeEntityManager(class VolumeEntityManager const &) = delete;
    VolumeEntityManager() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_VOLUMEENTITYMANAGER
#endif
    MCAPI unsigned __int64 getVolumeInstanceCount() const;
    MCAPI std::vector<class OwnerPtrT<struct EntityRefTraits>> const & getVolumeInstances(class AutomaticID<class Dimension, int>) const;
    MCAPI static bool isTriggerVolumesEnabled;
    MCAPI static void registerComponentNetRelevancy(class ComponentNetRelevancyRegistry &);

//protected:
    MCAPI VolumeEntityManager(class StackRefResultT<struct EntityRegistryRefTraits>);
    MCAPI class OwnerPtrT<struct EntityRefTraits> _createVolumeEntity(class DefinitionInstanceGroup const &);

protected:

};