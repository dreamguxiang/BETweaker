// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PeekComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PEEKCOMPONENT
public:
    class PeekComponent& operator=(class PeekComponent const &) = delete;
    PeekComponent(class PeekComponent const &) = delete;
    PeekComponent() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_PEEKCOMPONENT
#endif
    MCAPI int & getDuration();
    MCAPI bool getHadTarget() const;
    MCAPI void setHadTarget(bool);

};