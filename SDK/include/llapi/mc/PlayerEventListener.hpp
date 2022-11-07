// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PlayerEventListener {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PLAYEREVENTLISTENER
public:
    class PlayerEventListener& operator=(class PlayerEventListener const &) = delete;
    PlayerEventListener(class PlayerEventListener const &) = delete;
    PlayerEventListener() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_PLAYEREVENTLISTENER
    MCVAPI enum EventResult onCameraSetPlayerRot(class Player &, class Vec2 const &);
    MCVAPI enum EventResult onEvent(struct PlayerNotificationEvent const &);
    MCVAPI enum EventResult onLocalPlayerDeath(class IClientInstance &, class LocalPlayer &);
    MCVAPI enum EventResult onLocalPlayerRespawn(class IClientInstance &, class LocalPlayer &);
    MCVAPI enum EventResult onPlayerAIStepBegin(class Player &);
    MCVAPI enum EventResult onPlayerAIStepEnd(class Player &);
    MCVAPI enum EventResult onPlayerAction(class Player &, enum PlayerActionType, class BlockPos const &, int);
    MCVAPI enum EventResult onPlayerAttackedActor(class Player &, class Actor &);
    MCVAPI enum EventResult onPlayerAuthInputApplied(class Player &);
    MCVAPI enum EventResult onPlayerAuthInputReceived(class Player &);
    MCVAPI enum EventResult onPlayerAwardAchievement(class Player &, enum MinecraftEventing::AchievementIds);
    MCVAPI enum EventResult onPlayerCaravanChanged(class Actor const &, int);
    MCVAPI enum EventResult onPlayerCraftedItem(class Player &, class ItemInstance const &, bool, bool, bool, int, int, int, bool, bool, std::vector<short> const &);
    MCVAPI enum EventResult onPlayerCreated(class LocalPlayer &, std::string const &, std::string const &, bool);
    MCVAPI enum EventResult onPlayerDestroyedBlock(class Player &, int, int, int);
    MCVAPI enum EventResult onPlayerDestroyedBlock(class Player &, class Block const &);
    MCVAPI enum EventResult onPlayerEnchantedItem(class Player &, class ItemStack const &, class ItemEnchants const &);
    MCVAPI enum EventResult onPlayerEquippedArmor(class Player &, class ItemDescriptor const &);
    MCVAPI enum EventResult onPlayerInput(struct IPlayerMovementProxy &, class MoveInputHandler &);
    MCVAPI enum EventResult onPlayerItemEquipped(class Player &, class ItemInstance const &, int);
    MCVAPI enum EventResult onPlayerItemPlaceInteraction(class Player &, class ItemInstance const &);
    MCVAPI enum EventResult onPlayerItemUseInteraction(class Player &, class ItemInstance const &);
    MCVAPI enum EventResult onPlayerMove(class Player &);
    MCVAPI enum EventResult onPlayerMovementAnomaly(class Player &, class Vec3 const &, float, float);
    MCVAPI enum EventResult onPlayerMovementCorrected(class Player &, class Vec3 const &, float, float);
    MCVAPI enum EventResult onPlayerMovementRewindCorrected(class Player &, unsigned __int64);
    MCVAPI enum EventResult onPlayerNamedItem(class Player &, class ItemDescriptor const &);
    MCVAPI enum EventResult onPlayerOnGround(class Player &);
    MCVAPI enum EventResult onPlayerPiglinBarter(class Player &, std::string const &, bool);
    MCVAPI enum EventResult onPlayerPortalBuilt(class Player &, class AutomaticID<class Dimension, int>);
    MCVAPI enum EventResult onPlayerPortalUsed(class Player &, class AutomaticID<class Dimension, int>, class AutomaticID<class Dimension, int>);
    MCVAPI enum EventResult onPlayerSaved(class Player &);
    MCVAPI enum EventResult onPlayerSlide(class Player &);
    MCVAPI enum EventResult onPlayerStartRiding(class Player &, class Actor &);
    MCVAPI enum EventResult onPlayerStopRiding(class Player &, bool, bool, bool);
    MCVAPI enum EventResult onPlayerTargetBlockHit(class Player &, int);
    MCVAPI enum EventResult onPlayerTeleported(class Player &);
    MCVAPI enum EventResult onPlayerTick(class Player &);
    MCVAPI enum EventResult onPlayerTurn(class Player &, class Vec2 &);
    MCVAPI enum EventResult onPlayerWaxOnWaxOff(class Player &, int);
    MCVAPI enum EventResult onStartDestroyBlock(class Player &, class BlockPos const &, unsigned char &);
#endif

};