#pragma once
#include "Version.h"

#define JsonFile "plugins/BETweaker/config.json"
#define VERSION ll::Version{PLUGIN_VERSION_MAJOR, PLUGIN_VERSION_MINOR, PLUGIN_VERSION_REVISION, PLUGIN_LLVERSION_STATUS}
#define VERSION_RES ll::Version{PLUGIN_VERSION_MAJOR, PLUGIN_VERSION_MINOR, PLUGIN_VERSION_REVISION}
#define BDSP TARGET_BDS_PROTOCOL_VERSION
#define toStr(x) std::to_string(x)
#define getI18n(x,n) I18n::get(x,n)
#define H(x) do_hash2(x)

#include <iostream>
#include <Global.h>
#include "Main/setting.h"
#include <MC/Player.hpp>
#include <MC/BlockInstance.hpp>
#include <MC/Block.hpp>
#include <MC/CropBlock.hpp>
#include <MC/BlockLegacy.hpp>
#include <MC/ItemStack.hpp>
#include <EventAPI.h>
#include <LoggerAPI.h>
#include <MC/ItemInstance.hpp>
#include <mc/CompoundTag.hpp>
#include <MC/Level.hpp>
#include <MC/Randomize.hpp>
#include <MC/Random.hpp>
#include <MC/Container.hpp>
#include <MC/Item.hpp>
#include <MC/BlockSource.hpp>
#include <MC/ResourcePack.hpp>
#include <MC/PackSourceFactory.hpp>
#include <MC/Core.hpp>
#include <MC/ResourcePackManager.hpp>
#include <MC/PackIdVersion.hpp>
#include <MC/VanillaBlocks.hpp>
#include <MC/LeafBlock.hpp>
#include <MC/SemVersion.hpp>
#include <MC/DispenserBlock.hpp>
#include <MC/LogBlock.hpp>
#include <MC/FallingBlock.hpp>
#include <MC/FishingHook.hpp>
#include <MC/DoorBlock.hpp>
#include <MC/Facing.hpp>
#include <MC/BlockStateVariant.hpp>
#include <MC/BlockStateGroup.hpp>
#include <MC/EnchantUtils.hpp>
#include <MC/EnchantmentInstance.hpp>
#include <MC/VanillaStates.hpp>
#include <MC/ItemState.hpp>
#include <MC/DispenserBlockActor.hpp>
#include "Main/Helper.hpp"
#include <FormUI.h>
#include <ScheduleAPI.h>

extern Logger logger;
extern ScheduleTask hubinfo;

bool CheckAutoUpdate(bool isUpdateManually, bool forceUpdate = false);

/////////////////////// LL AutoUpgrade ///////////////////////

#define LL_RELAY_INDEX "https://upgrade.litebds.com/id.json"
#define LL_UPDATE_URL_PREFIX "https://cdn.jsdelivr.net/gh/LiteLDev/Upgrade"
#define LL_UPDATE_URL_PATH "/BETweaker/BETweaker.json"

#define LL_UPDATE_CHECK_INTERVAL (10 * 60)
#define LL_UPDATE_CONNECTION_TIMEOUT 60

#define LL_UPDATE_PROGRAM "plugins/LiteLoader/LLAutoUpdate.dll"

#define LL_UPDATE_CACHE_PATH "plugins/LiteLoader/Update/"
#define LL_UPDATE_INFO_RECORD "plugins/LiteLoader/Update/Update.ini"

#define LL_UPDATE_OTHER_FILES_RECORD "plugins/BETweaker/Versions.ini"

extern void loadCfg();
extern void checkUpdate();
extern std::set<string> sleepList;
