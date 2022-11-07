// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PackManifest {

#define AFTER_EXTRA
// Add Member There
public:
struct CapabilityRegisterer {
    CapabilityRegisterer() = delete;
    CapabilityRegisterer(CapabilityRegisterer const&) = delete;
    CapabilityRegisterer(CapabilityRegisterer const&&) = delete;
};

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PACKMANIFEST
public:
    class PackManifest& operator=(class PackManifest const &) = delete;
    PackManifest() = delete;
#endif

public:
    /*0*/ virtual ~PackManifest();
    /*1*/ virtual std::unique_ptr<class PackManifest> clone() const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_PACKMANIFEST
#endif
    MCAPI PackManifest(enum ManifestType);
    MCAPI PackManifest(class PackManifest const &);
    MCAPI void addLegacyModuleDependency(struct LegacyPackIdVersion const &);
    MCAPI void addModule(class ResourceInformation const &);
    MCAPI void addModuleDependency(struct ModuleIdentifier const &);
    MCAPI void addPackCapability(class gsl::basic_string_span<char const, -1>);
    MCAPI void addPackDependency(struct PackIdVersion const &);
    MCAPI void clearLegacyModuleDependencies();
    MCAPI void clearModules();
    MCAPI class ContentIdentity const & getContentIdentity() const;
    MCAPI std::vector<struct PackIdVersion> const & getDependentPackIdentities() const;
    MCAPI std::string getDescription() const;
    MCAPI enum PackManifestFormat getFormatVersion() const;
    MCAPI struct PackIdVersion const & getIdentity() const;
    MCAPI std::vector<struct LegacyPackIdVersion> const & getLegacyModuleDependencies() const;
    MCAPI class ResourceLocation const & getLocation() const;
    MCAPI enum ManifestOrigin getManifestOrigin() const;
    MCAPI class ResourceMetadata const & getMetaData() const;
    MCAPI class SemVersion const & getMinEngineVersion() const;
    MCAPI std::vector<struct ModuleIdentifier> const & getModuleDependencies() const;
    MCAPI std::vector<class ResourceInformation> const & getModules() const;
    MCAPI std::string getName() const;
    MCAPI std::string getNameForTelemetry() const;
    MCAPI enum PackManifestFormat getOriginalFormatVersion() const;
    MCAPI enum PackCategory getPackCategory() const;
    MCAPI enum PackOrigin getPackOrigin() const;
    MCAPI enum PackScope getPackScope() const;
    MCAPI class Json::Value const & getPackSettings() const;
    MCAPI unsigned __int64 getPackSize() const;
    MCAPI enum PackType getPackType() const;
    MCAPI class BaseGameVersion const & getRequiredBaseGameVersion() const;
    MCAPI bool hasClientScript() const;
    MCAPI bool hasEducationMetadata() const;
    MCAPI bool hasLegacyModuleDependencies() const;
    MCAPI bool hasModule(struct PackIdVersion const &) const;
    MCAPI bool hasPackCapability(class gsl::basic_string_span<char const, -1>) const;
    MCAPI bool hasPlugins() const;
    MCAPI bool isHidden() const;
    MCAPI bool isPlatformLocked() const;
    MCAPI bool isPremium() const;
    MCAPI bool isRestrictedPack() const;
    MCAPI bool isUsingPackDescriptionKeyword() const;
    MCAPI bool isUsingPackNameKeyword() const;
    MCAPI void serialize(enum PackManifestFormat, class Json::Value &) const;
    MCAPI void setCanBeRedownloaded(bool);
    MCAPI void setContentIdentity(class ContentIdentity const &);
    MCAPI void setDescription(std::string const &);
    MCAPI void setFormatVersion(enum PackManifestFormat);
    MCAPI void setHasClientScript();
    MCAPI void setHasEducationMetadata(bool);
    MCAPI void setHasPlugins(bool);
    MCAPI void setHidden(bool);
    MCAPI void setIdentity(struct PackIdVersion const &);
    MCAPI void setInvalidUUID();
    MCAPI void setLanguageCodesForPackKeywords(std::vector<std::string>);
    MCAPI void setLastModifiedDate(__int64);
    MCAPI void setLocalizedNameKeywords(class std::unordered_map<std::string, std::string, struct std::hash<std::string>, struct std::equal_to<std::string>, class std::allocator<struct std::pair<std::string const, std::string>>> const &);
    MCAPI void setLocation(class ResourceLocation const &);
    MCAPI void setManifestOrigin(enum ManifestOrigin const &);
    MCAPI void setMetadata(class ResourceMetadata const &);
    MCAPI void setMinEngineVersion(class SemVersion const &);
    MCAPI void setName(std::string const &);
    MCAPI void setOptionLockedState(enum TemplateLockState);
    MCAPI void setOriginalFormatVersion(enum PackManifestFormat);
    MCAPI void setPackCapabilitiesTrusted();
    MCAPI void setPackCategory(enum PackCategory);
    MCAPI void setPackOrigin(enum PackOrigin);
    MCAPI void setPackScope(enum PackScope);
    MCAPI void setPackSettings(class Json::Value const &);
    MCAPI void setPackSize(unsigned __int64);
    MCAPI void setPackType(enum PackType);
    MCAPI void setPlatformLocked(bool);
    MCAPI void setRequiredBaseGameVersion(class BaseGameVersion const &);
    MCAPI void setSourceIdentity(class ContentIdentity const &);
    MCAPI static std::string const MarioPackId;
    MCAPI static enum PackScope StringToPackScope(std::string const &);

//private:
    MCAPI void _serializeDependencies(class Json::Value &) const;
    MCAPI void _serializeHeader(class Json::Value &) const;
    MCAPI void _serializeModules(class Json::Value &) const;
    MCAPI void _serializeVersion(class Json::Value &, class SemVersion const &) const;

private:
    MCAPI static class std::unordered_map<std::string, enum PackScope, struct std::hash<std::string>, struct std::equal_to<std::string>, class std::allocator<struct std::pair<std::string const, enum PackScope>>> const STRING_TO_PACK_SCOPE;

};