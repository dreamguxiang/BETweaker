// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "JsonUtil.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class HarvestFarmBlockDefinition {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_HARVESTFARMBLOCKDEFINITION
public:
    class HarvestFarmBlockDefinition& operator=(class HarvestFarmBlockDefinition const &) = delete;
    HarvestFarmBlockDefinition(class HarvestFarmBlockDefinition const &) = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_HARVESTFARMBLOCKDEFINITION
#endif
    MCAPI HarvestFarmBlockDefinition();
    MCAPI void initialize(class EntityContext &, class HarvestFarmBlockGoal &);
    MCAPI static void buildSchema(std::string const &, class std::shared_ptr<class JsonUtil::JsonSchemaObjectNode<class JsonUtil::EmptyClass, class HarvestFarmBlockDefinition>> &);

};