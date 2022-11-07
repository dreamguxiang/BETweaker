// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class CommandOutputSender {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_COMMANDOUTPUTSENDER
public:
    class CommandOutputSender& operator=(class CommandOutputSender const &) = delete;
    CommandOutputSender(class CommandOutputSender const &) = delete;
#endif

public:
    /*0*/ virtual ~CommandOutputSender();
    /*1*/ virtual void send(class CommandOrigin const &, class CommandOutput const &);
    /*2*/ virtual void registerOutputCallback(class std::function<void (class AutomationCmdOutput &)> const &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_COMMANDOUTPUTSENDER
#endif
    MCAPI CommandOutputSender();
    MCAPI void sendToAdmins(class CommandOrigin const &, class CommandOutput const &, enum CommandPermissionLevel);
    MCAPI static std::vector<std::string> translate(std::vector<std::string> const &);

//protected:
    MCAPI class Json::Value _toJson(class CommandOutput const &) const;

protected:

};