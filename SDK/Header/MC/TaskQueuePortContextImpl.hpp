// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class TaskQueuePortContextImpl {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_TASKQUEUEPORTCONTEXTIMPL
public:
    class TaskQueuePortContextImpl& operator=(class TaskQueuePortContextImpl const &) = delete;
    TaskQueuePortContextImpl(class TaskQueuePortContextImpl const &) = delete;
    TaskQueuePortContextImpl() = delete;
#endif

public:
    /*0*/ virtual unsigned int AddRef();
    /*1*/ virtual unsigned int Release();
    /*2*/ virtual long QueryApi(enum ApiId, void **);
    /*3*/ virtual enum XTaskQueuePort GetType();
    /*4*/ virtual enum TaskQueuePortStatus GetStatus();
    /*5*/ virtual struct ITaskQueue * GetQueue();
    /*6*/ virtual struct ITaskQueuePort * GetPort();
    /*7*/ virtual bool TrySetStatus(enum TaskQueuePortStatus, enum TaskQueuePortStatus);
    /*8*/ virtual void SetStatus(enum TaskQueuePortStatus);
    /*9*/ virtual void ItemQueued();
    /*10*/ virtual bool AddSuspend();
    /*11*/ virtual bool RemoveSuspend();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_TASKQUEUEPORTCONTEXTIMPL
#endif

};