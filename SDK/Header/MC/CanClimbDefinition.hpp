// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "JsonUtil.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct CanClimbDefinition {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CANCLIMBDEFINITION
public:
    struct CanClimbDefinition& operator=(struct CanClimbDefinition const &) = delete;
    CanClimbDefinition(struct CanClimbDefinition const &) = delete;
    CanClimbDefinition() = delete;
#endif

public:
    MCAPI void initialize(class EntityContext &);
    MCAPI void uninitialize(class EntityContext &);

protected:

private:

};