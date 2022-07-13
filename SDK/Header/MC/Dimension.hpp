// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here
class DimensionHeightRange
{
public:
    short min;
    short max;
};
#undef BEFORE_EXTRA

class Dimension {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_DIMENSION
public:
    class Dimension& operator=(class Dimension const &) = default;
    Dimension(class Dimension const &) = default;
    Dimension() = default;
#endif


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_DIMENSION
    MCVAPI std::unique_ptr<class ChunkBuildOrderPolicyBase> _createChunkBuildOrderPolicy();
    MCVAPI void deserialize(class CompoundTag const &);
    MCVAPI bool forceCheckAllNeighChunkSavedStat() const;
    MCVAPI class mce::Color getBrightnessDependentFogColor(class mce::Color const &, float) const;
    MCVAPI class DimensionBrightnessRamp const & getBrightnessRamp() const;
    MCVAPI float getClearColorScale();
    MCVAPI short getCloudHeight() const;
    MCVAPI int getDefaultBiome() const;
    MCVAPI class BaseLightTextureImageBuilder * getLightTextureImageBuilder() const;
    MCVAPI class BlockPos getSpawnPos() const;
    MCVAPI int getSpawnYPosition() const;
    MCVAPI float getSunIntensity(float, class Vec3 const &, float) const;
    MCVAPI float getTimeOfDay(int, float) const;
    MCVAPI bool hasBedrockFog();
    MCVAPI bool hasGround() const;
    MCVAPI void init();
    MCVAPI bool is2DPositionRelevantForPlayer(class BlockPos const &, class Player &) const;
    MCVAPI bool isActorRelevantForPlayer(class Player &, class Actor const &) const;
    MCVAPI bool isDay() const;
    MCVAPI bool isFoggyAt(int, int) const;
    MCVAPI bool isNaturalDimension() const;
    MCVAPI bool isValidSpawn(int, int) const;
    MCVAPI bool mayRespawnViaBed() const;
    MCVAPI void onBlockChanged(class BlockSource &, class BlockPos const &, unsigned int, class Block const &, class Block const &, int, struct ActorBlockSyncMessage const *, enum BlockChangedEventTarget, class Actor *);
    MCVAPI void onBlockEvent(class BlockSource &, int, int, int, int, int);
    MCVAPI void onChunkLoaded(class ChunkSource &, class LevelChunk &);
    MCVAPI void onLevelDestruction(std::string const &);
    MCVAPI void sendBroadcast(class Packet const &, class Player *);
    MCVAPI void serialize(class CompoundTag &) const;
    MCVAPI bool showSky() const;
    MCVAPI void startLeaveGame();
    MCVAPI void tick();
    MCVAPI void tickRedstone();
    MCVAPI ~Dimension();
#endif
    MCAPI Dimension(class ILevel &, class AutomaticID<class Dimension, int>, class DimensionHeightRange, class Scheduler &, std::string);
    MCAPI void addActorChunkTransferToQueue(class ChunkPos &, class ChunkPos &);
    MCAPI void addActorUnloadedChunkTransferToQueue(class ChunkPos const &, class ChunkPos const &, class AutomaticID<class Dimension, int>, std::string &, std::unique_ptr<class CompoundTag>);
    MCAPI void addWither(struct ActorUniqueID const &);
    MCAPI float distanceToNearestPlayerSqr2D(class Vec3);
    MCAPI class Actor * fetchEntity(struct ActorUniqueID, bool);
    MCAPI class Player * fetchNearestAttackablePlayer(class Actor &, float);
    MCAPI class Player * fetchNearestAttackablePlayer(class BlockPos, float, class Actor *);
    MCAPI class Player * fetchNearestPlayer(class Actor &, float);
    MCAPI class Player * fetchNearestPlayer(float, float, float, float, bool);
    MCAPI class Player * findPlayer(class std::function<bool (class Player const &)>) const;
    MCAPI void flagEntityforChunkMove(class Actor &);
    MCAPI void flushLevelChunkGarbageCollector();
    MCAPI void flushRunTimeLighting();
    MCAPI void forEachPlayer(class std::function<bool (class Player &)>) const;
    MCAPI void forceSaveVillageManager();
    MCAPI class BlockEventDispatcher & getBlockEventDispatcher();
    MCAPI class BlockSource & getBlockSourceFromMainChunkSource() const;
    MCAPI class ChunkBuildOrderPolicyBase & getChunkBuildOrderPolicy();
    MCAPI class gsl::not_null<class ChunkLoadActionList *> getChunkLoadActionList();
    MCAPI class ChunkSource & getChunkSource() const;
    MCAPI class CircuitSystem & getCircuitSystem();
    MCAPI class gsl::not_null<class DelayActionList *> getDelayActionList();
    MCAPI class AutomaticID<class Dimension, int> getDimensionId() const;
    MCAPI std::vector<class WeakEntityRef> & getDisplayEntities();
    MCAPI class std::unordered_map<struct ActorUniqueID, class WeakEntityRef, struct std::hash<struct ActorUniqueID>, struct std::equal_to<struct ActorUniqueID>, class std::allocator<struct std::pair<struct ActorUniqueID const, class WeakEntityRef>>> & getEntityIdMap();
    MCAPI class std::unordered_map<struct ActorUniqueID, class WeakEntityRef, struct std::hash<struct ActorUniqueID>, struct std::equal_to<struct ActorUniqueID>, class std::allocator<struct std::pair<struct ActorUniqueID const, class WeakEntityRef>>> const & getEntityIdMapConst() const;
    MCAPI class FeatureTerrainAdjustments & getFeatureTerrainAdjustments();
    MCAPI class GameEventDispatcher * getGameEventDispatcher() const;
    MCAPI short getHeight() const;
    MCAPI unsigned short getHeightInSubchunks() const;
    MCAPI class DimensionHeightRange const & getHeightRange() const;
    MCAPI class Level & getLevel() const;
    MCAPI class Level const & getLevelConst() const;
    MCAPI short getMinHeight() const;
    MCAPI float getMoonBrightness() const;
    MCAPI int getMoonPhase() const;
    MCAPI float getPopCap(int, bool) const;
    MCAPI class Seasons & getSeasons();
    MCAPI struct Brightness getSkyDarken() const;
    MCAPI float getSunAngle(float) const;
    MCAPI class TickingAreaList & getTickingAreas();
    MCAPI class TickingAreaList const & getTickingAreasConst() const;
    MCAPI float getTimeOfDay(float) const;
    MCAPI std::unique_ptr<class VillageManager> const & getVillageManager() const;
    MCAPI class Weather & getWeather() const;
    MCAPI class WorldGenerator * getWorldGenerator() const;
    MCAPI bool hasCeiling() const;
    MCAPI bool hasSkylight() const;
    MCAPI bool isChunkKnown(class ChunkPos const &) const;
    MCAPI bool isLeaveGameDone();
    MCAPI bool isRedstoneTick();
    MCAPI bool isSubChunkHeightWithinRange(short const &) const;
    MCAPI bool isUltraWarm() const;
    MCAPI void onStaticTickingAreaAdded(std::string const &);
    MCAPI void registerDisplayEntity(class WeakRefT<struct EntityRefTraits>);
    MCAPI void registerEntity(struct ActorUniqueID const &, class WeakRefT<struct EntityRefTraits>);
    MCAPI void removeActorByID(struct ActorUniqueID const &);
    MCAPI void removeWither(struct ActorUniqueID const &);
    MCAPI void sendPacketForEntity(class Actor const &, class Packet const &, class Player const *);
    MCAPI void sendPacketForPosition(class BlockPos const &, class Packet const &, class Player const *);
    MCAPI void sendPacketToClients(class Packet const &, std::vector<struct NetworkIdentifierWithSubId>);
    MCAPI void setCeiling(bool);
    MCAPI void setSkylight(bool);
    MCAPI void setUltraWarm(bool);
    MCAPI void transferEntity(class ChunkPos const &, class Vec3 const &, std::unique_ptr<class CompoundTag>, bool);
    MCAPI void transferEntityToUnloadedChunk(class Actor &);
    MCAPI void transferEntityToUnloadedChunk(class ChunkPos const &, class ChunkPos const &, class AutomaticID<class Dimension, int>, std::string &, std::unique_ptr<class CompoundTag>);
    MCAPI bool tryAssignNewRegionAt(class ChunkPos const &, class Actor &);
    MCAPI void tryGarbageCollectStructures();
    MCAPI class BlockSource * tryGetClosestPublicRegion(class ChunkPos const &) const;
    MCAPI void tryLoadLimboEntities(class ChunkPos const &);
    MCAPI void unregisterDisplayEntity(class WeakRefT<struct EntityRefTraits>);
    MCAPI void unregisterEntity(struct ActorUniqueID const &);
    MCAPI void updateBlockLight(class BlockPos const &, struct Brightness, struct Brightness, struct Brightness, struct Brightness, bool);
    MCAPI void updateDimensionBlockSourceTick();
    MCAPI static enum LimboEntitiesVersion const CurrentLimboEntitiesVersion;
    MCAPI static unsigned int const LOW_CPU_PACKET_BLOCK_LIMIT;
    MCAPI static float const MOON_BRIGHTNESS_PER_PHASE[];
    MCAPI static class std::chrono::duration<__int64, struct std::ratio<1, 1>> const STRUCTURE_PRUNE_INTERVAL;

//protected:
    MCAPI void _completeEntityTransfer(class BlockSource &, class OwnerPtrT<struct EntityRefTraits>, bool);

//private:
    MCAPI void _processEntityChunkTransfers();
    MCAPI void _sendBlockEntityUpdatePacket(class NetworkBlockPosition const &);
    MCAPI void _sendBlocksChangedPackets();
    MCAPI void _tickEntityChunkMoves();


protected:

private:


};