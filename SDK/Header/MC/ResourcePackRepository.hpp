// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Core.hpp"
#include "Bedrock.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ResourcePackRepository {

#define AFTER_EXTRA
// Add Member There
public:
struct KnownPackContainer {
    KnownPackContainer() = delete;
    KnownPackContainer(KnownPackContainer const&) = delete;
    KnownPackContainer(KnownPackContainer const&&) = delete;
};

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_RESOURCEPACKREPOSITORY
public:
    class ResourcePackRepository& operator=(class ResourcePackRepository const &) = delete;
    ResourcePackRepository(class ResourcePackRepository const &) = delete;
    ResourcePackRepository() = delete;
#endif

public:
    /*0*/ virtual ~ResourcePackRepository();
    /*1*/ virtual void getResourcePacksByPackId(std::vector<struct PackInstanceId> const &, std::vector<class PackInstance> &) const;
    /*2*/ virtual class ResourcePack * getResourcePackForPackId(struct PackIdVersion const &) const;
    /*3*/ virtual class ResourcePack * getResourcePackByUUID(class mce::UUID const &) const;
    /*4*/ virtual class ResourcePack * getResourcePackForPackIdOwned(struct PackIdVersion const &) const;
    /*5*/ virtual class ResourcePack * getResourcePackSatisfiesPackId(struct PackIdVersion const &, bool) const;
    /*6*/ virtual class ResourcePack * getResourcePackContainingModule(struct PackIdVersion const &) const;
    /*7*/ virtual class ResourcePack * getResourcePackInPath(class Core::Path const &) const;
    /*8*/ virtual bool isResourcePackLoaded(struct PackIdVersion const &, enum PackOrigin const &);
    /*9*/ virtual class PackSourceReport const * getPackLoadingReport() const;
    /*10*/ virtual class ResourcePack * getVanillaPack() const;
    /*11*/ virtual class ResourcePack * getChemistryPack() const;
    /*12*/ virtual class ResourcePack * getChemistryServerPack() const;
    /*13*/ virtual bool setServicePacks(std::vector<struct PackIdVersion>);
    /*14*/ virtual void addServicePacksToStack(class ResourcePackStack &) const;
    /*15*/ virtual void addCachedResourcePacks(class std::unordered_map<class ContentIdentity, std::string, struct std::hash<class ContentIdentity>, struct std::equal_to<class ContentIdentity>, class std::allocator<struct std::pair<class ContentIdentity const, std::string>>> const *);
    /*16*/ virtual void addWorldResourcePacks(class Core::Path const &);
    /*17*/ virtual void addPremiumWorldTemplateResourcePacks(class Core::Path const &, class ContentIdentity const &);
    /*18*/ virtual void removePacksLoadedFromCache();
    /*19*/ virtual void removePacksLoadedFromWorld();
    /*20*/ virtual class Core::PathBuffer<std::string> const getResourcePacksPath() const;
    /*21*/ virtual class Core::PathBuffer<std::string> const getBehaviorPacksPath() const;
    /*22*/ virtual class Core::PathBuffer<std::string> const getSkinPacksPath() const;
    /*23*/ virtual class Core::PathBuffer<std::string> const getDevelopmentResourcePacksPath() const;
    /*24*/ virtual class Core::PathBuffer<std::string> const getDevelopmentBehaviorPacksPath() const;
    /*25*/ virtual class Core::PathBuffer<std::string> const getDevelopmentSkinPacksPath() const;
    /*26*/ virtual class Core::PathBuffer<std::string> const getTreatmentPacksPath() const;
    /*27*/ virtual class Core::PathBuffer<std::string> const getKnownPacksPath(enum KnownPackType) const;
    /*28*/ virtual class Core::PathBuffer<std::string> const getKnownValidPacksPath() const;
    /*29*/ virtual class Core::PathBuffer<std::string> const getKnownInvalidPacksPath() const;
    /*30*/ virtual void refreshPacks();
    /*31*/ virtual void requestReloadUserPacks();
    /*32*/ virtual void requestReloadDynamicPackagePacks();
    /*33*/ virtual class gsl::not_null<class Bedrock::NonOwnerPointer<class IContentKeyProvider const>> getKeyProvider() const;
    /*34*/ virtual class PackManifestFactory & getPackManifestFactory();
    /*35*/ virtual class PackSettingsFactory & getPackSettingsFactory() const;
    /*36*/ virtual class PackSourceFactory & getPackSourceFactory();
    /*37*/ virtual std::vector<class ResourcePack *> getPacksByResourceLocation(enum PackOrigin) const;
    /*38*/ virtual std::vector<class ResourcePack *> getPacksByType(enum PackType) const;
    /*39*/ virtual void addKnownPackFromImport(class PackManifest const &);
    /*40*/ virtual void addInvalidPack(class ResourceLocation const &, enum PackType);
    /*41*/ virtual std::vector<class ResourceLocation> const & getInvalidPacks(enum PackType) const;
    /*42*/ virtual std::vector<class ResourceLocation> getInvalidPacks(struct InvalidPacksFilterGroup const &) const;
    /*43*/ virtual void deletePack(class ResourceLocation const &);
    /*44*/ virtual void deletePackFiles(class ResourceLocation const &);
    /*45*/ virtual void postDeletePack(class ResourceLocation const &);
    /*46*/ virtual void untrackInvalidPack(class ResourceLocation const &);
    /*47*/ virtual void registerResourcePackRemovedCallback(void *, class std::function<void (class ResourcePack *)>);
    /*48*/ virtual void unregisterResourcePackRemovedCallback(void *);
    /*49*/ virtual bool isInitialized();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_RESOURCEPACKREPOSITORY
#endif
    MCAPI ResourcePackRepository(class IMinecraftEventing &, class PackManifestFactory &, class gsl::not_null<class Bedrock::NonOwnerPointer<class IContentAccessibilityProvider>> const &, class gsl::not_null<class Bedrock::NonOwnerPointer<class Core::FilePathManager>> const &, class PackSourceFactory &, bool);
    MCAPI static class mce::UUID const CHEMISTRY_PACK_UUID;
    MCAPI static class mce::UUID const CHEMISTRY_SERVER_PACK_UUID;

//private:
    MCAPI void _detectKnownPacksChange(struct ResourcePackRepository::KnownPackContainer &, struct ResourcePackRepository::KnownPackContainer const &, enum KnownPackType);
    MCAPI void _findVanillaPacks();
    MCAPI void _initialize();
    MCAPI void _initializeCachedPackSource();
    MCAPI void _initializePackSource();
    MCAPI void _initializeWorldPackSource();
    MCAPI void _loadLastKnownUserPacks(struct ResourcePackRepository::KnownPackContainer &, enum KnownPackType);
    MCAPI void _loadPacks(bool);
    MCAPI bool _packExists(class mce::UUID const &, class SemVersion const &, enum PackOrigin) const;
    MCAPI void _reloadUserPacks();
    MCAPI bool _removePack(class ResourceLocation const &, bool);
    MCAPI void _saveKnownUserPacks(struct ResourcePackRepository::KnownPackContainer &, enum KnownPackType);
    MCAPI void _triggerRemoveResourcePackCallback(class ResourcePack *);

private:

};