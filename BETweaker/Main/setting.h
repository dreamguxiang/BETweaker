#pragma once

#include <Utils/FileHelper.h>
#include <Nlohmann/json.hpp>

namespace Settings {
    bool BetterHarvestingCrop;
    bool NoFarmDestroy;
    bool FastSleeping;
    bool DispenserCrops;
    bool FastLeafDecay;
    bool HUBinfo;
    bool EditSign;
    bool AutoFish;
    bool DoubleDoors;
    bool FastSetMinecart;
    bool AutoSupplyItem;
    bool CuttingTree;
    bool EndPortalDuplicateGravityBlock;
    string HUBInfoShow;
    std::unordered_set<string> CanDispenserItemList;
    bool DispenserDestroyBlock;
    bool DispenserDestroyBreakItem;
    std::vector<string> DispenserDestroyItemList;
    nlohmann::json globaljson();
    void initjson(nlohmann::json json);
    void WriteDefaultConfig(const std::string& fileName);
    void LoadConfigFromJson(const std::string& fileName);
    void reloadJson(const std::string& fileName);
} // namespace Settings