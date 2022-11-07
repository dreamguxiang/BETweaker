// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class CommandOutputParameter {

#define AFTER_EXTRA
    enum NoCountType;
    std::string str;
    int type;
#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_COMMANDOUTPUTPARAMETER
public:
    class CommandOutputParameter& operator=(class CommandOutputParameter const &) = delete;
    CommandOutputParameter() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_COMMANDOUTPUTPARAMETER
#endif
    MCAPI CommandOutputParameter(bool);
    MCAPI CommandOutputParameter(enum CommandOutputParameter::NoCountType);
    MCAPI CommandOutputParameter(class BlockPos);
    MCAPI CommandOutputParameter(char const *);
    MCAPI CommandOutputParameter(float);
    MCAPI CommandOutputParameter(int);
    MCAPI CommandOutputParameter(class Actor const &);
    MCAPI CommandOutputParameter(class Actor const *);
    MCAPI CommandOutputParameter(std::vector<std::string> const &);
    MCAPI CommandOutputParameter(std::vector<class Actor const *> const &);
    MCAPI CommandOutputParameter(std::vector<class Player const *> const &);
    MCAPI CommandOutputParameter(std::string const &);
    MCAPI CommandOutputParameter(class CommandSelectorResults<class Actor> const &);
    MCAPI CommandOutputParameter(class CommandSelectorResults<class Player> const &);
    MCAPI CommandOutputParameter(class CommandOutputParameter const &);
    MCAPI CommandOutputParameter(class CommandOutputParameter &&);
    MCAPI class CommandOutputParameter & operator=(class CommandOutputParameter &&);
    MCAPI ~CommandOutputParameter();

};