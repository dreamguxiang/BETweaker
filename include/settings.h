#pragma once

#include <Nlohmann/json.hpp>

namespace settings {
    extern bool BetterHarvestingCrop;
    extern bool NoFarmDestroy;
    extern bool FastSleeping;
    extern bool DispenserCrops;
    extern bool FastLeafDecay;
    extern bool HUBinfo;
    extern bool AutoFish;
    extern bool DoubleDoors;
    extern bool FastSetMinecart;
    extern bool AutoSupplyItem;
    extern bool CuttingTree;
    extern bool AnvilRestoration;
    extern bool BetterThanMending;
    extern string HUBInfoShow;
    extern std::unordered_set<string> CanDispenserItemList;
    extern bool DispenserDestroyBlock;
    extern bool DispenserDestroyBreakItem;
    extern bool FlyEnabled;
    extern bool AutoCrafting;
    extern bool RenewableSponges;
    extern bool RenewableDeepslate;
    extern bool SeedCommand;
    extern  float FastSleepProbability;
    extern std::vector<string> DispenserDestroyItemList;
    extern std::unordered_set<string> FlyPlayerList;
    extern std::unordered_set<string> NoHubList;
    extern std::unordered_set<string> AutoCraftingBlacklistItems;

    nlohmann::json globaljson();
    void initjson(nlohmann::json json);
    void writeDefaultConfig(const std::string& fileName);
    void loadConfigFromJson(const std::string& fileName);
    void reloadJson(const std::string& fileName);
} // namespace settings