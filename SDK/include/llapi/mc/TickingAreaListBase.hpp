// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class TickingAreaListBase {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_TICKINGAREALISTBASE
public:
    class TickingAreaListBase& operator=(class TickingAreaListBase const &) = delete;
    TickingAreaListBase(class TickingAreaListBase const &) = delete;
    TickingAreaListBase() = delete;
#endif

public:
    /*0*/ virtual ~TickingAreaListBase();
    /*1*/ virtual bool removeDistantEntityAreasAndCheckForRemoved(std::vector<class Vec3> const &, class std::function<void (class ITickingArea const &)>, class LevelStorage &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_TICKINGAREALISTBASE
#endif
    MCAPI void add(std::unique_ptr<class ITickingArea>);
    MCAPI unsigned int countEntityTickingAreas() const;
    MCAPI unsigned int countStandaloneTickingAreas() const;
    MCAPI void destroyAreas();
    MCAPI bool empty() const;
    MCAPI std::vector<class std::shared_ptr<class ITickingArea>> findStandaloneAreasContaining(class BlockPos const &);
    MCAPI std::vector<class std::shared_ptr<class ITickingArea>> findStandaloneAreasNamed(std::string const &) const;
    MCAPI class std::shared_ptr<class ITickingArea> getAreaFor(struct ActorUniqueID const &) const;
    MCAPI std::vector<class std::shared_ptr<class ITickingArea>> const & getAreas() const;
    MCAPI std::vector<struct TickingAreaDescription> getStandaloneTickingAreaDescriptions() const;
    MCAPI bool hasTickingAreaNamed(std::string const &) const;
    MCAPI bool isPreloadDone() const;
    MCAPI void processRemoves();
    MCAPI void processUpdates(class LevelStorage &, struct Tick);
    MCAPI std::vector<struct TickingAreaDescription> removeAllStandaloneAreas(class LevelStorage &);
    MCAPI std::vector<struct TickingAreaDescription> removeAreas(std::vector<class std::shared_ptr<class ITickingArea>> const &, class LevelStorage &);
    MCAPI void tick(struct Tick const &);
    MCAPI void tickSeasons(class Random &);
    MCAPI void updateBlockSourceCurrentTick(struct Tick const &);

//protected:
    MCAPI bool _shouldRemoveArea(unsigned int, std::vector<class Vec3> const &) const;

protected:

};