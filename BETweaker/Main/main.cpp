#include "../Global.h"
#include "Module.h"
#include <MC/Dimension.hpp>
#include <MC/Actor.hpp>
#include <ScheduleAPI.h>
#include <MC/ResourcePackRepository.hpp>
#include <MC/ResourcePackStack.hpp>
#include <MC/BlockActor.hpp>
Logger logger(fmt::format(fg(fmt::color::light_pink), "BETweaker"));
map<string, long > useitemonbug;


time_t getTimeStamp()
{
    std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    auto tmp = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());
    std::time_t timestamp = tmp.count();
    return timestamp;
}

std::unordered_set<string> SignBlocks{
"minecraft:standing_sign",
"minecraft:spruce_standing_sign",
"minecraft:birch_standing_sign",
"minecraft:jungle_standing_sign",
"minecraft:acacia_standing_sign",
"minecraft:darkoak_standing_sign",
"minecraft:crimson_standing_sign",
"minecraft:warped_standing_sign",
"minecraft:wall_sign",
"minecraft:spruce_wall_sign",
"minecraft:birch_wall_sign",
"minecraft:jungle_wall_sign",
"minecraft:acacia_wall_sign",
"minecraft:darkoak_wall_sign",
"minecraft:crimson_wall_sign",
"minecraft:warped_wall_sign"
};

bool PlayerUseOn(const Event::PlayerUseItemOnEvent& ev) {
    long a = getTimeStamp();
    Player* sp = ev.mPlayer;
    auto playername = sp->getRealName();
    for (auto iter = useitemonbug.rbegin(); iter != useitemonbug.rend(); iter++)
        if (iter->first == playername) {
            if (a - useitemonbug[playername] <= (long)100) {
                return true;
            }
        }
    auto blockin = ev.mBlockInstance;
    auto blactor = blockin.getBlockEntity();
    useitemonbug[playername] = a;
    useitemonbug.insert(std::map < string, long > ::value_type(playername, a));

    if (Settings::BetterHarvestingCrop) {
        Module::LoadBetterHarvestingCrop(blockin, sp);
    }
	
    if (Settings::EditSign) {
        if (Helper::isBETstick(sp)) {
            if (SignBlocks.count(blockin.getBlock()->getTypeName())) {
                Module::EditSign(sp, blockin);
            }
        }
    }
	
    if (Settings::DispenserDestroyBlock) {
        if (Helper::isBETstick(sp)) {
            if (sp->isSneaking()) {
                auto blactor = blockin.getBlockEntity();
                if (blactor) {
                    if (blactor->getType() == BlockActorType::Dispenser) {
                        Module::ChangeDispenserMode(blactor, sp->getBlockSource(), sp);
                    }
                }
            }
        }
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
}//加载语言&配置文件

#include <MC/ResourcePackManager.hpp>
#include <MC/ResourceLocation.hpp>
#include <MC/Types.hpp>

static_assert(sizeof(SemVersion) == 0x70);

ResourcePackRepository* gl;

THook(bool, "?isInitialized@ResourcePackRepository@@UEAA_NXZ"
    , ResourcePackRepository* a1) {
    gl = a1;
    return original(a1);
}

extern void RegisterCommands();

bool PackInstall() {
    string File = Level::getCurrentLevelPath() + "/world_resource_packs.json";
    if (!std::filesystem::exists(File))
    {
        std::ofstream fout(File);
        fout << "[]" << std::flush;
    }

    try
    {
        auto Data = nlohmann::json::object();
        Data["pack_id"] = "3e15339d-aa47-114f-71ab-79b3cfb7f4c4";
        Data["version"] =  std::list{1,0,0};

        auto PackList = nlohmann::json::parse(*ReadAllFile(File));
        for (int i = 0; i < PackList.size(); i++) {
            if (PackList[i]["pack_id"] == "3e15339d-aa47-114f-71ab-79b3cfb7f4c4") {
                return false;
            }
        }
        PackList.push_back(Data);
        bool res = WriteAllFile(File, PackList.dump(4));
        if (!res)
            throw "Fail to write data back to addon list file!";

        return true;
    }
    catch (const std::exception& e)
    {
        return false;
    }
}

void initEvent() 
{
    Event::PlayerUseItemOnEvent::subscribe(PlayerUseOn);
    RegisterCommands();
    Event::ServerStartedEvent::subscribe([](const Event::ServerStartedEvent& ev) {
        if(Settings::HUBinfo) Module::HUBInfo();
        std::thread th([]() {
            checkUpdate();
            });
        th.detach();

        auto pack = gl->getResourcePackByUUID(mce::UUID::fromString("3e15339d-aa47-114f-71ab-79b3cfb7f4c4"));
        if (pack) {
            if (pack->getVersion().asString() != VERSION_RES.toString()) {
                logger.error("ResourcePack(BETweaker) is out of date.(old version:{} |new version:{})", pack->getVersion().asString(),VERSION_RES.toString());
            }
        }		
        return true;
        });
}


void regtest();
#include <ServerAPI.h>
void PluginInit()
{
    loadCfg();
    PackInstall();
    Event::ServerStartedEvent::subscribe([](const Event::ServerStartedEvent) {
       // regtest();
        return true;
        });
    logger.info("BETweaker {} Loaded by QingYu", VERSION.toString());
    logger.info("Build Date[{}]", __TIMESTAMP__);
    logger.info("Support ProtocolVersion {}", fmt::format(fg(fmt::color::orange_red), std::to_string(BDSP)));
    if (LL::getServerProtocolVersion() != BDSP) {
        logger.error("This version({}) does not support BDSProtocolVersion:{}", VERSION.toString(), LL::getServerProtocolVersion());
        logger.error("Please get the latest version");
    }
    initEvent();
}