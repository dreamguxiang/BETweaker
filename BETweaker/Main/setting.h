#pragma once

#include <Utils/FileHelper.h>
#include <Nlohmann/json.hpp>

namespace Settings {
    extern bool BetterHarvestingCrop;
    extern bool NoFarmDestroy;
    extern bool FastSleeping;
    extern bool DispenserCrops;
    extern bool FastLeafDecay;
    extern bool HUBinfo;
    extern bool EditSign;
    extern bool AutoFish;
    extern bool DoubleDoors;
    extern bool FastSetMinecart;
    extern bool AutoSupplyItem;
    extern bool CuttingTree;
    extern bool EndPortalDuplicateGravityBlock;
    extern bool AnvilRestoration;
    extern bool BetterThanMending;
    extern string HUBInfoShow;
    extern std::unordered_set<string> CanDispenserItemList;
    extern bool DispenserDestroyBlock;
    extern bool DispenserDestroyBreakItem;
    extern std::vector<string> DispenserDestroyItemList;
    extern std::unordered_set<string> FlyPlayerList;
    nlohmann::json globaljson();
    void initjson(nlohmann::json json);
    void WriteDefaultConfig(const std::string& fileName);
    void LoadConfigFromJson(const std::string& fileName);
    void reloadJson(const std::string& fileName);
} // namespace Settings