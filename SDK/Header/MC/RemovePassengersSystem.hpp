// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class RemovePassengersSystem {

#define AFTER_EXTRA

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_REMOVEPASSENGERSSYSTEM
public:
    class RemovePassengersSystem& operator=(class RemovePassengersSystem const &) = delete;
    RemovePassengersSystem(class RemovePassengersSystem const &) = delete;
    RemovePassengersSystem() = delete;
#endif


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_REMOVEPASSENGERSSYSTEM
#endif
    MCAPI static struct TickingSystemWithInfo createRemovePassengersSystem();



};