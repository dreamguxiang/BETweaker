// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct ActorMapping {

#define AFTER_EXTRA
// Add Member There
public:
    std::string mNameSpace;
    std::string mName;
    std::string mAlias;
    HashedString mMappingName;
#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ACTORMAPPING
public:
    struct ActorMapping& operator=(struct ActorMapping const &) = delete;
    ActorMapping(struct ActorMapping const &) = delete;
    ActorMapping() = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ACTORMAPPING
#endif
    MCAPI ActorMapping(std::string const &, std::string const &, std::string const &);
    MCAPI ActorMapping(std::string const &, std::string const &);
    MCAPI std::string getMappingName(enum ActorTypeNamespaceRules) const;
    MCAPI ~ActorMapping();

};