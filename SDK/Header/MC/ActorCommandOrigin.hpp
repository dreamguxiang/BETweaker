// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"
#include "CommandOrigin.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ActorCommandOrigin : public CommandOrigin {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ACTORCOMMANDORIGIN
public:
    class ActorCommandOrigin& operator=(class ActorCommandOrigin const &) = delete;
    ActorCommandOrigin(class ActorCommandOrigin const &) = delete;
    ActorCommandOrigin() = delete;
#endif


public:
    /*0*/ virtual ~ActorCommandOrigin();
    /*1*/ virtual std::string const & getRequestId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual class BlockPos getBlockPosition() const;
    /*4*/ virtual class Vec3 getWorldPosition() const;
    /*5*/ virtual class std::optional<class Vec2> getRotation() const;
    /*6*/ virtual class Level * getLevel() const;
    /*7*/ virtual class Dimension * getDimension() const;
    /*8*/ virtual class Actor * getEntity() const;
    /*9*/ virtual enum CommandPermissionLevel getPermissionsLevel() const;
    /*10*/ virtual std::unique_ptr<class CommandOrigin> clone() const;
    /*18*/ virtual bool isSelectorExpansionAllowed() const;
    /*23*/ virtual enum CommandOriginType getOriginType() const;
    /*29*/ virtual class CompoundTag serialize() const;
    /*30*/ virtual bool isValid() const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ACTORCOMMANDORIGIN
#endif
    MCAPI ActorCommandOrigin(class Actor &);
    MCAPI static std::unique_ptr<class ActorCommandOrigin> load(class CompoundTag const &, class Level &);



};