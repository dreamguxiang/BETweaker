#define CPPHTTPLIB_OPENSSL_SUPPORT

#include <LLAPI.h>
#include <Nlohmann/json.hpp>
#include <ServerAPI.h>
#include <SimpleIni/SimpleIni.h>
#include <Utils/CryptHelper.h>
#include <Utils/FileHelper.h>
#include <Utils/NetworkHelper.h>
#include <Utils/StringHelper.h>
#include <chrono>
#include <filesystem>
#include <httplib/httplib.h>
#include <process.h>
#include <seh_exception/seh_exception.hpp>
#include <string>
#include <thread>
#include "Global.h"

using namespace std;
using namespace LL;

enum class DownloadResult {
    Success,
    FailInit,
    FailDownload,
    FailDownloadMd5,
    FailCheckMd5
};

//Default MD5 File: filename + ".md5"
DownloadResult DownloadAndCheckMd5(const string& url, const string& localPath, bool isBinary, int* errorCode = nullptr,
    string* md5Rtn = nullptr) {
    string domain, path;
    SplitHttpUrl(url, domain, path);

    //Init
    httplib::Client cli(domain.c_str());
    cli.set_connection_timeout(LL_UPDATE_CONNECTION_TIMEOUT, 0);
    if (!cli.is_valid()) {
        if (errorCode)
            *errorCode = -1;
        return DownloadResult::FailInit;
    }

    //Download
    auto response = cli.Get(path.c_str());
    if (response && response->status == 200) {
        if (filesystem::exists(localPath))
            filesystem::remove(localPath);

        ios_base::openmode mode = ios::out;
        if (isBinary)
            mode |= ios::binary;

        ofstream fout(localPath, mode);
        fout << response->body;
        fout.close();
    }
    else {
        if (errorCode)
            *errorCode = response->status;
        return DownloadResult::FailDownload;
    }

    //Download MD5
    string md5;
    response = cli.Get((path + ".md5.verify").c_str());
    if (response && response->status == 200) {
        md5 = response->body;
        if (md5.back() == '\n')
            md5.pop_back();
        if (md5.back() == '\r')
            md5.pop_back();
    }
    else {
        if (errorCode)
            *errorCode = response->status;
        return DownloadResult::FailDownloadMd5;
    }

    if (md5Rtn)
        *md5Rtn = md5;

    //CheckMD5
    auto content = ReadAllFile(localPath, true);
    if (!content || CalcMD5(*content) != md5) {
        if (errorCode)
            *errorCode = -1;
        return DownloadResult::FailCheckMd5;
    }
    return DownloadResult::Success;
}

bool CheckAutoUpdate(bool isUpdateManually, bool forceUpdate) {
    try {
        //Get Dir Id
        int status = -1;
        string idJson;
        if (!HttpGetSync(LL_RELAY_INDEX, &status, &idJson, LL_UPDATE_CONNECTION_TIMEOUT) || status != 200) {
            if (isUpdateManually)
                logger.info("Unable to check for updates. Connection failed! Error Code: {}", status);
            else
                logger.debug("Unable to check for updates. Connection failed! Error Code: {}", status);
            return false;
        }
        if (EndsWith(idJson, "\n"))
            idJson.pop_back();
        if (EndsWith(idJson, "\r"))
            idJson.pop_back();

        nlohmann::json idInfo = nlohmann::json::parse(idJson);
        string id = idInfo["token"];

        //Get Json
        string infoUrl = string(LL_UPDATE_URL_PREFIX) + "/" + id + LL_UPDATE_URL_PATH;
        string info;
        if (!HttpGetSync(infoUrl, &status, &info, LL_UPDATE_CONNECTION_TIMEOUT) || status != 200) {
            if (isUpdateManually)
                logger.info("Unable to check for updates. Download failed! Error Code: {}", status);
            else
                logger.debug("Unable to check for updates. Download failed! Error Code: {}", status);
            return false;
        }

        //Parse
        nlohmann::json data = nlohmann::json::parse(info, nullptr, true, true);

        //Check Announcement
        if (data.find("notice") != data.end() && data["notice"].is_array()) {
            for (auto& element : data["notice"])
                logger.info << element.get<string>() << Logger::endl;
        }

        //Check Other Files config
        if (!filesystem::exists(LL_UPDATE_OTHER_FILES_RECORD)) {
            ofstream fout(LL_UPDATE_OTHER_FILES_RECORD);
            fout.flush();
            fout.close();
        }

        //Process Other Files
        auto iniVersions = new CSimpleIniA;
        iniVersions->SetUnicode(true);
        auto res = iniVersions->LoadFile(LL_UPDATE_OTHER_FILES_RECORD);
        if (res < 0) {
            logger.error("Failed in loading ini file");
            logger.error("Error Code: {}", res);
            delete iniVersions;
        }
        else {
            for (auto& file : data["OtherFiles"]) {
                string fileName = file["Name"].get<string>();
                Version nowVersion = Version::parse(iniVersions->GetValue(fileName.c_str(), "Version", "0.0.0"));
                Version newVersion = Version::parse(file["Version"].get<string>());

                if (nowVersion < newVersion) {
                    if (isUpdateManually)
                        logger.info("Updating file: {}", fileName);
                    else
                        logger.debug("Updating file: {}", fileName);

                    string path = file["Path"].get<string>();
                    string remotePath = string(LL_UPDATE_URL_PREFIX) + "/" + id + path + fileName;
                    string localPath = file["Install"].get<string>() + "/" + fileName;
                    bool isBinary = file["IsBinary"].get<bool>();

                    //Download File
                    int errorCode;
                    string md5;
                    switch (DownloadAndCheckMd5(remotePath, localPath, isBinary, &errorCode, &md5)) {
                    case DownloadResult::Success:
                        iniVersions->SetValue(fileName.c_str(), "Version", newVersion.toString().c_str());
                        break;
                    case DownloadResult::FailInit:
                        if (isUpdateManually)
                            logger.info("Fail to init connection!");
                        else
                            logger.debug("Fail to init connection!");
                        break;
                    case DownloadResult::FailDownload:
                        if (isUpdateManually)
                            logger.info("Fail to download resource! Error code: {}", errorCode);
                        else
                            logger.debug("Fail to download resource! Error code: {}", errorCode);
                        break;
                    case DownloadResult::FailDownloadMd5:
                        if (isUpdateManually)
                            logger.info("Fail to download md5.verify! Error code: {}", errorCode);
                        else
                            logger.debug("Fail to download md5.verify! Error code: {}", errorCode);
                        break;
                    case DownloadResult::FailCheckMd5:
                        if (isUpdateManually)
                            logger.info("Check MD5 failed!");
                        else
                            logger.debug("Check MD5 failed!");
                        break;
                    }
                }
            }
            iniVersions->SaveFile(LL_UPDATE_OTHER_FILES_RECORD);
            delete iniVersions;
        }

        //Check BDS Version
        string bds = LL::getBdsVersion();
        if (bds.front() == 'v')
            bds.erase(0, 1);
        if (!data[bds].is_object()) {
            logger.info(
                "Your BDS does not match the current mainline LLtpa. Auto-update will not be pushed.");
            if (isUpdateManually)
                return false;
            else
                _endthreadex(0);
        }
        else {
            nlohmann::json current = data[bds];

            //Check Announcement
            if (current.find("notice") != current.end() && current["notice"].is_array()) {
                for (auto& element : current["notice"])
                    logger.info << element.get<string>() << Logger::endl;
            }

            //Get Version
            Version verRemote = Version::parse(current["Version"].get<string>());
            Version verCurrent = VERSION;

            if (!forceUpdate && verCurrent >= verRemote) {
                if (isUpdateManually)
                    logger.info("Currently is the latest version.");
                return true;
            }

            //Check existing update
            auto ini = new CSimpleIniA;
            ini->SetUnicode(true);
            auto res = ini->LoadFile(LL_UPDATE_INFO_RECORD);
            if (res >= 0 && Version::parse(ini->GetValue("Info", "Version", "0.0.0")) == verRemote) {
                if (isUpdateManually)
                    logger.info(
                        "Auto-update download is completed, please restart the server to finish update.");
                return true;
            }
            delete ini;

            //Init for Download
            if (isUpdateManually)
                logger.info("New version found, updating...");
            else
                logger.debug("New version found, updating...");
            filesystem::remove_all(LL_UPDATE_CACHE_PATH);
            filesystem::create_directories(LL_UPDATE_CACHE_PATH);

            //Downloading
            auto iniUpdate = new CSimpleIniA;
            iniUpdate->SetUnicode(true);
            for (auto& file : current["Files"]) {
                string fileName = file["Name"].get<string>();
                if (isUpdateManually)
                    logger.info("Get: {}", fileName);
                else
                    logger.debug("Get: {}", fileName);

                string path = file["Path"].get<string>();
                string remotePath = string(LL_UPDATE_URL_PREFIX) + "/" + id + path + fileName;
                string localPath = LL_UPDATE_CACHE_PATH + fileName;
                bool isBinary = file["IsBinary"].get<bool>();

                //Download File
                int errorCode;
                string md5;
                switch (DownloadAndCheckMd5(remotePath, localPath, isBinary, &errorCode, &md5)) {
                case DownloadResult::Success:
                    break;
                case DownloadResult::FailInit:
                    if (isUpdateManually)
                        logger.info("Fail to init connection!");
                    else
                        logger.debug("Fail to init connection!");
                    return false;
                    break;
                case DownloadResult::FailDownload:
                    if (isUpdateManually)
                        logger.info("Fail to download resource! Error code: {}", errorCode);
                    else
                        logger.debug("Fail to download resource! Error code: {}", errorCode);
                    return false;
                    break;
                case DownloadResult::FailDownloadMd5:
                    if (isUpdateManually)
                        logger.info("Fail to download md5.verify! Error Code: {}", errorCode);
                    else
                        logger.debug("Fail to download md5.verify! Error code: {}", errorCode);
                    return false;
                    break;
                case DownloadResult::FailCheckMd5:
                    if (isUpdateManually)
                        logger.info("Check MD5 failed!");
                    else
                        logger.debug("Check MD5 failed!");
                    return false;
                    break;
                }

                //Write to Update.ini
                string install = file["Install"].get<string>();
                iniUpdate->SetValue(fileName.c_str(), "Install", install.c_str());
                iniUpdate->SetValue(fileName.c_str(), "MD5", md5.c_str());
            }

            //Finish Download
            iniUpdate->SetValue("Info", "Version", verRemote.toString().c_str());
            iniUpdate->SaveFile(LL_UPDATE_INFO_RECORD);
            delete iniUpdate;

            logger.warn(
                "Congratulations! The update download is complete. Restart the server now to enjoy the new version.");
        }
    }
    catch (nlohmann::json::exception& e) {
        if (isUpdateManually)
            logger.info("An error occurred while parsing the update configuration, {}", e.what());
        else
            logger.debug("An error occurred while parsing the update configuration, {}", e.what());
    }
    catch (const seh_exception& e) {
        if (isUpdateManually) {
            logger.info("SEH Uncaught Exception Detected!\n{}", e.what());
            logger.info("In Auto Update system");
        }
        else {
            logger.debug("SEH Uncaught Exception Detected!\n{}", e.what());
            logger.debug("In Auto Update system");
        }
    }
    catch (...) {
        if (isUpdateManually)
            logger.info("An error was caught during the update process.");
        else
            logger.debug("An error was caught during the update process.");
    }
    return false;
}