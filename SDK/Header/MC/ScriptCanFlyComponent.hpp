// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "ScriptActorComponent.hpp"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class ScriptCanFlyComponent : public ScriptActorComponent {

#define AFTER_EXTRA

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SCRIPTCANFLYCOMPONENT
public:
    class ScriptCanFlyComponent& operator=(class ScriptCanFlyComponent const &) = delete;
    ScriptCanFlyComponent(class ScriptCanFlyComponent const &) = delete;
    ScriptCanFlyComponent() = delete;
#endif

public:
    /*0*/ virtual ~ScriptCanFlyComponent();
    /*
    inline  ~ScriptCanFlyComponent(){
         (ScriptCanFlyComponent::*rv)();
        *((void**)&rv) = dlsym("??1ScriptCanFlyComponent@@UEAA@XZ");
        return (this->*rv)();
    }
    */
    MCAPI static class HashedString const & getHashedName();

protected:

private:

};