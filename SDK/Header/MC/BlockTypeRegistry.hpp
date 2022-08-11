// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class BlockTypeRegistry {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLOCKTYPEREGISTRY
public:
    class BlockTypeRegistry& operator=(class BlockTypeRegistry const &) = delete;
    BlockTypeRegistry(class BlockTypeRegistry const &) = delete;
    BlockTypeRegistry() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_BLOCKTYPEREGISTRY
#endif
    MCAPI static unsigned __int64 computeBlockTypeRegistryChecksum(class BaseGameVersion const &);
    MCAPI static void forEachBlock(class std::function<bool (class BlockLegacy const &)>);
    MCAPI static class Block const & getDefaultBlockState(class HashedString const &, bool);
    MCAPI static class StackRefResultT<struct EntityRegistryRefTraits> getEntityRegistry();
    MCAPI static void initBlockEntities(class Experiments const &);
    MCAPI static void initEntityRegistry();
    MCAPI static bool isBlockDataDriven(std::string const &);
    MCAPI static class BlockTypeRegistryReadLock lockAgainstRegistryModifications();
    MCAPI static class BlockTypeRegistryModificationsLock lockForRegistryModifications();
    MCAPI static class WeakPtr<class BlockLegacy> lookupByName(class HashedString const &, bool);
    MCAPI static void prepareBlocks(unsigned int);
    MCAPI static void registerAlias(class HashedString const &, class HashedString const &);
    MCAPI static void unregisterBlock(class HashedString const &);
    MCAPI static void unregisterBlocks();

//private:

private:
    MCAPI static class std::unordered_map<class HashedString, class HashedString, struct std::hash<class HashedString>, struct std::equal_to<class HashedString>, class std::allocator<struct std::pair<class HashedString const, class HashedString>>> mBlockAliasLookupMap;
    MCAPI static class std::map<class HashedString, class SharedPtr<class BlockLegacy>, struct std::less<class HashedString>, class std::allocator<struct std::pair<class HashedString const, class SharedPtr<class BlockLegacy>>>> mBlockLookupMap;
    MCAPI static class OwnerPtrT<struct EntityRegistryRefTraits> mEntities;
    MCAPI static class std::set<std::string, struct std::less<std::string>, class std::allocator<std::string>> mKnownNamespaces;
    MCAPI static class std::shared_ptr<class BlockTypeRegistryRWLock> mRWLock;

};