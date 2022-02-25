#pragma once

#include <Utils/FileHelper.h>
#include <Nlohmann/json.hpp>

namespace Settings {
    extern bool BetterHarvestingCrop;
    extern bool NoFarmDestroy;
    extern bool FastSleeping;
    extern bool DispenserCrops;
    nlohmann::json globaljson();
    void initjson(nlohmann::json json);
    void WriteDefaultConfig(const std::string& fileName);
    void LoadConfigFromJson(const std::string& fileName);
    void reloadJson(const std::string& fileName);
} // namespace Settings