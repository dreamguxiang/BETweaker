// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here
class UserEntityIdentifierComponent;

#undef BEFORE_EXTRA

class Mob : public Actor {

#define AFTER_EXTRA
// Add Member There
public:
struct JumpPreventionResult {
    JumpPreventionResult() = delete;
    JumpPreventionResult(JumpPreventionResult const&) = delete;
    JumpPreventionResult(JumpPreventionResult const&&) = delete;
};

public:

    LIAPI bool refreshInventory();

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MOB
public:
    class Mob& operator=(class Mob const &) = delete;
    Mob(class Mob const &) = delete;
    Mob() = delete;
#endif


public:
    /*0*/ virtual bool hasComponent(class HashedString const &) const;
    /*7*/ virtual void outOfWorld();
    /*8*/ virtual void reloadHardcoded(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*9*/ virtual void reloadHardcodedClient(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*10*/ virtual void initializeComponents(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*13*/ virtual void _doInitialMove();
    /*14*/ virtual ~Mob();
    /*31*/ virtual float getInterpolatedBodyRot(float) const;
    /*32*/ virtual float getInterpolatedHeadRot(float) const;
    /*33*/ virtual float getInterpolatedBodyYaw(float) const;
    /*34*/ virtual float getYawSpeedInDegreesPerSecond() const;
    /*40*/ virtual void __unk_vfn_40();
    /*41*/ virtual void blockedByShield(class ActorDamageSource const &, class Actor &);
    /*43*/ virtual void teleportTo(class Vec3 const &, bool, int, int, bool);
    /*48*/ virtual void normalTick();
    /*49*/ virtual void baseTick();
    /*50*/ virtual void passengerTick();
    /*52*/ virtual bool startRiding(class Actor &);
    /*53*/ virtual void addPassenger(class Actor &);
    /*60*/ virtual void __unk_vfn_60();
    /*67*/ virtual void __unk_vfn_67();
    /*81*/ virtual void __unk_vfn_81();
    /*87*/ virtual void __unk_vfn_87();
    /*91*/ virtual bool isImmobile() const;
    /*94*/ virtual bool isPickable();
    /*95*/ virtual void __unk_vfn_95();
    /*96*/ virtual bool isSleeping() const;
    /*97*/ virtual void setSleeping(bool);
    /*98*/ virtual void __unk_vfn_98();
    /*100*/ virtual bool isBlocking() const;
    /*102*/ virtual bool isAlive() const;
    /*105*/ virtual void __unk_vfn_105();
    /*106*/ virtual bool isSurfaceMob() const;
    /*107*/ virtual void __unk_vfn_107();
    /*108*/ virtual void __unk_vfn_108();
    /*110*/ virtual void __unk_vfn_110();
    /*113*/ virtual void setTarget(class Actor *);
    /*115*/ virtual bool attack(class Actor &, enum ActorDamageCause const &);
    /*126*/ virtual bool canPowerJump() const;
    /*128*/ virtual bool isJumping() const;
    /*135*/ virtual enum ActorDamageCause getBlockDamageCause(class Block const &) const;
    /*136*/ virtual void animateHurt();
    /*137*/ virtual bool doFireHurt(int);
    /*141*/ virtual void handleEntityEvent(enum ActorEvent, int);
    /*155*/ virtual enum ArmorMaterialType getArmorMaterialTypeInSlot(enum ArmorSlot) const;
    /*156*/ virtual enum ArmorTextureType getArmorMaterialTextureTypeInSlot(enum ArmorSlot) const;
    /*157*/ virtual float getArmorColorInSlot(enum ArmorSlot, int) const;
    /*159*/ virtual void setEquippedSlot(enum EquipmentSlot, class ItemStack const &);
    /*173*/ virtual bool canFreeze() const;
    /*181*/ virtual void __unk_vfn_181();
    /*185*/ virtual void causeFallDamage(float, float, class ActorDamageSource);
    /*193*/ virtual bool canBePulledIntoVehicle() const;
    /*194*/ virtual bool inCaravan() const;
    /*195*/ virtual void __unk_vfn_195();
    /*199*/ virtual void stopRiding(bool, bool, bool);
    /*202*/ virtual void buildDebugInfo(std::string &) const;
    /*207*/ virtual int getDeathTime() const;
    /*218*/ virtual void swing();
    /*220*/ virtual void __unk_vfn_220();
    /*221*/ virtual void __unk_vfn_221();
    /*225*/ virtual float getYHeadRot() const;
    /*226*/ virtual void setYHeadRot(float);
    /*227*/ virtual float getYHeadRotO() const;
    /*246*/ virtual void __unk_vfn_246();
    /*249*/ virtual void __unk_vfn_249();
    /*250*/ virtual void kill();
    /*251*/ virtual void die(class ActorDamageSource const &);
    /*252*/ virtual bool shouldDropDeathLoot() const;
    /*265*/ virtual void updateEntitySpecificMolangVariables(class RenderParams &);
    /*267*/ virtual void __unk_vfn_267();
    /*268*/ virtual bool _hurt(class ActorDamageSource const &, float, bool, bool);
    /*271*/ virtual void readAdditionalSaveData(class CompoundTag const &, class DataLoadHelper &);
    /*272*/ virtual void addAdditionalSaveData(class CompoundTag &) const;
    /*273*/ virtual void _playStepSound(class BlockPos const &, class Block const &);
    /*275*/ virtual void __unk_vfn_275();
    /*282*/ virtual void _removePassenger(struct ActorUniqueID const &, bool, bool, bool);
    /*283*/ virtual void _onSizeUpdated();
    /*284*/ virtual void __unk_vfn_284();
    /*285*/ virtual void knockback(class Actor *, int, float, float, float, float, float);
    /*286*/ virtual void spawnAnim();
    /*287*/ virtual void setSprinting(bool);
    /*288*/ virtual enum LevelSoundEvent getHurtSound();
    /*289*/ virtual enum LevelSoundEvent getDeathSound();
    /*290*/ virtual struct TextureUVCoordinateSet const * getItemInHandIcon(class ItemStack const &, int);
    /*291*/ virtual float getSpeed() const;
    /*292*/ virtual void setSpeed(float);
    /*293*/ virtual void hurtEffects(class ActorDamageSource const &, float, bool, bool);
    /*294*/ virtual float getMeleeWeaponDamageBonus(class Mob *);
    /*295*/ virtual int getMeleeKnockbackBonus();
    /*296*/ virtual void travel(float, float, float);
    /*297*/ virtual void travel(struct IMobMovementProxy &, float, float, float) const;
    /*298*/ virtual void applyFinalFriction(float, bool);
    /*299*/ virtual void aiStep();
    /*300*/ virtual void aiStep(struct IMobMovementProxy &) const;
    /*301*/ virtual void pushActors();
    /*302*/ virtual void lookAt(class Actor *, float, float);
    /*303*/ virtual bool isLookingAtAnEntity();
    /*304*/ virtual bool checkSpawnRules(bool);
    /*305*/ virtual bool checkSpawnObstruction() const;
    /*306*/ virtual float getAttackAnim(float);
    /*307*/ virtual int getItemUseDuration() const;
    /*308*/ virtual float getItemUseStartupProgress() const;
    /*309*/ virtual float getItemUseIntervalProgress() const;
    /*310*/ virtual int getItemUseIntervalAxis() const;
    /*311*/ virtual int getTimeAlongSwing() const;
    /*312*/ virtual void __unk_vfn_312();
    /*313*/ virtual float getMaxHeadXRot();
    /*314*/ virtual bool isAlliedTo(class Mob *);
    /*315*/ virtual bool doHurtTarget(class Actor *, enum ActorDamageCause const &);
    /*316*/ virtual void __unk_vfn_316();
    /*317*/ virtual void leaveCaravan();
    /*318*/ virtual void joinCaravan(class Mob *);
    /*319*/ virtual bool hasCaravanTail() const;
    /*320*/ virtual struct ActorUniqueID getCaravanHead() const;
    /*321*/ virtual int getArmorValue() const;
    /*322*/ virtual float getArmorCoverPercentage() const;
    /*323*/ virtual int getToughnessValue() const;
    /*324*/ virtual void hurtArmorSlots(class ActorDamageSource const &, int, class std::bitset<4>);
    /*325*/ virtual void setDamagedArmor(enum ArmorSlot, class ItemStack const &);
    /*326*/ virtual void sendArmorDamage(class std::bitset<4>);
    /*327*/ virtual void sendArmor(class std::bitset<4>);
    /*328*/ virtual void containerChanged(int);
    /*329*/ virtual void updateEquipment();
    /*330*/ virtual int clearEquipment();
    /*331*/ virtual std::vector<int> getAllArmorID() const;
    /*332*/ virtual std::vector<class ItemStack const *> getAllHand() const;
    /*333*/ virtual std::vector<class ItemStack const *> getAllEquipment() const;
    /*334*/ virtual int getArmorTypeHash();
    /*335*/ virtual void dropEquipmentOnDeath(class ActorDamageSource const &, int);
    /*336*/ virtual void dropEquipmentOnDeath();
    /*337*/ virtual void clearVanishEnchantedItemsOnDeath();
    /*338*/ virtual void sendInventory(bool);
    /*339*/ virtual float getDamageAfterEnchantReduction(class ActorDamageSource const &, float) const;
    /*340*/ virtual float getDamageAfterArmorReduction(class ActorDamageSource const &, float) const;
    /*341*/ virtual float getDamageAfterResistanceEffect(class ActorDamageSource const &, float) const;
    /*342*/ virtual bool createAIGoals();
    /*343*/ virtual void onBorn(class Actor &, class Actor &);
    /*344*/ virtual bool setItemSlot(enum EquipmentSlot, class ItemStack const &);
    /*345*/ virtual void setTransitioningSitting(bool);
    /*346*/ virtual void attackAnimation(class Actor *, float);
    /*347*/ virtual int getAttackTime();
    /*348*/ virtual float _getWalkTargetValue(class BlockPos const &);
    /*349*/ virtual bool canExistWhenDisallowMob() const;
    /*350*/ virtual void __unk_vfn_350();
    /*351*/ virtual void ascendLadder();
    /*352*/ virtual void ascendBlockByJumping();
    /*353*/ virtual void descendBlockByCrouching();
    /*354*/ virtual void dropContainer();
    /*355*/ virtual std::unique_ptr<class BodyControl> initBodyControl();
    /*356*/ virtual void jumpFromGround();
    /*357*/ virtual void jumpFromGround(struct IMobMovementProxy &) const;
    /*358*/ virtual void updateAi();
    /*359*/ virtual void newServerAiStep();
    /*360*/ virtual void _serverAiMobStep();
    /*361*/ virtual void dropBags();
    /*362*/ virtual void tickDeath();
    /*363*/ virtual void updateGliding();
    /*364*/ virtual void __unk_vfn_364();
    /*365*/ virtual class AABB _getAdjustedAABBForSpawnCheck(class AABB const &, class Vec3 const &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_MOB
    MCVAPI bool _allowAscendingScaffolding() const;
    MCVAPI void ate();
    MCVAPI bool canBeControlledByPassenger();
    MCVAPI bool isShootable();
    MCVAPI void renderDebugServerState(class Options const &);
    MCVAPI bool useNewAi() const;
#endif
    MCAPI Mob(class Level &, class EntityContext &);
    MCAPI Mob(class ActorDefinitionGroup *, struct ActorDefinitionIdentifier const &, class EntityContext &);
    MCAPI void _endJump();
    MCAPI void addSpeedModifier(class mce::UUID const &, std::string const &, float);
    MCAPI float calcMoveRelativeSpeed(enum TravelType);
    MCAPI bool checkForPostHitDamageImmunity(float, class ActorDamageSource const &);
    MCAPI bool checkTotemDeathProtection(class ActorDamageSource const &);
    MCAPI void createAI(std::vector<struct GoalDefinition>);
    MCAPI bool discardFriction() const;
    MCAPI void emitJumpPreventedEvent(class BlockPos const &);
    MCAPI void frostWalk();
    MCAPI class BlockPos getBoundOrigin() const;
    MCAPI int getCaravanSize() const;
    MCAPI int getEatCounter() const;
    MCAPI class Mob * getFirstCaravanHead();
    MCAPI float getFlightSpeed() const;
    MCAPI float getFrictionModifier() const;
    MCAPI int getGlidingTicks() const;
    MCAPI class ItemStack const & getItemSlot(enum EquipmentSlot) const;
    MCAPI float getJumpEffectAmplifierValue();
    MCAPI float getJumpMultiplier();
    MCAPI float getJumpPower() const;
    MCAPI struct JumpPreventionResult getJumpPrevention();
    MCAPI float getMovementComponentCurrentSpeed() const;
    MCAPI int getNoActionTime() const;
    MCAPI float getPassengerLockedBodyRot() const;
    MCAPI float getPassengerRotLimit() const;
    MCAPI int getRollCounter() const;
    MCAPI float getSwimSpeedMultiplier() const;
    MCAPI struct ActorUniqueID getTargetCaptain() const;
    MCAPI enum TravelType getTravelType();
    MCAPI float getYRotA() const;
    MCAPI float getZza() const;
    MCAPI bool hasBoundOrigin() const;
    MCAPI void hurtArmor(class ActorDamageSource const &, int);
    MCAPI bool isAbleToMove() const;
    MCAPI bool isEating() const;
    MCAPI bool isFrostWalking() const;
    MCAPI bool isGliding() const;
    MCAPI bool isLayingEgg() const;
    MCAPI bool isPregnant() const;
    MCAPI bool isRolling() const;
    MCAPI bool isSprinting() const;
    MCAPI bool isTransitioningSitting() const;
    MCAPI void onPlayerDimensionChanged(class Player *, class AutomaticID<class Dimension, int>);
    MCAPI void onPlayerJump(int);
    MCAPI void removeSpeedModifier(class mce::UUID const &);
    MCAPI void resetAttributes();
    MCAPI void resetNoActionTime();
    MCAPI void sendArmorDamageSlot(enum ArmorSlot);
    MCAPI void sendArmorSlot(enum ArmorSlot);
    MCAPI void setEatCounter(int);
    MCAPI void setEating(bool);
    MCAPI void setFlightSpeed(float);
    MCAPI void setFrictionModifier(float);
    MCAPI void setIsLayingEgg(bool);
    MCAPI void setIsPregnant(bool);
    MCAPI void setJumpVelRedux(bool);
    MCAPI void setJumping(bool);
    MCAPI void setMovementComponentCurrentSpeed(float);
    MCAPI void setNaturallySpawned(bool);
    MCAPI void setPassengerLockedBodyRot(float);
    MCAPI void setPassengerRotLimit(float);
    MCAPI void setRolling(bool);
    MCAPI void setSpawnMethod(enum MobSpawnMethod);
    MCAPI void setSpeedModifier(float);
    MCAPI void setSurfaceMob(bool);
    MCAPI void setSwimSpeedMultiplier(float);
    MCAPI void setTargetCaptain(struct ActorUniqueID);
    MCAPI void setXxa(float);
    MCAPI void setYRotA(float);
    MCAPI void setYya(float);
    MCAPI void setZza(float);
    MCAPI void snapToYBodyRot(float);
    MCAPI void snapToYHeadRot(float);
    MCAPI static int const ARMOR_DAMAGE_DIVISOR;
    MCAPI static float const ARMOR_PROTECTION_DIVIDER;
    MCAPI static float const ASCEND_BLOCK_BY_JUMPING_SPEED;
    MCAPI static float const BASE_ARMOR_TOUGHNESS;
    MCAPI static float const DEFAULT_GRAVITY;
    MCAPI static float const FRICTION_CONSTANT;
    MCAPI static float const FRICTION_CONSTANT_MODIFIED;
    MCAPI static float const FRICTION_MODIFIER;
    MCAPI static float const GLIDING_FALL_RESET_DELTA;
    MCAPI static float const LADDER_CLIMB_SPEED;
    MCAPI static float const MAX_ARMOR;
    MCAPI static float const MIN_ARMOR_RATIO;
    MCAPI static float const NUM_ARMOR_ITEMS;
    MCAPI static float const PLAYER_SWIMMING_SURFACE_OFFSET;
    MCAPI static int const REMOVE_PASSENGERS_DELAY;
    MCAPI static float const SLOW_FALL_GRAVITY;
    MCAPI static int const SPAWN_XP_DELAY;
    MCAPI static int const TOTAL_ROLL_STEPS;
    MCAPI static void _aiStep(struct IMobMovementProxy &);
    MCAPI static float _calcMoveRelativeSpeed(struct IMobMovementProxy &, enum TravelType);
    MCAPI static void _travel(struct IMobMovementProxy &, float, float, float);
    MCAPI static void _updateMobTravel(struct IMobMovementProxy &);
    MCAPI static float calculateJumpImpulse(struct IMobMovementProxy const &);
    MCAPI static float getJumpEffectAmplifierValue(struct IMobMovementProxy const &);
    MCAPI static struct JumpPreventionResult getJumpPrevention(struct IMobMovementProxy const &);
    MCAPI static enum TravelType getTravelType(struct IMobMovementProxy &);
    MCAPI static bool isImmobile(struct IActorMovementProxy const &);
    MCAPI static bool shouldApplyWaterGravity(struct IActorMovementProxy const &);
    MCAPI static class Mob * tryGetFromEntity(class EntityContext &, bool);

//protected:
    MCAPI void _doSprintParticleEffect();
    MCAPI void _registerMobAttributes();
    MCAPI int getCurrentSwingDuration();
    MCAPI void processSoulSpeed();
    MCAPI std::unique_ptr<class ListTag> saveOffhand() const;
    MCAPI void tickEffects();
    MCAPI void updateAttackAnim();
    MCAPI bool updateGlidingDurability();
    MCAPI static void _jumpFromGround(struct IMobMovementProxy &);

//private:
    MCAPI bool _initHardCodedComponents();
    MCAPI void _initialize(class EntityContext &);
    MCAPI void _updateSprintingState();
    MCAPI void _verifyAttributes();
    MCAPI static bool _tryApplyingLevitation(struct IMobMovementProxy const &, class Vec3 &);


protected:
    MCAPI static int const MAX_INACTIVITY_TIMER;

private:


};