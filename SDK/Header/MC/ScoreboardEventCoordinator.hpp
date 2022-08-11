// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ScoreboardEventCoordinator {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SCOREBOARDEVENTCOORDINATOR
public:
    class ScoreboardEventCoordinator& operator=(class ScoreboardEventCoordinator const &) = delete;
    ScoreboardEventCoordinator(class ScoreboardEventCoordinator const &) = delete;
    ScoreboardEventCoordinator() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SCOREBOARDEVENTCOORDINATOR
#endif
    MCAPI void sendOnObjectiveAdded(std::string const &);
    MCAPI void sendOnObjectiveRemoved(std::string const &);
    MCAPI void sendOnScoreChanged(struct ScoreboardId const &, std::string const &, int);
    MCAPI void sendOnScoreboardIdentityRemoved(struct ScoreboardId const &);

};