// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class MingleComponent {

#define AFTER_EXTRA
// Add Member There
public:
enum MingleState;

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MINGLECOMPONENT
public:
    class MingleComponent& operator=(class MingleComponent const &) = delete;
    MingleComponent(class MingleComponent const &) = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_MINGLECOMPONENT
#endif
    MCAPI MingleComponent();
    MCAPI class MingleComponent & clearPreviousPartnerId();
    MCAPI class Actor * fetchCurrentPartner(class Actor const &) const;
    MCAPI void resetState();
    MCAPI class MingleComponent & setMingleState(enum MingleComponent::MingleState);
    MCAPI class MingleComponent & setPartnerId(struct ActorUniqueID);

};