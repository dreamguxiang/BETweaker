/**
 * @file  IsTamedDefinition.hpp
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
 * @brief MC structure IsTamedDefinition.
 *
 */
struct IsTamedDefinition {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ISTAMEDDEFINITION
public:
    struct IsTamedDefinition& operator=(struct IsTamedDefinition const &) = delete;
    IsTamedDefinition(struct IsTamedDefinition const &) = delete;
    IsTamedDefinition() = delete;
#endif

public:
    /**
     * @symbol ?initialize@IsTamedDefinition@@QEAAXAEAVEntityContext@@@Z
     * @hash   634695022
     */
    MCAPI void initialize(class EntityContext &);
    /**
     * @symbol ?uninitialize@IsTamedDefinition@@QEAAXAEAVEntityContext@@@Z
     * @hash   -305591476
     */
    MCAPI void uninitialize(class EntityContext &);
    /**
     * @symbol ?buildSchema@IsTamedDefinition@@SAXAEAV?$shared_ptr@V?$JsonSchemaObjectNode@VEmptyClass@JsonUtil@@UIsTamedDefinition@@@JsonUtil@@@std@@@Z
     * @hash   2134649342
     */
    MCAPI static void buildSchema(class std::shared_ptr<class JsonUtil::JsonSchemaObjectNode<class JsonUtil::EmptyClass, struct IsTamedDefinition>> &);

};