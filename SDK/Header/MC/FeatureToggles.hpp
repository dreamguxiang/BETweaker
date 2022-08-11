// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class FeatureToggles {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_FEATURETOGGLES
public:
    class FeatureToggles& operator=(class FeatureToggles const &) = delete;
    FeatureToggles(class FeatureToggles const &) = delete;
    FeatureToggles() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_FEATURETOGGLES
#endif
    MCAPI FeatureToggles(class AppPlatform &);
    MCAPI class Option * get(enum FeatureOptionID);
    MCAPI bool isEnabled(enum FeatureOptionID) const;

//private:
    MCAPI class std::function<void (class Option &)> _getDisableIfOtherOptionDisabledSetupCallback(enum FeatureOptionID) const;
    MCAPI class std::function<void (class Option &)> _getDisabledIfOptionExpectationsNotMetSetupCallback(std::vector<enum FeatureOptionID>, std::vector<enum FeatureOptionID>);
    MCAPI class std::function<void (class Option &)> _getDisabledIfOtherOptionsEnabledSetupCallback(std::vector<enum FeatureOptionID>);
    MCAPI class std::function<void (bool &)> _getLockIfInGameCallback();
    MCAPI class std::function<void (bool &)> _getLockIfInGameOrOptionExpectationsNotMetLockCallback(std::vector<enum FeatureOptionID>, std::vector<enum FeatureOptionID>);
    MCAPI class std::function<void (bool &)> _getLockIfOtherOptionDisabledLockCallback(enum FeatureOptionID) const;
    MCAPI void _initialize(class AppPlatform &);
    MCAPI void _registerFeature(enum FeatureOptionTabID, enum FeatureOptionID, std::string const &, std::string const &, bool, enum FeatureOptionID, class std::function<void (class Option &)>, class std::function<void (bool &)>);
    MCAPI void _registerFeatures();
    MCAPI void _setupDependencies();

private:
    MCAPI static std::unique_ptr<class FeatureToggles> mFeatureToggles;

};