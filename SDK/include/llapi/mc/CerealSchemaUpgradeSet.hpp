// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class CerealSchemaUpgradeSet {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CEREALSCHEMAUPGRADESET
public:
    class CerealSchemaUpgradeSet& operator=(class CerealSchemaUpgradeSet const &) = delete;
    CerealSchemaUpgradeSet(class CerealSchemaUpgradeSet const &) = delete;
    CerealSchemaUpgradeSet() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CEREALSCHEMAUPGRADESET
#endif
    MCAPI class std::shared_ptr<class CerealSchemaUpgrade> findNext(class SemVersion const &) const;
    MCAPI bool forEach(class std::function<bool (class std::shared_ptr<class CerealSchemaUpgrade>)>);
    MCAPI ~CerealSchemaUpgradeSet();

};