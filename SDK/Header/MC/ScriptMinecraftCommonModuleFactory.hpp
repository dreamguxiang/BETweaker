// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class ScriptMinecraftCommonModuleFactory {

#define AFTER_EXTRA

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SCRIPTMINECRAFTCOMMONMODULEFACTORY
public:
    class ScriptMinecraftCommonModuleFactory& operator=(class ScriptMinecraftCommonModuleFactory const &) = delete;
    ScriptMinecraftCommonModuleFactory(class ScriptMinecraftCommonModuleFactory const &) = delete;
#endif


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SCRIPTMINECRAFTCOMMONMODULEFACTORY
#endif
    MCAPI ScriptMinecraftCommonModuleFactory();
    MCAPI void addCommon(class Scripting::ModuleBindingBuilder &, struct Scripting::Version);
    MCAPI ~ScriptMinecraftCommonModuleFactory();



};