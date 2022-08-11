// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "reflection.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class CerealItemComponentFactory {

#define AFTER_EXTRA
// Add Member There
public:
struct Constructor {
    Constructor() = delete;
    Constructor(Constructor const&) = delete;
    Constructor(Constructor const&&) = delete;
};

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CEREALITEMCOMPONENTFACTORY
public:
    class CerealItemComponentFactory& operator=(class CerealItemComponentFactory const &) = delete;
    CerealItemComponentFactory(class CerealItemComponentFactory const &) = delete;
    CerealItemComponentFactory() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CEREALITEMCOMPONENTFACTORY
#endif
    MCAPI static void addAllComponentUpgrades(class CerealDocumentUpgrader &);
    MCAPI static class std::shared_ptr<class ItemComponent> constructItemComponent(std::string const &);
    MCAPI static class ComponentItem * getItemContext();
    MCAPI static bool isRegisteredComponent(std::string const &);
    MCAPI static void registerComponentUpgrade(class CerealDocumentUpgrader &, class std::shared_ptr<class CerealSchemaUpgrade>);
    MCAPI static void resetItemContext();
    MCAPI static void setItemContext(class ComponentItem *);

//private:
    MCAPI static void _bindAllComponentSchemas(class reflection::SchemaFactory &, class SemVersion const &);

private:
    MCAPI static class ComponentItem * mItemContext;
    MCAPI static class std::unordered_map<std::string, struct CerealItemComponentFactory::Constructor, struct std::hash<std::string>, struct std::equal_to<std::string>, class std::allocator<struct std::pair<std::string const, struct CerealItemComponentFactory::Constructor>>> mRegisteredComponents;

};