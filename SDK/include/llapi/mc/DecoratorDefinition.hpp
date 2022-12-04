/**
 * @file  DecoratorDefinition.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class DecoratorDefinition.
 *
 */
class DecoratorDefinition {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_DECORATORDEFINITION
public:
    class DecoratorDefinition& operator=(class DecoratorDefinition const &) = delete;
    DecoratorDefinition(class DecoratorDefinition const &) = delete;
    DecoratorDefinition() = delete;
#endif

public:
    /**
     * @symbol ?get@DecoratorDefinition@@QEBAPEBVBehaviorDefinition@@XZ
     * @hash   -576872497
     */
    MCAPI class BehaviorDefinition const * get() const;

//protected:
    /**
     * @symbol ?_decoratorLoadChildBehavior@DecoratorDefinition@@KA?AV?$unique_ptr@VBehaviorDefinition@@U?$default_delete@VBehaviorDefinition@@@std@@@std@@VValue@Json@@AEBVBehaviorFactory@@VBehaviorTreeDefinitionPtr@@@Z
     * @hash   -1981857211
     */
    MCAPI static std::unique_ptr<class BehaviorDefinition> _decoratorLoadChildBehavior(class Json::Value, class BehaviorFactory const &, class BehaviorTreeDefinitionPtr);

protected:

};