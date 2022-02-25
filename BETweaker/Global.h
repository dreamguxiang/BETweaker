#pragma once

#define JsonFile "plugins/BETweaker/config.json"
#define VERSION LL::Version{1,0,2}
#define BDSP 486
#define toStr(x) std::to_string(x)
#define getI18n(x) I18n::get(x)

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
#include <MC/EnchantUtils.hpp>
#include <MC/BlockSource.hpp>
#include <MC/ResourcePack.hpp>
#include <MC/PackSourceFactory.hpp>
#include <MC/Core.hpp>
#include <MC/ResourcePackManager.hpp>
#include <MC/PackIdVersion.hpp>
#include <MC/VanillaBlocks.hpp>
#include <MC/LeafBlock.hpp>
#include <MC/SemVersion.hpp>
#include "Main/Helper.h"
#include <FormUI.h>
#include <ScheduleAPI.h>
extern Logger logger;
extern ScheduleTask hubinfo;