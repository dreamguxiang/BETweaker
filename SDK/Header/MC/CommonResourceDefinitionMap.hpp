// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class CommonResourceDefinitionMap {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_COMMONRESOURCEDEFINITIONMAP
public:
    class CommonResourceDefinitionMap& operator=(class CommonResourceDefinitionMap const &) = delete;
    CommonResourceDefinitionMap(class CommonResourceDefinitionMap const &) = delete;
#endif

public:
    MCAPI CommonResourceDefinitionMap();
    MCAPI std::vector<struct NamedMolangScript> const & getAnimateScriptArray() const;
    MCAPI class std::unordered_map<class HashedString, class ActorAnimationControllerPtr, struct std::hash<class HashedString>, struct std::equal_to<class HashedString>, class std::allocator<struct std::pair<class HashedString const, class ActorAnimationControllerPtr>>> const & getAnimationControllers() const;
    MCAPI class std::unordered_map<class HashedString, class ActorSkeletalAnimationPtr, struct std::hash<class HashedString>, struct std::equal_to<class HashedString>, class std::allocator<struct std::pair<class HashedString const, class ActorSkeletalAnimationPtr>>> const & getAnimations() const;
    MCAPI std::vector<struct MolangVariableSettings> const & getVariableSettings() const;
    MCAPI bool isCommonResourceDefinitionMapEmpty() const;
    MCAPI void mergeActorAnimateScriptArray(std::vector<struct NamedMolangScript> const &);
    MCAPI void mergeAnimation(class HashedString const &, class ActorSkeletalAnimationPtr);
    MCAPI void mergeAnimationController(class HashedString const &, class ActorAnimationControllerPtr);

protected:

private:
    MCAPI static class std::recursive_mutex & _getAnimationResourceDefinitionLock();

};