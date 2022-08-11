// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class TickingArea {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_TICKINGAREA
public:
    class TickingArea& operator=(class TickingArea const &) = delete;
    TickingArea(class TickingArea const &) = delete;
    TickingArea() = delete;
#endif

public:
    /*0*/ virtual ~TickingArea();
    /*1*/ virtual class mce::UUID const & getId() const;
    /*2*/ virtual std::string const & getName() const;
    /*3*/ virtual struct ActorUniqueID const & getEntityId() const;
    /*4*/ virtual bool isEntityOwned() const;
    /*5*/ virtual void __unk_vfn_5();
    /*6*/ virtual void __unk_vfn_6();
    /*7*/ virtual struct Bounds const & getBounds() const;
    /*8*/ virtual bool isAlwaysActive() const;
    /*9*/ virtual float getMaxDistToPlayers() const;
    /*10*/ virtual void __unk_vfn_10();
    /*11*/ virtual void __unk_vfn_11();
    /*12*/ virtual struct TickingAreaDescription getDescription() const;
    /*13*/ virtual enum TickingAreaLoadMode getLoadMode() const;
    /*14*/ virtual void setLoadMode(enum TickingAreaLoadMode, class LevelStorage &);
    /*15*/ virtual bool isPreloadDone() const;
    /*16*/ virtual void tick(struct Tick const &, bool);
    /*17*/ virtual void tickSeasons(class Random &);
    /*18*/ virtual void updatePosition(class Vec3 const &);
    /*19*/ virtual void updateAndCenter(class LevelStorage &, struct Tick);
    /*20*/ virtual class Actor * findOwner(unsigned char &);
    /*21*/ virtual bool entityHasBeenFound() const;
    /*22*/ virtual void setEntityFound();
    /*23*/ virtual bool isRemoved();
    /*24*/ virtual void remove(class LevelStorage &);
    /*25*/ virtual void onComponentChanged(unsigned int, float, bool, class LevelStorage &);
    /*26*/ virtual void updateBlockSourceCurrentTick(struct Tick const &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_TICKINGAREA
    MCVAPI class BlockSource & getBlockSource();
    MCVAPI class BlockSource const & getBlockSource() const;
    MCVAPI class ITickingAreaView const & getView() const;
    MCVAPI class ITickingAreaView & getView();
#endif
    MCAPI TickingArea(class Dimension &, class mce::UUID, struct Bounds const &, struct ActorUniqueID);
    MCAPI TickingArea(class Dimension &, class mce::UUID, struct Bounds const &, struct ActorUniqueID, float);
    MCAPI TickingArea(class Dimension &, class mce::UUID, std::string const &, struct Bounds const &, bool, enum TickingAreaLoadMode);

//private:
    MCAPI TickingArea(class Dimension &, class mce::UUID, std::string const &, struct ActorUniqueID, struct Bounds const &, bool, float, bool, enum TickingAreaLoadMode);
    MCAPI void _center(class LevelStorage &);
    MCAPI void _save(class LevelStorage &);

private:

};