// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Command.hpp"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class CodeBuilderActorInfoCommand : public Command {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CODEBUILDERACTORINFOCOMMAND
public:
    class CodeBuilderActorInfoCommand& operator=(class CodeBuilderActorInfoCommand const &) = delete;
    CodeBuilderActorInfoCommand(class CodeBuilderActorInfoCommand const &) = delete;
    CodeBuilderActorInfoCommand() = delete;
#endif

public:
    /*0*/ virtual ~CodeBuilderActorInfoCommand();
    /*1*/ virtual void execute(class CommandOrigin const &, class CommandOutput &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CODEBUILDERACTORINFOCOMMAND
#endif
    MCAPI static void setup(class CommandRegistry &);

};