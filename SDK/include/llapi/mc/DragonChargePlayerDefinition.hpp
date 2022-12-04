/**
 * @file  DragonChargePlayerDefinition.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "JsonUtil.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class DragonChargePlayerDefinition.
 *
 */
class DragonChargePlayerDefinition {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_DRAGONCHARGEPLAYERDEFINITION
public:
    class DragonChargePlayerDefinition& operator=(class DragonChargePlayerDefinition const &) = delete;
    DragonChargePlayerDefinition(class DragonChargePlayerDefinition const &) = delete;
#endif

public:
    /**
     * @symbol ??0DragonChargePlayerDefinition@@QEAA@XZ
     * @hash   471035287
     */
    MCAPI DragonChargePlayerDefinition();
    /**
     * @symbol ?initialize@DragonChargePlayerDefinition@@QEAAXAEAVEntityContext@@AEAVDragonChargePlayerGoal@@@Z
     * @hash   699669479
     */
    MCAPI void initialize(class EntityContext &, class DragonChargePlayerGoal &);
    /**
     * @symbol ?buildSchema@DragonChargePlayerDefinition@@SAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$shared_ptr@V?$JsonSchemaObjectNode@VEmptyClass@JsonUtil@@VDragonChargePlayerDefinition@@@JsonUtil@@@3@@Z
     * @hash   -2136777641
     */
    MCAPI static void buildSchema(std::string const &, class std::shared_ptr<class JsonUtil::JsonSchemaObjectNode<class JsonUtil::EmptyClass, class DragonChargePlayerDefinition>> &);

};