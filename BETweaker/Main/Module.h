#pragma once
#include "../Global.h"

namespace Module {
	bool loadBetterHarvestingCrop(BlockInstance blockin, Player* sp);
	void FastSleep();
	bool editSign(Player* pl, BlockInstance bi);
	void HUBInfo();
	bool FastLeafDecayFunc1(LeafBlock*, BlockSource* a2, const BlockPos* a3);
	bool FastLeafDecayFunc();
}