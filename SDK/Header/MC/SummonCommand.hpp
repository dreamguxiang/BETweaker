// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Command.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class SummonCommand : public Command {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SUMMONCOMMAND
public:
    class SummonCommand& operator=(class SummonCommand const &) = delete;
    SummonCommand(class SummonCommand const &) = delete;
    SummonCommand() = delete;
#endif


public:
    /*0*/ virtual ~SummonCommand();
    /*1*/ virtual void execute(class CommandOrigin const &, class CommandOutput &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SUMMONCOMMAND
#endif
    MCAPI static void setup(class CommandRegistry &);



};