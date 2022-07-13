// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

namespace CommandUtils {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
    MCAPI extern std::vector<struct std::pair<std::string, char>> const CMD_INPUT_UNICODE_TRANSLATE_MAP;
    MCAPI bool addItemInstanceComponents(class ItemInstance &, class Json::Value const &, std::string &);
    MCAPI void addtoCSVList(std::string &, std::string const &);
    MCAPI void alterSpawnableEntities(class LevelData &, struct ActorDefinitionIdentifier const &, struct ActorDefinitionIdentifier &);
    MCAPI void broadcastPlayerSpawnedMobEvent(class Actor const &, class Actor &);
    MCAPI bool canBeSummoned(struct ActorDefinitionIdentifier const &, class CommandOrigin const &);
    MCAPI void clearBlockEntityContents(class BlockSource &, class BlockPos const &);
    MCAPI void clearBlockEntityLootTable(class BlockSource &, class BlockPos const &);
    MCAPI void convertBlockEntityTag(class CompoundTag &, class BlockActor const &, class BlockPos const &);
    MCAPI class ItemStack createItemStack(std::string const &, int, int);
    MCAPI std::vector<class ItemStack> createItemStacks(class ItemInstance const &, int, int &);
    MCAPI bool createMapData(class Actor &, class ItemInstance &, class CommandOutput &);
    MCAPI void displayLocalizableMessage(bool, class Player &, std::string const &, std::vector<std::string> const &);
    MCAPI std::string getActorName(class Actor const &);
    MCAPI class BlockPos getFeetBlockPos(class Actor const *);
    MCAPI class Vec3 getFeetPos(class Actor const *);
    MCAPI std::vector<enum ActorType> getInvalidCommandEntities();
    MCAPI class Player const * getOriginPlayer(class CommandOrigin const &);
    MCAPI std::string getTelemetryErrorList(class CommandOutput const &);
    MCAPI bool isActiveTickingChunk(struct Tick, struct Tick);
    MCAPI bool isFunctionValid(class CommandOutput &, class FunctionEntry &, std::string const &);
    MCAPI bool isPlayerSpawnedMob(class Actor const &, class Actor const &);
    MCAPI bool isValidCommandEntity(std::vector<enum ActorType> const &, enum ActorType);
    MCAPI void nameEntity(class Actor &, bool, std::string const &);
    MCAPI void setInitEvent(struct ActorDefinitionIdentifier &, std::string const &);
    MCAPI class Actor * spawnEntityAt(class BlockSource &, class Vec3 const &, struct ActorDefinitionIdentifier const &, struct ActorUniqueID &, class Actor *);
    MCAPI std::string toJsonResult(std::string const &, class Json::Value const &);
    MCAPI std::string const validatePath(class CommandOutput &, class CommandFilePath const &);

};