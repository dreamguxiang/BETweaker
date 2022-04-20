#include "../Global.h"
#include "Module.h"
#include "setting.h"
#include <MC/LogBlock.hpp>

THook(void, "?updateSleepingPlayerList@ServerLevel@@UEAAXXZ", ServerLevel* self) {
	original(self);
	if (Settings::FastSleeping)
		Module::FastSleep();
}

THook(void, "?transformOnFall@FarmBlock@@UEBAXAEAVBlockSource@@AEBVBlockPos@@PEAVActor@@M@Z", void* __this, void* a2,
	void* a3, void* a4, float a5) {
	if (Settings::NoFarmDestroy) {
		return;
	}
	return original(__this, a2, a3, a4, a5);
}

THook(void, "?ejectItem@DispenserBlock@@IEBAXAEAVBlockSource@@AEBVVec3@@EAEBVItemStack@@AEAVContainer@@H@Z", DispenserBlock* a1,
	BlockSource* a2, Vec3* a3, FaceID a4, ItemStack* a5, Container* a6, unsigned int a7) {
	if (Module::DispenserItemFunc(a1, a2, a3, a4, a5, a6, a7))
		return;
	return original(a1, a2, a3, a4, a5, a6, a7);
}

THook(void, "?onRemove@LeafBlock@@UEBAXAEAVBlockSource@@AEBVBlockPos@@@Z",
	LeafBlock* _this, BlockSource* a2, const BlockPos* a3) {
	if (Settings::FastLeafDecay)
		Module::FastLeafDecayFunc1(_this, a2, a3);
	return original(_this, a2, a3);
}

THook(void, "?onRemove@LogBlock@@UEBAXAEAVBlockSource@@AEBVBlockPos@@@Z",
	LogBlock* _this, BlockSource* a2, const BlockPos* a3) {
	if (Settings::FastLeafDecay)
		Module::FastLeafDecayFunc1((LeafBlock*)_this, a2, a3);
	return original(_this, a2, a3);
}


THook(void, "?tick@Level@@UEAAXXZ", Level* _this) {
	if (Settings::FastLeafDecay)
	{
		Module::FastLeafDecayFunc();
	}
	return original(_this);
}

TInstanceHook(void, "?_updateServer@FishingHook@@IEAAXXZ", FishingHook) {
	if (Settings::AutoFish)
	{
		Module::AutoFish(this);
	}
	return original(this);
}

TInstanceHook(bool, "?use@DoorBlock@@UEBA_NAEAVPlayer@@AEBVBlockPos@@E@Z", DoorBlock, Player* pl, BlockPos* a3, UCHAR a4) {
	if (Settings::DoubleDoors && this->getTypeName() != "minecraft:iron_door")
		Module::DoubleDoors(this, pl, a3, a4);
	return  original(this, pl, a3, a4);
}

TInstanceHook(__int64, "?interact@Player@@QEAA_NAEAVActor@@AEBVVec3@@@Z",
	Player, Actor* a2, Vec3* a3) {
	if (Settings::FastSetMinecart) {
		if (this->isSneaking() && a2->getTypeName() == "minecraft:minecart")
			Module::FastSetMinecart(this, a2);
	}
	return original(this, a2, a3);
}
/*
#include <MC/ShovelItem.hpp>
#include <MC/ServerPlayer.hpp>
TInstanceHook(bool, "?_useOn@ShovelItem@@MEBA_NAEAVItemStack@@AEAVActor@@VBlockPos@@EAEBVVec3@@@Z"
	, ShovelItem, ItemStackBase* a2, Actor* a3, BlockPos& a4, char a5) {
	if (a3->isPlayer()) {
		auto sp = (ServerPlayer*)a3;
		auto block = Level::getBlock(a4, sp->getBlockSource());
		if (VanillaBlocks::mTopSnow && block == VanillaBlocks::mTopSnow) {
			auto i = block->getTileData();
			if (i > 2) {
				Level::setBlock(a4, sp->getDimensionId(), block->getTypeName(), i - 1);
			}
		}
	}
	return original(this, a2, a3, a4, a5);
}
*/


#include <MC/PlayerInventory.hpp>
#include <MC/GameMode.hpp>
#include <MC/Inventory.hpp>
TInstanceHook(void, "?useItem@Player@@UEAAXAEAVItemStackBase@@W4ItemUseMethod@@_N@Z", Player, ItemStackBase& item, int a2, bool a3)
{
	bool isfirst = false;
	auto itemname = item.getItem()->getSerializedName();
	original(this, item, a2, a3);
	if (item.getCount() == 0) {
		auto& inv = this->getInventory();
		for (int i = 1; i <= inv.getSize(); i++) {
			auto& item = inv.getItem(i);
			if (!item.isNull())
				if (item.getItem()->getSerializedName() == itemname) {
					if (!isfirst) {
						isfirst = true;
						continue;
					}
					auto snbt = const_cast<ItemStack*>(&item)->getNbt()->toSNBT();
					inv.setItem(i, ItemStack::EMPTY_ITEM);
					auto newitem = ItemStack::create(CompoundTag::fromSNBT(snbt));
					this->giveItem(newitem);
					delete newitem;
					this->sendInventory(1);
					break;
				}
		}
	}
	auto& plinv = this->getSupplies();
	std::cout << plinv.getFirstEmptySlot() << std::endl;
	auto inv = dAccess<Inventory*, 176>(&plinv);
	//std::cout << dAccess<uintptr_t, 0>(inf) - (uintptr_t)GetModuleHandle(NULL) << std::endl;
	
}
