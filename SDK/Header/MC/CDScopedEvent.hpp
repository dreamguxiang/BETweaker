// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class CDScopedEvent {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CDSCOPEDEVENT
public:
    class CDScopedEvent& operator=(class CDScopedEvent const &) = delete;
    CDScopedEvent(class CDScopedEvent const &) = delete;
    CDScopedEvent() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CDSCOPEDEVENT
#endif
    MCAPI CDScopedEvent(enum CrashDumpLogStringID, enum CrashDumpLogStringID, enum CrashDumpLogStringID);
    MCAPI ~CDScopedEvent();

};