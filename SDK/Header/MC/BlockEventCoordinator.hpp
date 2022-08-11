// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class BlockEventCoordinator {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLOCKEVENTCOORDINATOR
public:
    class BlockEventCoordinator& operator=(class BlockEventCoordinator const &) = delete;
    BlockEventCoordinator(class BlockEventCoordinator const &) = delete;
    BlockEventCoordinator() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_BLOCKEVENTCOORDINATOR
#endif
    MCAPI class BlockGameplayHandler & getBlockGameplayHandler();
    MCAPI void registerBlockGameplayHandler(std::unique_ptr<class BlockGameplayHandler> &&);
    MCAPI void sendBlockDestroyedByPlayer(class Player &, class Block const &, class BlockPos const &);
    MCAPI void sendBlockDestructionStarted(class Player &, class BlockPos const &);
    MCAPI void sendBlockDestructionStopped(class Player &, class BlockPos const &, int);
    MCAPI void sendBlockExploded(class BlockPos const &, class Block const &, class Actor *);
    MCAPI void sendBlockInteractedWith(class Player &, class BlockPos const &);
    MCAPI void sendBlockMovedByPiston(class BlockPos const &, class BlockPos const &, enum PistonState);
    MCAPI void sendBlockPlacedByPlayer(class Player &, class Block const &, class BlockPos const &, bool);
    MCAPI enum CoordinatorResult sendEvent(class EventRef<struct BlockGameplayEvent<enum CoordinatorResult>> const &);
    MCAPI enum CoordinatorResult sendEvent(class EventRef<struct MutableBlockGameplayEvent<enum CoordinatorResult>>);
    MCAPI void sendEvent(class EventRef<struct BlockGameplayEvent<void>> const &);
    MCAPI void sendUnknownBlockReceived(class Level &, struct NewBlockID const &, unsigned short);

};