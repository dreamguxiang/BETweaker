// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct ContainerValidationResult {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CONTAINERVALIDATIONRESULT
public:
    struct ContainerValidationResult& operator=(struct ContainerValidationResult const &) = delete;
    ContainerValidationResult(struct ContainerValidationResult const &) = delete;
    ContainerValidationResult() = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CONTAINERVALIDATIONRESULT
#endif
    MCAPI ContainerValidationResult(std::vector<struct ContainerValidationOperation> &&, enum ContainerValidationOutcome, enum ContainerScreenRequestActionType);
    MCAPI ContainerValidationResult(enum ContainerValidationOutcome);
    MCAPI bool isSuccess() const;
    MCAPI struct ContainerValidationOperation const * tryGetOperation(enum ContainerValidationOperationType) const;
    MCAPI ~ContainerValidationResult();

};