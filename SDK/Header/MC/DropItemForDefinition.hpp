// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "JsonUtil.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class DropItemForDefinition {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_DROPITEMFORDEFINITION
public:
    class DropItemForDefinition& operator=(class DropItemForDefinition const &) = delete;
    DropItemForDefinition(class DropItemForDefinition const &) = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_DROPITEMFORDEFINITION
#endif
    MCAPI DropItemForDefinition();
    MCAPI void initialize(class EntityContext &, class DropItemForGoal &);
    MCAPI static void buildSchema(std::string const &, class std::shared_ptr<class JsonUtil::JsonSchemaObjectNode<class JsonUtil::EmptyClass, class DropItemForDefinition>> &);

};