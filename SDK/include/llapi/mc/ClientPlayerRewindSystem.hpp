// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class ClientPlayerRewindSystem {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CLIENTPLAYERREWINDSYSTEM
public:
    class ClientPlayerRewindSystem& operator=(class ClientPlayerRewindSystem const &) = delete;
    ClientPlayerRewindSystem(class ClientPlayerRewindSystem const &) = delete;
    ClientPlayerRewindSystem() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CLIENTPLAYERREWINDSYSTEM
#endif
    MCAPI static struct TickingSystemWithInfo createSystem();

//private:
    MCAPI static void _doClientPlayerRewindSystem(class StrictEntityContext const &, class ActorOwnerComponent &, class ReplayStateComponent &);

private:

};