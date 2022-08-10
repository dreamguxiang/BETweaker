// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

struct ImguiProfiler {

#define AFTER_EXTRA

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_IMGUIPROFILER
public:
    struct ImguiProfiler& operator=(struct ImguiProfiler const &) = delete;
    ImguiProfiler(struct ImguiProfiler const &) = delete;
    ImguiProfiler() = delete;
#endif

public:
    MCAPI class TimeAccumulator getTimeAccumulator(std::string const &, std::string const &, bool);
    MCAPI void reset();

protected:

private:
    MCAPI static std::vector<struct ImguiProfiler::Record> sPendingRecords;
    MCAPI static class std::mutex sRecordMutex;

};