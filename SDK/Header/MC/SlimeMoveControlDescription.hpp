// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class SlimeMoveControlDescription {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SLIMEMOVECONTROLDESCRIPTION
public:
    class SlimeMoveControlDescription& operator=(class SlimeMoveControlDescription const &) = delete;
    SlimeMoveControlDescription(class SlimeMoveControlDescription const &) = delete;
    SlimeMoveControlDescription() = delete;
#endif

public:
    /*0*/ virtual char const * getJsonName() const;
    /*1*/ virtual ~SlimeMoveControlDescription();
    /*2*/ virtual void deserializeData(struct DeserializeDataParams);
    /*3*/ virtual void serializeData(class Json::Value &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SLIMEMOVECONTROLDESCRIPTION
#endif

};