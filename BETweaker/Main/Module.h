#pragma once
#include "../Global.h"

namespace Module {
	bool LoadBetterHarvestingCrop(BlockInstance blockin, Player* sp);
	void FastSleep();
	bool EditSign(Player* pl, BlockInstance bi);
	void HUBInfo();
	bool FastLeafDecayFunc1(LeafBlock* a1, BlockSource* a2, const BlockPos* a3);
	bool FastLeafDecayFunc();
	bool DispenserItemFunc(BlockSource* a2, Vec3* a3, FaceID a4, ItemStack* a5);
	bool AutoFish(FishingHook* a1);
	bool DoubleDoors(DoorBlock* a1, Player* pl, BlockPos* a3, UCHAR a4);
	bool FastSetMinecart(Player* pl, Actor* ac);
	bool UseItemSupply(Player* sp, ItemStackBase& item, string itemname);
	bool UseItemSupply(Player* sp, string itemname);
	void cutTree(BlockSource* bs, BlockPos a3, Player* sp);
	void cutTreeLore(Player* sp, ItemStack* item);
	bool DispenserDestroy(BlockSource* a2, BlockPos* a3, ItemStack& a5, int, BlockPos* old);
}