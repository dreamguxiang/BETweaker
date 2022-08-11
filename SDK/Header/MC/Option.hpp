// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"
#include "Bedrock.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class Option {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_OPTION
public:
    class Option& operator=(class Option const &) = delete;
    Option(class Option const &) = delete;
    Option() = delete;
#endif

public:
    /*0*/ virtual ~Option();
    /*1*/ virtual void save(std::vector<struct std::pair<std::string, std::string>> &);
    /*2*/ virtual void load(std::string const &);
    /*3*/ virtual void load(class std::map<std::string, std::string, struct std::less<std::string>, class std::allocator<struct std::pair<std::string const, std::string>>> &);
    /*4*/ virtual void load(class Json::Value const &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_OPTION
#endif
    MCAPI Option(enum OptionID, enum OptionOwnerType, enum OptionResetFlags, std::string const &, std::string const &, enum OptionType);
    MCAPI bool canModify() const;
    MCAPI bool getBool() const;
    MCAPI bool hasOverrideSource() const;
    MCAPI void notifyOptionValueChanged(bool);
    MCAPI class Bedrock::PubSub::Subscription registerLock(class std::function<void (bool &)>);
    MCAPI class Bedrock::PubSub::Subscription registerObserver(class std::function<void (class Option const &)>);
    MCAPI void setRequestSaveCallback(class std::function<void (bool)>);
    MCAPI static bool read(std::string const &, bool &);

//private:
    MCAPI void _updatePropertyVector(std::vector<struct std::pair<std::string, std::string>> &, std::string const &);

private:

};