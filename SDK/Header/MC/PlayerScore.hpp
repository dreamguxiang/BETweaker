// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

struct PlayerScore {

#define AFTER_EXTRA

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PLAYERSCORE
public:
    struct PlayerScore& operator=(struct PlayerScore const &) = delete;
    PlayerScore(struct PlayerScore const &) = delete;
    PlayerScore() = delete;
#endif

public:
    MCAPI PlayerScore(struct ScoreboardId const &, int);
    MCAPI struct ScoreboardId const & getId() const;

protected:

private:

};