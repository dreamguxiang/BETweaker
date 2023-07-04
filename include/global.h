#pragma once

#include "llapi/LoggerAPI.h"

extern Logger logger;
inline bool isInit = false;
//LLAPI
#include <llapi/Global.h>
#include <llapi/ScheduleAPI.h>
#include <llapi/utils/Hash.h>

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
#include <llapi/mc/Container.hpp>
#include <llapi/mc/SeedItemComponentLegacy.hpp>
#include <llapi/mc/Material.hpp>
#include <llapi/mc/CameraItemComponentLegacy.hpp>
#include <llapi/mc/BlockActor.hpp>
#include <llapi/mc/BlockActorDataPacket.hpp>
#include <llapi/mc/DispenserBlock.hpp>
#include <llapi/mc/RandomizableBlockActorContainerBase.hpp>
#include <llapi/mc/ActorDefinitionIdentifier.hpp>
#define ENABLE_VIRTUAL_FAKESYMBOL_DISPENSERBLOCKACTOR
#include <llapi/mc/DispenserBlockActor.hpp>
#include <llapi/mc/ActorFactory.hpp>
#include <llapi/mc/I18n.hpp>
#include <llapi/mc/CompoundTag.hpp>
#include <llapi/mc/ListTag.hpp>
#include <llapi/mc/Recipe.hpp>
#define ENABLE_VIRTUAL_FAKESYMBOL_HOPPERBLOCKACTOR
#include <llapi/mc/HopperBlockActor.hpp>
#include <llapi/mc/ILevel.hpp>
#include <llapi/mc/CraftingContainer.hpp>
#include <llapi/mc/Spawner.hpp>
#include <llapi/mc/CraftingContext.hpp>

#define I18N_GET(key,lang) I18n::get(key, I18n::getLanguage(lang))