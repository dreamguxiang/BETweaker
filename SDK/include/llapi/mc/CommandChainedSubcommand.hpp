// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class CommandChainedSubcommand {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_COMMANDCHAINEDSUBCOMMAND
public:
    class CommandChainedSubcommand& operator=(class CommandChainedSubcommand const &) = delete;
    CommandChainedSubcommand(class CommandChainedSubcommand const &) = delete;
    CommandChainedSubcommand() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_COMMANDCHAINEDSUBCOMMAND
#endif
    MCAPI class Command * getCommand() const;
    MCAPI void setCommand(std::unique_ptr<class Command>);

};