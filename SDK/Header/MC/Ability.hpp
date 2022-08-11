// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class Ability {

#define AFTER_EXTRA
// Add Member There
public:
enum Options;
enum Type;

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ABILITY
public:
    class Ability& operator=(class Ability const &) = delete;
    Ability(class Ability const &) = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ABILITY
#endif
    MCAPI Ability();
    MCAPI Ability(bool, enum Ability::Options);
    MCAPI bool getBool() const;
    MCAPI float getFloat() const;
    MCAPI enum Ability::Type getType() const;
    MCAPI bool hasOption(enum Ability::Options) const;
    MCAPI bool isSet() const;
    MCAPI bool operator!=(class Ability const &) const;
    MCAPI void setBool(bool);
    MCAPI void setFloat(float);
    MCAPI void unSet();

};