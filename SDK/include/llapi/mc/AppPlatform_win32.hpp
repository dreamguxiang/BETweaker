// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class AppPlatform_win32 {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_APPPLATFORM_WIN32
public:
    class AppPlatform_win32& operator=(class AppPlatform_win32 const &) = delete;
    AppPlatform_win32(class AppPlatform_win32 const &) = delete;
    AppPlatform_win32() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_APPPLATFORM_WIN32
    MCVAPI bool canLaunchUri(std::string const &);
    MCVAPI class Core::PathBuffer<std::string> copyImportFileToTempFolder(class Core::Path const &);
    MCVAPI class std::shared_ptr<class WebviewInterface> createWebview(class Webview::PlatformArguments &&) const;
    MCVAPI std::string getApplicationId() const;
    MCVAPI class Core::PathBuffer<std::string> getAssetFileFullPath(class Core::Path const &);
    MCVAPI enum BuildPlatform getBuildPlatform() const;
    MCVAPI int getDisplayHeight();
    MCVAPI int getDisplayWidth();
    MCVAPI std::string getEdition() const;
    MCVAPI unsigned __int64 getFreeMemory() const;
    MCVAPI class Core::PathBuffer<std::string> getLoggingPath() const;
    MCVAPI unsigned __int64 getMemoryLimit() const;
    MCVAPI std::string getModelName();
    MCVAPI enum OsVersion getOSVersion() const;
    MCVAPI std::string getPackageFamilyName() const;
    MCVAPI class Core::PathBuffer<std::string> getPackagePath() const;
    MCVAPI float getPixelsPerMillimeter();
    MCVAPI std::string getPlatformString() const;
    MCVAPI bool getPlatformTTSEnabled() const;
    MCVAPI enum PlatformType getPlatformType() const;
    MCVAPI enum UIScalingRules getPlatformUIScalingRules() const;
    MCVAPI class std::variant<struct HWND__*, struct std::monostate> getRenderSurfaceParameters() const;
    MCVAPI int getScreenHeight() const;
    MCVAPI int getScreenWidth() const;
    MCVAPI std::unique_ptr<class SecureStorage> getSecureStorage();
    MCVAPI class SecureStorageKey getSecureStorageKey(std::string const &);
    MCVAPI std::string getSubPlatformString() const;
    MCVAPI unsigned __int64 getTotalPhysicalMemory() const;
    MCVAPI unsigned __int64 getUsedMemory();
    MCVAPI bool hasBuyButtonWhenInvalidLicense();
    MCVAPI bool hasFastAlphaTest() const;
    MCVAPI bool isCentennial() const;
    MCVAPI class std::optional<bool> isOnWifiConnectionTelemetryValue();
    MCVAPI bool isWebviewSupported() const;
    MCVAPI void launchUri(std::string const &);
    MCVAPI class std::set<class Core::PathBuffer<std::string>, struct std::less<class Core::PathBuffer<std::string>>, class std::allocator<class Core::PathBuffer<std::string>>> listAssetFilesIn(class Core::Path const &, std::string const &) const;
    MCVAPI std::string readAssetFile(class Core::Path const &);
    MCVAPI void setFullscreenMode(enum FullscreenMode);
    MCVAPI void setScreenSize(int, int);
    MCVAPI void setSecureStorageKey(std::string const &, class SecureStorageKey const &);
    MCVAPI void setWindowSize(int, int);
    MCVAPI void setWindowText(std::string const &);
    MCVAPI bool supportsFliteTTS() const;
    MCVAPI bool supportsVibration() const;
    MCVAPI void updateTextBoxText(std::string const &);
    MCVAPI ~AppPlatform_win32();
#endif
    MCAPI AppPlatform_win32(struct HWND__*, std::string const &, std::string const &, class gsl::basic_string_span<char const, -1>, class std::shared_ptr<class HIDController>, int, int);
    MCAPI static void setupWorkingDirectory();

//private:
    MCAPI struct OSInformation _fetchOSInformation() const;

private:

};