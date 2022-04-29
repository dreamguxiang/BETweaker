#include <Utils/FileHelper.h>
#include <Nlohmann/json.hpp>
#include "../Global.h"

#define TRJ(key1,key2,val)                                \
if (json.find(key1) != json.end()) {                      \
    if (json.at(key1).find(key2) != json.at(key1).end()) {\
    const nlohmann::json& out2 = json.at(key1).at(key2);  \
         out2.get_to(val);}}                              \

namespace Settings {

    bool BetterHarvestingCrop = true;
    bool NoFarmDestroy = true;
    bool FastSleeping = true;
    bool DispenserCrops = true;
    bool FastLeafDecay = true;
    bool HUBinfo = true;
    bool EditSign = true;
    bool AutoFish = true;
    bool DoubleDoors = true;
    bool FastSetMinecart = true;
    bool AutoSupplyItem = true;
    bool CuttingTree = false;
    string HUBInfoShow = "TIP";
    std::unordered_set<string> CanDispenserItemList{
    "minecraft:bamboo",//bamboo
    "minecraft:sapling",//saplings
    "minecraft:azalea",
    "minecraft:flowering_azalea",
    "minecraft:crimson_fungus",
    "minecraft:warped_fungus",
    "minecraft:brown_mushroom",
    "minecraft:red_mushroom"
    };

    nlohmann::json globaljson() {
        nlohmann::json json;
        json["BetterHarvestingCrop"]["Enabled"] = BetterHarvestingCrop;
        json["NoFarmDestroy"]["Enabled"] = NoFarmDestroy;
        json["FastSleeping"]["Enabled"] = FastSleeping;
        json["DispenserCrops"]["Enabled"] = DispenserCrops;
        json["FastLeafDecay"]["Enabled"] = FastLeafDecay;
        json["HUBInfo"]["Enabled"] = HUBinfo;
        json["EditSign"]["Enabled"] = EditSign;
        json["AutoFish"]["Enabled"] = AutoFish;
        json["DoubleDoors"]["Enabled"] = DoubleDoors;
        json["FastSetMinecart"]["Enabled"] = FastSetMinecart;
        json["AutoSupplyItem"]["Enabled"] = AutoSupplyItem;
        json["HUBInfo"]["Show"] = HUBInfoShow;
        json["DispenserCrops"]["ItemList"] = CanDispenserItemList;
        json["CuttingTree"]["Enabled"] = CuttingTree;
        return json;
    }

    void initjson(nlohmann::json json) {

        TRJ("BetterHarvestingCrop","Enabled", BetterHarvestingCrop);
        TRJ("NoFarmDestroy", "Enabled", NoFarmDestroy);
        TRJ("FastSleeping", "Enabled", FastSleeping);
        TRJ("DispenserCrops", "Enabled", DispenserCrops);
        TRJ("FastLeafDecay", "Enabled", FastLeafDecay);
        TRJ("HUBInfo", "Enabled", HUBinfo);
        TRJ("EditSign", "Enabled", EditSign);
        TRJ("AutoFish", "Enabled", AutoFish);
        TRJ("DoubleDoors", "Enabled", DoubleDoors);
        TRJ("FastSetMinecart", "Enabled", FastSetMinecart);
        TRJ("AutoSupplyItem", "Enabled", AutoSupplyItem);
        TRJ("HUBInfo", "Show", HUBInfoShow);
        TRJ("DispenserCrops","ItemList", CanDispenserItemList);
        TRJ("CuttingTree", "Enabled", CuttingTree);
    }

    void WriteDefaultConfig(const std::string& fileName) {
        std::ofstream file(fileName);
        if (!file.is_open()) {
            std::cout << "Can't open file " << fileName << std::endl;
            return;
        }
        auto json = globaljson();
        file << json.dump(4);
        file.close();
    }

    void LoadConfigFromJson(const std::string& fileName) {
        std::ifstream file(fileName);
        if (!file.is_open()) {
            std::cout << "Can't open file " << fileName << std::endl;
            return;
        }
        nlohmann::json json;
        file >> json;
        file.close();
        initjson(json);
        WriteDefaultConfig(fileName);
    }
    void reloadJson(const std::string& fileName) {
        std::ofstream file(fileName);
        if (file)
        {
            file << globaljson().dump(4);
        }
        else
        {
            Logger("BETweakerJson").error("Configuration File Creation failed!");
        }
        file.close();
    }
} // namespace Settings