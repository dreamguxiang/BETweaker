// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"
#include "CommandOrigin.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class BlockCommandOrigin : public CommandOrigin {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLOCKCOMMANDORIGIN
public:
    class BlockCommandOrigin& operator=(class BlockCommandOrigin const &) = delete;
    BlockCommandOrigin(class BlockCommandOrigin const &) = delete;
    BlockCommandOrigin() = delete;
#endif

public:
    /*0*/ virtual ~BlockCommandOrigin();
    /*1*/ virtual std::string const & getRequestId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual class BlockPos getBlockPosition() const;
    /*4*/ virtual class Vec3 getWorldPosition() const;
    /*5*/ virtual class std::optional<class Vec2> getRotation() const;
    /*6*/ virtual class Level * getLevel() const;
    /*7*/ virtual class Dimension * getDimension() const;
    /*8*/ virtual class Actor * getEntity() const;
    /*9*/ virtual enum CommandPermissionLevel getPermissionsLevel();
    /*10*/ virtual std::unique_ptr<class CommandOrigin> clone() const;
    /*17*/ virtual bool canUseCommandsWithoutCheatsEnabled();
    /*18*/ virtual bool isSelectorExpansionAllowed();
    /*23*/ virtual enum CommandOriginType getOriginType();
    /*29*/ virtual class CompoundTag serialize() const;
    /*30*/ virtual bool isValid();
    /*32*/ virtual class BaseCommandBlock * _getBaseCommandBlock(class BlockSource &) const;
    /*33*/ virtual class CommandBlockActor * _getBlockEntity(class BlockSource &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_BLOCKCOMMANDORIGIN
#endif
    MCAPI BlockCommandOrigin(class BlockSource &, class BlockPos const &);
    MCAPI BlockCommandOrigin(class Level &, class AutomaticID<class Dimension, int>, std::string const &, class BlockPos const &);
    MCAPI static std::unique_ptr<class BlockCommandOrigin> load(class CompoundTag const &, class Level &);

//protected:
    MCAPI std::string _getName(class BlockSource &) const;

protected:

};