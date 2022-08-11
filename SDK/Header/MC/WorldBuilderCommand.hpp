// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Command.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class WorldBuilderCommand : public Command {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_WORLDBUILDERCOMMAND
public:
    class WorldBuilderCommand& operator=(class WorldBuilderCommand const &) = delete;
    WorldBuilderCommand(class WorldBuilderCommand const &) = delete;
    WorldBuilderCommand() = delete;
#endif

public:
    /*0*/ virtual ~WorldBuilderCommand();
    /*1*/ virtual void execute(class CommandOrigin const &, class CommandOutput &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_WORLDBUILDERCOMMAND
#endif
    MCAPI static void setWorldBuilder(class LayeredAbilities &, bool);
    MCAPI static void setup(class CommandRegistry &);

};