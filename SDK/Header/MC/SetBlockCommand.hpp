// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Command.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class SetBlockCommand : public Command {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SETBLOCKCOMMAND
public:
    class SetBlockCommand& operator=(class SetBlockCommand const &) = delete;
    SetBlockCommand(class SetBlockCommand const &) = delete;
    SetBlockCommand() = delete;
#endif

public:
    /*0*/ virtual ~SetBlockCommand();
    /*1*/ virtual void execute(class CommandOrigin const &, class CommandOutput &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SETBLOCKCOMMAND
#endif
    MCAPI static void setup(class CommandRegistry &);

};