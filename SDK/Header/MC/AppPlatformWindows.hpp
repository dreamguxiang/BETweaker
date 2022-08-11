// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class AppPlatformWindows {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_APPPLATFORMWINDOWS
public:
    class AppPlatformWindows& operator=(class AppPlatformWindows const &) = delete;
    AppPlatformWindows(class AppPlatformWindows const &) = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_APPPLATFORMWINDOWS
    MCVAPI class Core::PathBuffer<std::string> _getCurrentStoragePath() const;
    MCVAPI class Core::PathBuffer<std::string> _getExternalStoragePath() const;
    MCVAPI class Core::PathBuffer<std::string> _getInternalStoragePath() const;
    MCVAPI class Core::PathBuffer<std::string> _getUserdataPath() const;
    MCVAPI bool allowContentLogWriteToDisk();
    MCVAPI unsigned __int64 calculateAvailableDiskFreeSpace(class Core::Path const &);
    MCVAPI bool canAppSelfTerminate() const;
    MCVAPI class Core::PathBuffer<std::string> copyImportFileToTempFolder(class Core::Path const &);
    MCVAPI unsigned __int64 getHighPerformanceThreadsCount() const;
    MCVAPI class MPMCQueue<class std::function<void (void)>> & getMainThreadQueue();
    MCVAPI class Core::PathBuffer<std::string> getPackagedShaderCachePath();
    MCVAPI bool getPlatformTTSEnabled() const;
    MCVAPI bool getPlatformTTSExists() const;
    MCVAPI class Core::PathBuffer<std::string> getPlatformTempPath() const;
    MCVAPI unsigned __int64 getTotalHardwareThreadsCount() const;
    MCVAPI void queueForMainThread_DEPRECATED(class std::function<void (void)>);
    MCVAPI void registerExperimentsActiveCrashDump(std::vector<std::string> const &) const;
    MCVAPI ~AppPlatformWindows();
#endif
    MCAPI AppPlatformWindows();
    MCAPI static std::string const EXPERIMENTS_ACTIVE_KEY;

//protected:
    MCAPI unsigned __int64 _findHighPerformanceThreadsCount() const;

protected:

};