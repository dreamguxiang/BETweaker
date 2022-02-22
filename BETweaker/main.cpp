#include "pch.h"
#include "Moudle.h"
#include <MC/Dimension.hpp>
#include <MC/Actor.hpp>
Logger logger(fmt::format(fg(fmt::color::light_pink),"BETweaker"));

map<string, long > useitemonbug;


time_t getTimeStamp()
{
    std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    auto tmp = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());
    std::time_t timestamp = tmp.count();
    return timestamp;
}

bool PlayerUseOn(const Event::PlayerUseItemOnEvent& ev) {
    long a = getTimeStamp();
    Player* sp = ev.mPlayer;
    auto playername = sp->getRealName();
    for (auto iter = useitemonbug.rbegin(); iter != useitemonbug.rend(); iter++)
        if (iter->first == playername) {
            if (a - useitemonbug[playername] <= (long)50) {
                return false;
            }
        }
    auto blockin = ev.mBlockInstance;
    useitemonbug[playername] = a;
    useitemonbug.insert(std::map < string, long > ::value_type(playername, a));

    if (Settings::BetterHarvestingCrop) {
        loadBetterHarvestingCrop(blockin, sp);
    }

    return true;
}

void loadCfg() {
    //config
    if (!std::filesystem::exists("plugins/BETweaker"))
        std::filesystem::create_directories("plugins/BETweaker");
    //tr	
    if (std::filesystem::exists(JsonFile)) {
        try {
            Settings::LoadConfigFromJson(JsonFile);
        }
        catch (std::exception& e) {
            logger.error("Config File isInvalid, Err {}", e.what());
            Sleep(1000 * 100);
            exit(1);
        }
        catch (...) {
            logger.error("Config File isInvalid");
            Sleep(1000 * 100);
            exit(1);
        }
    }
    else {
        logger.info("Config with default values created");
        Settings::WriteDefaultConfig(JsonFile);
    }
}//º”‘ÿ”Ô—‘&≈‰÷√Œƒº˛
extern void RegisterCommands();

void initEvent() 
{
    Event::PlayerUseItemOnEvent::subscribe(PlayerUseOn);
    RegisterCommands();
}

#include <ServerAPI.h>
void PluginInit()
{
    loadCfg();
    logger.info("BETweaker Loaded by QingYu");
    logger.info("Build Date[{}]", __TIMESTAMP__);
    logger.info("Support ProtocolVersion {}", fmt::format(fg(fmt::color::orange_red), std::to_string(BDSP)));
    if (LL::getServerProtocolVersion() != BDSP) {
        logger.error("This version({}) does not support BDSProtocolVersion:{}", VERSION.toString(), LL::getServerProtocolVersion());
        logger.error("Please get the latest version");
    }
    initEvent();
}
