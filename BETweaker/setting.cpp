#include <Utils/FileHelper.h>
#include <Nlohmann/json.hpp>
#include "setting.h"

#define TRJ(key,val)                                         \
if (json.find(key) != json.end()) {                          \
    const nlohmann::json& out = json.at(key);                \
    out.get_to(val);}                                         \

namespace Settings {

    bool BetterHarvestingCrop = true;
    bool NoFarmDestroy = true;
    nlohmann::json globaljson() {
        nlohmann::json json;
        json["BetterHarvestingCrop"] = BetterHarvestingCrop;
        json["NoFarmDestroy"] = NoFarmDestroy;
        return json;
    }

    void initjson(nlohmann::json json) {
        TRJ("BetterHarvestingCrop", BetterHarvestingCrop);
        TRJ("NoFarmDestroy", NoFarmDestroy);
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
} // namespace Settings