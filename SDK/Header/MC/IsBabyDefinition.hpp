// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "JsonUtil.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct IsBabyDefinition {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ISBABYDEFINITION
public:
    struct IsBabyDefinition& operator=(struct IsBabyDefinition const &) = delete;
    IsBabyDefinition(struct IsBabyDefinition const &) = delete;
    IsBabyDefinition() = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ISBABYDEFINITION
#endif
    MCAPI void initialize(class EntityContext &);
    MCAPI void uninitialize(class EntityContext &);
    MCAPI static void buildSchema(class std::shared_ptr<class JsonUtil::JsonSchemaObjectNode<class JsonUtil::EmptyClass, struct IsBabyDefinition>> &);

};