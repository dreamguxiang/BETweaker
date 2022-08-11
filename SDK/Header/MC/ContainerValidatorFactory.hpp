// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ContainerValidatorFactory {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CONTAINERVALIDATORFACTORY
public:
    class ContainerValidatorFactory& operator=(class ContainerValidatorFactory const &) = delete;
    ContainerValidatorFactory(class ContainerValidatorFactory const &) = delete;
    ContainerValidatorFactory() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CONTAINERVALIDATORFACTORY
#endif
    MCAPI static std::unique_ptr<class ContainerScreenValidatorBase> createContainerScreenValidator(class ContainerScreenContext const &);
    MCAPI static class std::shared_ptr<class ContainerValidationBase const> createContainerValidator(enum ContainerEnumName, class ContainerScreenContext const &, enum ContainerValidationCaller);
    MCAPI static class Container * getBackingContainer(enum ContainerEnumName, class ContainerScreenContext const &);

};