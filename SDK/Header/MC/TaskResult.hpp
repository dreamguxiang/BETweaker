// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class TaskResult {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_TASKRESULT
public:
    class TaskResult& operator=(class TaskResult const&) = delete;
    TaskResult(class TaskResult const&) = delete;
    TaskResult() = delete;
#endif

public:
    MCAPI ~TaskResult();
    MCAPI static class TaskResult const Done;
    MCAPI static class TaskResult const Requeue;
    MCAPI static class TaskResult requeueAfter(class std::chrono::duration<__int64, struct std::ratio<1, 1000000000> >);

protected:

private:

};