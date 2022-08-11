// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class ActorDefinitionEventLoader {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ACTORDEFINITIONEVENTLOADER
public:
    class ActorDefinitionEventLoader& operator=(class ActorDefinitionEventLoader const &) = delete;
    ActorDefinitionEventLoader(class ActorDefinitionEventLoader const &) = delete;
    ActorDefinitionEventLoader() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ACTORDEFINITIONEVENTLOADER
#endif
    MCAPI static class ActorDefinitionEvent loadEvent(class Json::Value, class SemVersion const &, class SemVersion const &, class ActorEventResponseFactory const *);

//private:
    MCAPI static void _loadCollection(class ActorDefinitionEvent &, class Json::Value const &, class SemVersion const &, class ActorEventResponseFactory const *);
    MCAPI static class ActorDefinitionEvent _loadEvent(class Json::Value &, class SemVersion const &, class ActorEventResponseFactory const *);

private:

};