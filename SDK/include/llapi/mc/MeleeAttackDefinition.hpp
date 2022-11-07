// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "JsonUtil.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class MeleeAttackDefinition {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MELEEATTACKDEFINITION
public:
    class MeleeAttackDefinition& operator=(class MeleeAttackDefinition const &) = delete;
    MeleeAttackDefinition(class MeleeAttackDefinition const &) = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_MELEEATTACKDEFINITION
#endif
    MCAPI MeleeAttackDefinition();
    MCAPI void initialize(class EntityContext &, class MeleeAttackGoal &);
    MCAPI static void buildSchema(std::string const &, class std::shared_ptr<class JsonUtil::JsonSchemaObjectNode<class JsonUtil::EmptyClass, class MeleeAttackDefinition>> &);

};