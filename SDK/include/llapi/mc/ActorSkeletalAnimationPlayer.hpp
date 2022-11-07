// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ActorSkeletalAnimationPlayer {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ACTORSKELETALANIMATIONPLAYER
public:
    class ActorSkeletalAnimationPlayer& operator=(class ActorSkeletalAnimationPlayer const &) = delete;
    ActorSkeletalAnimationPlayer(class ActorSkeletalAnimationPlayer const &) = delete;
    ActorSkeletalAnimationPlayer() = delete;
#endif

public:
    /*0*/ virtual ~ActorSkeletalAnimationPlayer();
    /*1*/ virtual void applyToPose(class RenderParams &, class std::unordered_map<enum SkeletalHierarchyIndex, std::vector<class BoneOrientation>, struct std::hash<enum SkeletalHierarchyIndex>, struct std::equal_to<enum SkeletalHierarchyIndex>, class std::allocator<struct std::pair<enum SkeletalHierarchyIndex const, std::vector<class BoneOrientation>>>> &, float);
    /*2*/ virtual void resetAnimation();
    /*3*/ virtual void buildBoneToPartMapping(class AnimationComponent &);
    /*4*/ virtual void bindParticleEffects(class std::unordered_map<class HashedString, class HashedString, struct std::hash<class HashedString>, struct std::equal_to<class HashedString>, class std::allocator<struct std::pair<class HashedString const, class HashedString>>> const &);
    /*5*/ virtual void bindSoundEffects(class std::unordered_map<class HashedString, std::string, struct std::hash<class HashedString>, struct std::equal_to<class HashedString>, class std::allocator<struct std::pair<class HashedString const, std::string>>> const &);
    /*6*/ virtual bool hasAnimationFinished() const;
    /*7*/ virtual class std::shared_ptr<class ActorAnimationPlayer> findAnimation(class HashedString const &);
    /*8*/ virtual enum ActorAnimationType getAnimationType() const;
    /*9*/ virtual class HashedString const & getRawName() const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ACTORSKELETALANIMATIONPLAYER
#endif
    MCAPI ActorSkeletalAnimationPlayer(class HashedString const &, class ActorSkeletalAnimationPtr, class AnimationComponent &, class ExpressionNode const &);

};