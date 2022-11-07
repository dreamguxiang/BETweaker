// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "JsonUtil.hpp"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class AngerLevelDefinition {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ANGERLEVELDEFINITION
public:
    class AngerLevelDefinition& operator=(class AngerLevelDefinition const &) = delete;
    AngerLevelDefinition(class AngerLevelDefinition const &) = delete;
    AngerLevelDefinition() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ANGERLEVELDEFINITION
#endif
    MCAPI void addOnIncreaseSoundDefinition(class SoundDefinition const &);
    MCAPI void initialize(class EntityContext &, class AngerLevelComponent &);
    MCAPI static void buildSchema(class std::shared_ptr<class JsonUtil::JsonSchemaObjectNode<class JsonUtil::EmptyClass, class AngerLevelDefinition>> &);

};