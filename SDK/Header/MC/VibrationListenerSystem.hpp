// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class VibrationListenerSystem {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_VIBRATIONLISTENERSYSTEM
public:
    class VibrationListenerSystem& operator=(class VibrationListenerSystem const &) = delete;
    VibrationListenerSystem(class VibrationListenerSystem const &) = delete;
    VibrationListenerSystem() = delete;
#endif

public:
    /*0*/ virtual ~VibrationListenerSystem();
    /*1*/ virtual void __unk_vfn_1();
    /*2*/ virtual void tick(class EntityRegistry &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_VIBRATIONLISTENERSYSTEM
#endif

};