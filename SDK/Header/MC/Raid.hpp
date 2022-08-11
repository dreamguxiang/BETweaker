// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class Raid {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_RAID
public:
    class Raid& operator=(class Raid const &) = delete;
    Raid(class Raid const &) = delete;
    Raid() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_RAID
#endif
    MCAPI Raid(int, int, int, int, enum Difficulty, unsigned char, class std::function<bool (unsigned __int64, class Vec3 &)> &&, class std::function<bool (unsigned __int64, class Vec3, unsigned char, class std::unordered_set<struct ActorUniqueID, struct std::hash<struct ActorUniqueID>, struct std::equal_to<struct ActorUniqueID>, class std::allocator<struct ActorUniqueID>> &)> &&, class std::function<bool (struct ActorUniqueID const &)> &&, class std::function<bool (void)> &&);
    MCAPI void addAdditionalSaveData(class CompoundTag &) const;
    MCAPI void addPlayerToHeroList(class Actor const &);
    MCAPI void appendDebugInfo(std::string &) const;
    MCAPI float getBossBarFilledFraction() const;
    MCAPI unsigned __int64 getRemainingRaiders() const;
    MCAPI void readAdditionalSaveData(class CompoundTag const &);
    MCAPI void tick();
    MCAPI ~Raid();
    MCAPI static class Vec3 const INVALID_SPAWN_POINT;

//private:
    MCAPI float _getTotalRaiderHealth() const;
    MCAPI void _tickGroupInPlay();

private:
    MCAPI static unsigned char const NUM_GROUPS_ON_EASY;
    MCAPI static unsigned char const NUM_GROUPS_ON_HARD;
    MCAPI static unsigned char const NUM_GROUPS_ON_NORMAL;

};