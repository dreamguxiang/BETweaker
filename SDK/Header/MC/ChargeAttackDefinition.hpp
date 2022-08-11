// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "JsonUtil.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ChargeAttackDefinition {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CHARGEATTACKDEFINITION
public:
    class ChargeAttackDefinition& operator=(class ChargeAttackDefinition const &) = delete;
    ChargeAttackDefinition(class ChargeAttackDefinition const &) = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CHARGEATTACKDEFINITION
#endif
    MCAPI ChargeAttackDefinition();
    MCAPI void initialize(class EntityContext &, class ChargeAttackGoal &);
    MCAPI static void buildSchema(std::string const &, class std::shared_ptr<class JsonUtil::JsonSchemaObjectNode<class JsonUtil::EmptyClass, class ChargeAttackDefinition>> &);

};