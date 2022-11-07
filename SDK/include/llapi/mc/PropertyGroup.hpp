// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"
#include "PropertyMetadata.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PropertyGroup {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PROPERTYGROUP
public:
    class PropertyGroup& operator=(class PropertyGroup const &) = delete;
    PropertyGroup(class PropertyGroup const &) = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_PROPERTYGROUP
#endif
    MCAPI PropertyGroup();
    MCAPI bool getDefaultBoolValue(unsigned __int64, class RenderParams &) const;
    MCAPI unsigned __int64 getDefaultEnumIndexValue(unsigned __int64, class RenderParams &, std::string const &) const;
    MCAPI float getDefaultFloatValue(unsigned __int64, class RenderParams &) const;
    MCAPI int getDefaultIntValue(unsigned __int64, class RenderParams &) const;
    MCAPI class ListTag getNetworkSyncPropertyDescriptionsAsListTag() const;
    MCAPI class PropertyMetadata const * getPropertyMetadata(unsigned __int64) const;
    MCAPI class PropertyMetadata const * getPropertyMetadataByString(std::string const &) const;
    MCAPI ~PropertyGroup();
    MCAPI static unsigned __int64 const MAX_ENUM_SIZE;
    MCAPI static unsigned __int64 const MAX_ENUM_VALUE_SIZE;
    MCAPI static bool isValidEnumEntry(std::string const &);
    MCAPI static class std::shared_ptr<class PropertyGroup const> loadPropertiesFromJson(class Json::Value const &, class SemVersion const &);

//private:
    MCAPI void _addBoolProperty(std::string const &, bool, bool);
    MCAPI void _addEnumIndexProperty(std::string const &, bool, unsigned __int64, std::vector<class HashedString> const &);
    MCAPI void _addFloatProperty(std::string const &, bool, float, float, float);
    MCAPI void _addIntProperty(std::string const &, bool, int, int, int);
    MCAPI void _addPropertyMetadata(std::string const &, bool, enum PropertyMetadata::ContainedType);
    MCAPI std::string const & _getFriendlyJsonTypeString(enum PropertyMetadata::ContainedType);
    MCAPI bool _loadPropertyFromJson(std::string const &, class Json::Value const &, enum MolangVersion, bool);
    MCAPI void _reserveSpaceForTypes(std::vector<unsigned __int64> const &);
    MCAPI bool _validateDataType(class Json::Value const &, enum PropertyMetadata::ContainedType);
    MCAPI static enum PropertyMetadata::ContainedType _getJsonPropertyType(class Json::Value const &);

private:

};