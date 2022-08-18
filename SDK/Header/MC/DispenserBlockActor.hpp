// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class DispenserBlockActor {

#define AFTER_EXTRA
// Add Member There
#define ENABLE_VIRTUAL_FAKESYMBOL_DISPENSERBLOCKACTOR
public:

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_DISPENSERBLOCKACTOR
public:
    class DispenserBlockActor& operator=(class DispenserBlockActor const &) = delete;
    DispenserBlockActor(class DispenserBlockActor const &) = delete;
    DispenserBlockActor() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_DISPENSERBLOCKACTOR
    MCVAPI std::unique_ptr<class BlockActorDataPacket> _getUpdatePacket(class BlockSource &);
    MCVAPI void _onUpdatePacket(class CompoundTag const &, class BlockSource &);
    MCVAPI class Container const * getContainer() const;
    MCVAPI class Container * getContainer();
    MCVAPI int getContainerSize() const;
    MCVAPI class ItemStack const & getItem(int) const;
    MCVAPI int getMaxStackSize() const;
    MCVAPI std::string getName() const;
    MCVAPI int getRandomSlot();
    MCVAPI void load(class Level &, class CompoundTag const &, class DataLoadHelper &);
    MCVAPI void onMove();
    MCVAPI bool save(class CompoundTag &) const;
    MCVAPI void serverInitItemStackIds(int, int, class std::function<void (int, class ItemStack const &)>);
    MCVAPI void setItem(int, class ItemStack const &);
    MCVAPI void startOpen(class Player &);
    MCVAPI void stopOpen(class Player &);
    MCVAPI ~DispenserBlockActor();
#endif
    MCAPI DispenserBlockActor(class BlockPos);
    MCAPI DispenserBlockActor(class BlockPos, enum BlockActorType);

};