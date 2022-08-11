// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "JsonUtil.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ControlledByPlayerDefinition {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CONTROLLEDBYPLAYERDEFINITION
public:
    class ControlledByPlayerDefinition& operator=(class ControlledByPlayerDefinition const &) = delete;
    ControlledByPlayerDefinition(class ControlledByPlayerDefinition const &) = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CONTROLLEDBYPLAYERDEFINITION
#endif
    MCAPI ControlledByPlayerDefinition();
    MCAPI void initialize(class EntityContext &, class ControlledByPlayerGoal &);
    MCAPI static void buildSchema(std::string const &, class std::shared_ptr<class JsonUtil::JsonSchemaObjectNode<class JsonUtil::EmptyClass, class ControlledByPlayerDefinition>> &);

};