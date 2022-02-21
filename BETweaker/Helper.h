#pragma once
#include "pch.h"

namespace CropBlockSym {
	inline bool getCropNum(CropBlock& block, Randomize& rand, int growthlevel) {
		return SymCall("?getCropNum@CropBlock@@MEBAHAEAVRandomize@@HH@Z", bool, CropBlock&, Randomize&, int)(block, rand, growthlevel);
	}
	inline int getSeedNum(CropBlock& block, Randomize& rand, int growthlevel, int level) {
		return SymCall("?getSeedNum@CropBlock@@MEBAHAEAVRandomize@@HH@Z", int, CropBlock&, Randomize&, int, int)(block, rand, growthlevel, level);
	}
}

namespace CropBlockOff {
	inline ItemStack* getBaseCrop(CropBlock* block) {
		auto item = ItemStack::create();
		return VirtualCall<ItemStack*>(block, 1592, item);
	}
	inline ItemStack* getBaseSeed(CropBlock* block) {
		auto item = ItemStack::create();
		return VirtualCall<ItemStack*>(block,1584, item);
	}
}