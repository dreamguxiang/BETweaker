#include <Utils/FileHelper.h>
#include <Nlohmann/json.hpp>
#include "../Global.h"
#define TRJ(key,val)                                         \
if (json.find(key) != json.end()) {                          \
    const nlohmann::json& out = json.at(key);                \
    out.get_to(val);}                                         \

namespace Settings {

    bool BetterHarvestingCrop = true;
    bool NoFarmDestroy = true;
    bool FastSleeping = true;
    bool DispenserCrops = true;
    bool HUBinfo = true;
    bool EditSign = true;

    nlohmann::json globaljson() {
        nlohmann::json json;
        json["BetterHarvestingCrop"] = BetterHarvestingCrop;
        json["NoFarmDestroy"] = NoFarmDestroy;
        json["FastSleeping"] = FastSleeping;
        json["DispenserCrops"] = DispenserCrops;
        json["HUBinfo"] = HUBinfo;
        json["EditSign"] = EditSign;
        return json;
    }

    void initjson(nlohmann::json json) {
        TRJ("BetterHarvestingCrop", BetterHarvestingCrop);
        TRJ("NoFarmDestroy", NoFarmDestroy);
        TRJ("FastSleeping", FastSleeping);
        TRJ("DispenserCrops", DispenserCrops);
        TRJ("HUBinfo", HUBinfo);
        TRJ("EditSign", EditSign);
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

