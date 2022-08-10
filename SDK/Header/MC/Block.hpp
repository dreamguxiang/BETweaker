// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Add include headers & pre-declares
#include "CompoundTag.hpp"

#undef BEFORE_EXTRA

class Block {

#define AFTER_EXTRA
// Add new members to class
public:
	LIAPI static Block* create(const string& str, unsigned short tileData);
	LIAPI static Block* create(CompoundTag* nbt);

    LIAPI string getTypeName() const;
	LIAPI int getId() const;
	LIAPI unsigned short getTileData();
    LIAPI std::unique_ptr<CompoundTag> getNbt();
    LIAPI bool setNbt(CompoundTag* nbt);

    inline bool operator==(class Block const& a2) const
    {
        __int64 v2; // r8
        __int64 v3; // rax
        v2 = *(__int64*)(this + 16);
        if (!v2 || (v3 = *(__int64*)(&a2 + 16)) == 0)
            return false;
        return v2 == v3 && *(unsigned short*)(this + 8) == *(unsigned short*)(&a2 + 8);
		
    }
	inline bool operator!=(class Block const& a2) const
	{
        __int64 v2; // r8
        __int64 v3; // rax

        v2 = *(__int64*)(this + 16);
        if (!v2 || (v3 = *(__int64*)(&a2 + 16)) == 0)
            return false;
        return v2 != v3 || *(unsigned short*)(this + 8) != *(unsigned short*)(&a2 + 8);	
	}
	
#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLOCK
public:
    class Block& operator=(class Block const &) = delete;
    Block(class Block const &) = delete;
    Block() = delete;
#endif


public:
    /*0*/ virtual ~Block();
    /*1*/ virtual enum BlockRenderLayer getRenderLayer() const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_BLOCK
#endif
    MCAPI Block(unsigned short, class gsl::not_null<class BlockLegacy *>);
    MCAPI Block(unsigned short, class gsl::not_null<class BlockLegacy *>, class CompoundTag, unsigned int const &);
    MCAPI void addAABBs(class BlockSource const &, class BlockPos const &, class AABB const *, std::vector<class AABB> &) const;
    MCAPI bool addCollisionShapes(class BlockSource const &, class BlockPos const &, class AABB const *, std::vector<class AABB> &, class optional_ref<class GetCollisionShapeInterface const>) const;
    MCAPI class Block & addTag(class HashedString const &);
    MCAPI void animateTick(class BlockSource &, class BlockPos const &, class Random &) const;
    MCAPI class ItemInstance asItemInstance(class BlockSource &, class BlockPos const &) const;
    MCAPI bool attack(class Player *, class BlockPos const &) const;
    MCAPI bool breaksFallingBlocks(class BaseGameVersion) const;
    MCAPI std::string buildDescriptionId() const;
    MCAPI std::string buildDescriptionName() const;
    MCAPI void cacheComponentData();
    MCAPI float calcGroundFriction(struct IMobMovementProxy const &, class BlockPos const &) const;
    MCAPI bool canBeBrokenFromFalling() const;
    MCAPI bool canBeBuiltOver(class BlockSource &, class BlockPos const &) const;
    MCAPI bool canBeBuiltOver(class BlockSource &, class BlockPos const &, class BlockItem const &) const;
    MCAPI bool canBeFertilized(class BlockSource &, class BlockPos const &, class Block const &) const;
    MCAPI bool canBeOriginalSurface() const;
    MCAPI bool canConnect(class Block const &, unsigned char, class Block const &) const;
    MCAPI bool canDamperVibrations() const;
    MCAPI bool canHaveExtraData() const;
    MCAPI bool canHurtAndBreakItem() const;
    MCAPI bool canInstatick() const;
    MCAPI bool canOccludeVibrations() const;
    MCAPI bool canProvideFullSupport(unsigned char) const;
    MCAPI bool canProvideMultifaceSupport(unsigned char) const;
    MCAPI bool canProvideSupport(unsigned char, enum BlockSupportType) const;
    MCAPI bool canSlide(class BlockSource &, class BlockPos const &) const;
    MCAPI bool canSurvive(class BlockSource &, class BlockPos const &) const;
    MCAPI bool causesFreezeEffect() const;
    MCAPI bool checkIsPathable(class Actor &, class BlockPos const &, class BlockPos const &) const;
    MCAPI class HitResult clip(class BlockSource const &, class BlockPos const &, class Vec3 const &, class Vec3 const &, bool) const;
    MCAPI class HitResult clip(class BlockSource const &, class BlockPos const &, class Vec3 const &, class Vec3 const &, bool, class AABB const &) const;
    MCAPI class Block const & copyState(class Block const &, class ItemState const &) const;
    MCAPI bool dealsContactDamage(class Actor const &, bool) const;
    MCAPI void destroy(class BlockSource &, class BlockPos const &, class Actor *) const;
    MCAPI void entityInside(class BlockSource &, class BlockPos const &, class Actor &) const;
    MCAPI void executeEvent(std::string const &, class RenderParams &) const;
    MCAPI void executeItemEvent(class ItemStackBase &, std::string const &, class BlockSource &, class BlockPos const &, class Actor *) const;
    MCAPI bool executeTrigger(class DefinitionTrigger const &, class RenderParams &) const;
    MCAPI class AABB const & getAABB(class IConstBlockSource const &, class BlockPos const &, class AABB &, bool) const;
    MCAPI bool getAllowsRunes() const;
    MCAPI enum BlockActorType getBlockEntityType() const;
    MCAPI int getBurnOdds() const;
    MCAPI bool getCollisionShape(class AABB &, class IConstBlockSource const &, class BlockPos const &, class optional_ref<class GetCollisionShapeInterface const>) const;
    MCAPI int getColor(class BlockSource &, class BlockPos const &) const;
    MCAPI int getColor() const;
    MCAPI int getComparatorSignal(class BlockSource &, class BlockPos const &, unsigned char) const;
    MCAPI void getConnectedDirections(class BlockPos const &, class BlockSource &, bool &, bool &, bool &, bool &) const;
    MCAPI enum CreativeItemCategory getCreativeCategory() const;
    MCAPI class gsl::basic_string_span<char const, -1> getCreativeGroup() const;
    MCAPI void getDebugText(std::vector<std::string> &, class BlockPos const &) const;
    MCAPI std::string getDescriptionId() const;
    MCAPI float getDestroySpeed() const;
    MCAPI int getDirectSignal(class BlockSource &, class BlockPos const &, int) const;
    MCAPI class EntityContext & getEntityForModification() const;
    MCAPI float getExplosionResistance(class Actor *) const;
    MCAPI int getFlameOdds() const;
    MCAPI float getFriction() const;
    MCAPI bool getIgnoresDestroyPermissions(class Actor &, class BlockPos const &) const;
    MCAPI class BlockLegacy const & getLegacyBlock() const;
    MCAPI struct Brightness getLight() const;
    MCAPI struct Brightness getLightEmission() const;
    MCAPI class mce::Color getMapColor(class BlockSource &, class BlockPos const &) const;
    MCAPI class Material const & getMaterial() const;
    MCAPI class MobSpawnerData const * getMobToSpawn(class SpawnConditions const &, class BlockSource &) const;
    MCAPI class HashedString const & getName() const;
    MCAPI class Block const & getPlacementBlock(class Actor &, class BlockPos const &, unsigned char, class Vec3 const &, int) const;
    MCAPI int getResourceCount(class Randomize &, int) const;
    MCAPI unsigned int const & getRuntimeId() const;
    MCAPI bool getSecondPart(class BlockSource const &, class BlockPos const &, class BlockPos &) const;
    MCAPI class CompoundTag const & getSerializationId() const;
    MCAPI class ItemInstance getSilkTouchItemInstance() const;
    MCAPI float getThickness() const;
    MCAPI float getTranslucency() const;
    MCAPI int getVariant() const;
    MCAPI class AABB const & getVisualShape(class AABB &, bool) const;
    MCAPI class AABB const & getVisualShapeInWorld(class BlockSource &, class BlockPos const &, class AABB &, bool) const;
    MCAPI bool hasBlockEntity() const;
    MCAPI bool hasComparatorSignal() const;
    MCAPI bool hasProperty(enum BlockProperty) const;
    MCAPI bool hasPropertyNoLock(enum BlockProperty) const;
    MCAPI bool const hasRuntimeId() const;
    MCAPI bool hasState(class ItemState const &) const;
    MCAPI bool hasTag(class HashedString const &) const;
    MCAPI bool hasTag(unsigned __int64 const &) const;
    MCAPI bool ignoreEntitiesOnPistonMove() const;
    MCAPI void initEntity(class EntityRegistry &);
    MCAPI void initParams(class RenderParams &, class BlockSource &, class BlockPos const &, class Actor *) const;
    MCAPI bool isAir() const;
    MCAPI bool isAttachedTo(class BlockSource &, class BlockPos const &, class BlockPos &) const;
    MCAPI bool isAuxValueRelevantForPicking() const;
    MCAPI bool isBounceBlock() const;
    MCAPI bool isButtonBlock() const;
    MCAPI bool isClimbable(struct IActorMovementProxy const &) const;
    MCAPI bool isContainerBlock() const;
    MCAPI bool isCropBlock() const;
    MCAPI bool isDoorBlock() const;
    MCAPI bool isEmpty() const;
    MCAPI bool isFenceBlock() const;
    MCAPI bool isFenceGateBlock() const;
    MCAPI bool isFilteredOut(enum BlockRenderLayer) const;
    MCAPI bool isHeavy() const;
    MCAPI bool isInteractiveBlock() const;
    MCAPI bool isLeverBlock() const;
    MCAPI bool isMotionBlockingBlock() const;
    MCAPI bool isMultifaceBlock() const;
    MCAPI bool isObstructingChests(class BlockSource &, class BlockPos const &) const;
    MCAPI bool isPartialBlock(class BlockSource const &, class BlockPos const &) const;
    MCAPI bool isPreservingMediumWhenPlaced(class Block const &) const;
    MCAPI bool isRailBlock() const;
    MCAPI bool isSignalSource() const;
    MCAPI bool isSlabBlock() const;
    MCAPI bool isSolid() const;
    MCAPI bool isSolidBlockingBlock() const;
    MCAPI bool isSolidBlockingBlockAndNotSignalSource() const;
    MCAPI bool isStairBlock() const;
    MCAPI bool isStandingSign() const;
    MCAPI bool isStemBlock() const;
    MCAPI bool isThinFenceBlock() const;
    MCAPI bool isTopPartialBlock(class BlockSource const &, class BlockPos const &) const;
    MCAPI bool isUnbreakable() const;
    MCAPI bool isWallBlock() const;
    MCAPI bool isWaterBlocking() const;
    MCAPI class Block const & keepState(class ItemState const &) const;
    MCAPI bool mayConsumeFertilizer(class BlockSource &) const;
    MCAPI bool mayPick(class BlockSource const &, bool) const;
    MCAPI bool mayPick() const;
    MCAPI bool mayPlace(class BlockSource &, class BlockPos const &) const;
    MCAPI bool mayPlace(class BlockSource &, class BlockPos const &, unsigned char) const;
    MCAPI bool mayPlaceOn(class BlockSource &, class BlockPos const &) const;
    MCAPI void movedByPiston(class BlockSource &, class BlockPos const &) const;
    MCAPI void neighborChanged(class BlockSource &, class BlockPos const &, class BlockPos const &) const;
    MCAPI void onExploded(class BlockSource &, class BlockPos const &, class Actor *) const;
    MCAPI void onFallOn(class BlockSource &, class BlockPos const &, class Actor &, float) const;
    MCAPI bool onFertilized(class BlockSource &, class BlockPos const &, class Actor *, enum FertilizerType) const;
    MCAPI void onLightningHit(class BlockSource &, class BlockPos const &) const;
    MCAPI void onPlace(class BlockSource &, class BlockPos const &, class Block const &) const;
    MCAPI void onPlayerPlacing(class BlockSource &, class BlockPos const &, class Actor &, unsigned char) const;
    MCAPI void onProjectileHit(class BlockSource &, class BlockPos const &, class Actor const &) const;
    MCAPI void onRemove(class BlockSource &, class BlockPos const &) const;
    MCAPI void onStandOn(class EntityContext &, class BlockPos const &) const;
    MCAPI void onStepOff(class Actor &, class BlockPos const &) const;
    MCAPI void onStepOn(class Actor &, class BlockPos const &) const;
    MCAPI void onStructureBlockPlace(class BlockSource &, class BlockPos const &) const;
    MCAPI void onStructureNeighborBlockPlace(class BlockSource &, class BlockPos const &) const;
    MCAPI void playerDestroy(class Player &, class BlockPos const &) const;
    MCAPI bool playerWillDestroy(class Player &, class BlockPos const &) const;
    MCAPI class ItemActor * popResource(class BlockSource &, class BlockPos const &, class ItemInstance const &) const;
    MCAPI bool pushesOutItems() const;
    MCAPI bool pushesUpFallingBlocks() const;
    MCAPI void queuedTick(class BlockSource &, class BlockPos const &, class Random &) const;
    MCAPI void randomTick(class BlockSource &, class BlockPos const &, class Random &) const;
    MCAPI class Vec3 randomlyModifyPosition(class BlockPos const &) const;
    MCAPI bool shouldRandomTick() const;
    MCAPI bool shouldRandomTickExtraLayer() const;
    MCAPI bool shouldStopFalling(class Actor &) const;
    MCAPI void spawnResources(class BlockSource &, class BlockPos const &, class Randomize &, std::vector<class Item const *> *, float, int) const;
    MCAPI void spawnResources(class BlockSource &, class BlockPos const &, class Block const &, class Randomize &, std::vector<class Item const *> *, float, int, class ItemStack const &) const;
    MCAPI int telemetryVariant(class BlockSource &, class BlockPos const &) const;
    MCAPI std::string toDebugString() const;
    MCAPI void transformOnFall(class BlockSource &, class BlockPos const &, class Actor *, float) const;
    MCAPI void triggerEvent(class BlockSource &, class BlockPos const &, int, int) const;
    MCAPI class CopperBehavior const * tryGetCopperBehavior() const;
    MCAPI class Block const * tryGetInfested() const;
    MCAPI class Block const * tryGetUninfested() const;
    MCAPI void trySpawnResourcesOnExplosion(class BlockSource &, class BlockPos const &, class Block const &, std::vector<class Item const *> *, float, int) const;
    MCAPI bool tryToPlace(class BlockSource &, class BlockPos const &, struct ActorBlockSyncMessage const *) const;
    MCAPI bool tryToTill(class BlockSource &, class BlockPos const &, class Actor &, class ItemStack &) const;
    MCAPI void updateEntityAfterFallOn(class BlockPos const &, struct UpdateEntityAfterFallOnInterface &) const;
    MCAPI bool updateTallestCollisionShape(class BlockSource const &, class BlockPos const &, class AABB const &, class optional_ref<class GetCollisionShapeInterface const>, class AABB &, class Vec3 const &, float &) const;
    MCAPI bool use(class Player &, class BlockPos const &, unsigned char) const;
    MCAPI static std::string const BLOCK_DESCRIPTION_PREFIX;
    MCAPI static float const SIZE_OFFSET;

//protected:
    MCAPI void buildSerializationId(unsigned int);
    MCAPI void setRuntimeId(unsigned int const &) const;

//private:
    MCAPI bool _isSolid() const;
    MCAPI class BlockTypeRegistryReadLock _lockRegistryForRead() const;
    MCAPI void _tryInitEntityIfNotInitialized();
    MCAPI class EntityContext const & getEntity() const;


protected:

private:


};