// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

struct ScriptResourceStats {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SCRIPTRESOURCESTATS
public:
    struct ScriptResourceStats& operator=(struct ScriptResourceStats const &) = delete;
    ScriptResourceStats(struct ScriptResourceStats const &) = delete;
    ScriptResourceStats() = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SCRIPTRESOURCESTATS
#endif
    MCAPI std::string serialize() const;
    MCAPI ~ScriptResourceStats();
    MCAPI static void bindType();

};