// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

namespace ActorPropertyUtils {

#define AFTER_EXTRA

#undef AFTER_EXTRA
    MCAPI void _applyValueChangeFromTag(class PropertyComponent &, class PropertyGroup const &, class PropertyMetadata const &, class Tag const &);
    MCAPI bool _checkAndQueueBoolValue(class PropertyGroup const &, unsigned __int64, class ActorDefinitionDiffList *, bool);
    MCAPI bool _checkAndQueueEnumIndexValueByHash(class PropertyGroup const &, unsigned __int64, unsigned __int64, class ActorDefinitionDiffList *, unsigned __int64);
    MCAPI bool _checkAndQueueFloatValue(class PropertyGroup const &, unsigned __int64, unsigned __int64, class ActorDefinitionDiffList *, float);
    MCAPI bool _checkAndQueueIntValue(class PropertyGroup const &, unsigned __int64, unsigned __int64, class ActorDefinitionDiffList *, int);
    MCAPI void addPendingEventResponseChange(class PropertyComponent const &, class Actor &, class HashedString const &, struct MolangScriptArg const &, std::string const &);
    MCAPI void ingestPropertyUpdate(class PropertyComponent &, class CompoundTag const &);

};