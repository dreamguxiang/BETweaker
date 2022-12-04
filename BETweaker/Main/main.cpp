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
    auto item = ev.mItemStack;
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
    if (Settings::AnvilRestoration) {
        if (sp->isSneaking()) {
            auto out = Module::AnvilRestoration(item, blockin.getBlock(), blockin.getPosition(), sp);
            return out;
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
            exit(1);
        }
        catch (...) {
            logger.error("Config File isInvalid");
     
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
#include <MC/PackSourceFactory.hpp>
#include <MC/CompositePackSource.hpp>
#include <MC/PackSourceFactory.hpp>
#include <MC/ResourcePackPaths.hpp>
#include <MC/DirectoryPackSource.hpp> 
#include <MC/PackSource.hpp>

static_assert(sizeof(SemVersion) == 0x70);

extern void RegisterCommands();


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
        return true;
        });
}

void regtest();
#include <ServerAPI.h>
using namespace std::filesystem;

void removeOldPack() {
    if (exists("resource_packs\\BETweaker")) {
		remove_all("resource_packs\\BETweaker");
		logger.warn("old resource_packs\\BETweaker removed");
    }
}

void PluginInit()
{
    removeOldPack();
    loadCfg();
    Event::ServerStartedEvent::subscribe([](const Event::ServerStartedEvent) {
        Schedule::repeat([] {
            if (((Dimension*)Global<Level>->getOrCreateDimension(0).mHandle.lock().get())->isDay()) {
                sleepList.clear();
            };
            },10*60*20);
        Module::InitAutoCrafting();
        return true;
        });
    Event::ResourcePackInitEvent::subscribe([](const Event::ResourcePackInitEvent& ev) {
        ev.mRepo->setCustomResourcePackPath(PackType::PackType_Resources, ".\\plugins\\BETweaker\\resource_packs");
        return true;
        });
    Logger().info(R"(    ____  ____________                    __            )");
    Logger().info(R"(   / __ )/ ____/_  __/      _____  ______/ /_____  _____)");
    Logger().info(R"(  / __  / __/   / / | | /| / / _ \/ __  / //_/ _ \/ ___/)");
    Logger().info(R"( / /_/ / /___  / /  | |/ |/ /  __/ /_/ /  < /  __/ /  )");
    Logger().info(R"(/_____/_____/ /_/   |__/|__/\___/\____/_/|_|\___/_/     )");
    Logger().info(R"(                                                       )");
    logger.info("BETweaker {} Loaded by QingYu", VERSION.toString());
    logger.info("Build Date[{}]", __TIMESTAMP__);
    logger.info("Support ProtocolVersion {}", fmt::format(fg(fmt::color::orange_red), std::to_string(BDSP)));
    if (ll::getServerProtocolVersion() != BDSP) {
        logger.error("This version({}) does not support BDSProtocolVersion:{}", VERSION.toString(), ll::getServerProtocolVersion());
        logger.error("Please get the latest version");
    }
    initEvent();
}
