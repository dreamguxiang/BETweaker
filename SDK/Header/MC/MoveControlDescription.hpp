// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct MoveControlDescription {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MOVECONTROLDESCRIPTION
public:
    struct MoveControlDescription& operator=(struct MoveControlDescription const &) = delete;
    MoveControlDescription(struct MoveControlDescription const &) = delete;
    MoveControlDescription() = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_MOVECONTROLDESCRIPTION
    MCVAPI void deserializeData(struct DeserializeDataParams);
    MCVAPI void serializeData(class Json::Value &) const;
#endif

};