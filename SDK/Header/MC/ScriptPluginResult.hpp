// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Scripting.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ScriptPluginResult {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SCRIPTPLUGINRESULT
public:
    class ScriptPluginResult& operator=(class ScriptPluginResult const &) = delete;
    ScriptPluginResult() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SCRIPTPLUGINRESULT
#endif
    MCAPI ScriptPluginResult(struct Scripting::ModuleDescriptor const &);
    MCAPI ScriptPluginResult(class ScriptPluginResult const &);
    MCAPI void addError(std::string const &);
    MCAPI void addErrors(std::vector<std::string> const &);
    MCAPI void addInfo(std::string const &);
    MCAPI void addWarning(std::string const &);
    MCAPI std::vector<struct ScriptPluginResult::Error> const & getErrors() const;
    MCAPI std::vector<struct ScriptPluginResult::Info> const & getInfos() const;
    MCAPI struct Scripting::ModuleDescriptor const & getModuleDescriptor() const;
    MCAPI std::vector<struct ScriptPluginResult::Warning> const & getWarnings() const;
    MCAPI bool hasErrors() const;
    MCAPI ~ScriptPluginResult();

};