// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class AppPlatformNetworkSettings {

#define AFTER_EXTRA

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_APPPLATFORMNETWORKSETTINGS
public:
    class AppPlatformNetworkSettings& operator=(class AppPlatformNetworkSettings const &) = delete;
    AppPlatformNetworkSettings(class AppPlatformNetworkSettings const &) = delete;
#endif


public:
    /*0*/ virtual ~AppPlatformNetworkSettings();
    /*1*/ virtual bool requiresNetworkOutageMessaging() const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_APPPLATFORMNETWORKSETTINGS
public:
#endif
    MCAPI AppPlatformNetworkSettings();


};