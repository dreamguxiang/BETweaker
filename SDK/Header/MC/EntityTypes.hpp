// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class EntityTypes {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ENTITYTYPES
public:
    class EntityTypes& operator=(class EntityTypes const &) = delete;
    EntityTypes(class EntityTypes const &) = delete;
    EntityTypes() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ENTITYTYPES
#endif
    MCAPI bool parseJson(class Json::Value const &);
    MCAPI ~EntityTypes();

};