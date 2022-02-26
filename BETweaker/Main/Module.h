#pragma once
#include "../Global.h"

namespace Module {
	bool loadBetterHarvestingCrop(BlockInstance blockin, Player* sp);
	void FastSleep();
	bool editSign(Player* pl, BlockInstance bi);
	void HUBInfo();
	bool FastLeafDecayFunc1(LeafBlock* a1, BlockSource* a2, const BlockPos* a3);
	bool FastLeafDecayFunc();
	bool DispenserItemFunc(DispenserBlock* a1, BlockSource* a2, Vec3* a3, FaceID a4, ItemStack* a5, Container* a6, unsigned int a7);
	bool AutoFish(FishingHook* a1);
}