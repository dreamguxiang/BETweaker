// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "JsonUtil.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class MoveTowardsDwellingRestrictionDefinition {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MOVETOWARDSDWELLINGRESTRICTIONDEFINITION
public:
    class MoveTowardsDwellingRestrictionDefinition& operator=(class MoveTowardsDwellingRestrictionDefinition const &) = delete;
    MoveTowardsDwellingRestrictionDefinition(class MoveTowardsDwellingRestrictionDefinition const &) = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_MOVETOWARDSDWELLINGRESTRICTIONDEFINITION
#endif
    MCAPI MoveTowardsDwellingRestrictionDefinition();
    MCAPI static void buildSchema(std::string const &, class std::shared_ptr<class JsonUtil::JsonSchemaObjectNode<class JsonUtil::EmptyClass, class MoveTowardsDwellingRestrictionDefinition>> &);

};