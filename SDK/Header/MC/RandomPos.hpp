// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class RandomPos {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_RANDOMPOS
public:
    class RandomPos& operator=(class RandomPos const &) = delete;
    RandomPos(class RandomPos const &) = delete;
    RandomPos() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_RANDOMPOS
#endif
    MCAPI static bool getPos(class Vec3 &, class Mob &, int, int, int, enum SolidityCheckType);
    MCAPI static bool getPosAvoid(class Vec3 &, class Mob &, int, int, class Vec3 const &, enum SolidityCheckType, int);
    MCAPI static bool getPosInDirection(class Vec3 &, class Mob &, int, int, int, bool, bool, class Vec3 *, struct IntRange const &, int, enum SolidityCheckType);
    MCAPI static bool getPosTowards(class Random &, class Vec3 &, class Mob &, int, int, class Vec3 const &);
    MCAPI static bool getPosTowards(class Vec3 &, class Mob &, int, int, class Vec3 const &);
    MCAPI static bool getSpawnPos(class BlockSource &, class Random &, class Vec3 &, int, int, int);

//private:
    MCAPI static bool generateRandomPos(class Randomize &, class Vec3 &, class Mob &, int, int, int, class Vec3 const *, bool, bool, struct IntRange const &, int, enum SolidityCheckType);
    MCAPI static bool generateRandomPos(class Vec3 &, class Mob &, int, int, class Vec3 const *, bool, bool, int, enum SolidityCheckType);
    MCAPI static bool snapToGround(class BlockPos &, class Mob &, int, struct IntRange const &, enum SolidityCheckType);
    MCAPI static bool snapToGround(class BlockPos &, int, int, int, class std::function<bool (class BlockPos &)>);
    MCAPI static bool snapToGround(class BlockPos &, int, int, class std::function<bool (class BlockPos &)>);
    MCAPI static bool spawnSnapToGround(class BlockSource &, class BlockPos &, float, int);

private:

};