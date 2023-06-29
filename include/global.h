#pragma once

#include "llapi/LoggerAPI.h"

extern Logger logger;
inline bool isInit = false;
//LLAPI
#include <llapi/Global.h>
#include <llapi/ScheduleAPI.h>

//BETweaker
#include <settings.h>
#include <memory/hook.h>

//MCAPI
#include <llapi/mc/FishingHook.hpp>
#include <llapi/mc/HashedString.hpp>
#include <llapi/mc/ServerPlayer.hpp>
#include <llapi/mc/Randomize.hpp>
#include <llapi/mc/CropBlock.hpp>
#include <llapi/mc/Block.hpp>
#include <llapi/mc/BlockLegacy.hpp>
#include <llapi/mc/BlockInstance.hpp>
#include <llapi/mc/NetherWartBlock.hpp>
#include <llapi/mc/EnchantUtils.hpp>
#include <llapi/mc/Random.hpp>
#include <llapi/mc/ItemStack.hpp>
#include <llapi/mc/Item.hpp>
#include <llapi/mc/Level.hpp>
#include <llapi/mc/VanillaItemNames.hpp>
#include <llapi/mc/ItemInstance.hpp>
#include <llapi/mc/GameMode.hpp>
#include <llapi/mc/Vec3.hpp>
#include <llapi/mc/BlockPos.hpp>
#include <llapi/mc/mce.hpp>
#include <llapi/mc/Vec2.hpp>
#include <llapi/mc/Vec2.hpp>
#include <llapi/mc/DoorBlock.hpp>
#include <llapi/mc/StaticVanillaBlocks.hpp>
#include <llapi/mc/LeavesBlock.hpp>
#include <llapi/mc/BlockSource.hpp>
#include <llapi/mc/LogBlock.hpp>
#include <llapi/mc/Attribute.hpp>
#include <llapi/mc/AttributeInstance.hpp>