// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class DynamicProperties {

#define AFTER_EXTRA

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_DYNAMICPROPERTIES
public:
    class DynamicProperties& operator=(class DynamicProperties const &) = delete;
    DynamicProperties(class DynamicProperties const &) = delete;
    DynamicProperties() = delete;
#endif


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_DYNAMICPROPERTIES
public:
#endif
    MCAPI void deserialize(class CompoundTag const &);
    MCAPI unsigned __int64 getCollectionCount() const;
    MCAPI class std::variant<float, bool, std::string> * getDynamicProperty(std::string const &, std::string const &);
    MCAPI bool removeDynamicProperty(std::string const &, std::string const &);
    MCAPI std::unique_ptr<class CompoundTag> serialize() const;
    MCAPI void setDynamicProperty(std::string const &, class std::variant<float, bool, std::string> const &, std::string const &);
    MCAPI void writeToLevelStorage(class LevelStorage &);
    MCAPI ~DynamicProperties();
    MCAPI static std::string const STORAGE_TAG;
    MCAPI static std::unique_ptr<class DynamicProperties> readFromLevelStorage(class LevelStorage &);
    MCAPI static std::string validateDynamicProperty(struct DynamicPropertyDefinition const *, std::string const &, class std::variant<float, bool, std::string> const *);


};