// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class HideDescription {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_HIDEDESCRIPTION
public:
    class HideDescription& operator=(class HideDescription const &) = delete;
    HideDescription(class HideDescription const &) = delete;
    HideDescription() = delete;
#endif


public:
    /*0*/ virtual char const * getJsonName() const;
    /*1*/ virtual ~HideDescription();
    /*3*/ virtual void serializeData(class Json::Value &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_HIDEDESCRIPTION
#endif



};