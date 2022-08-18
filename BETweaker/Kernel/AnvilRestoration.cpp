#include "../Global.h"

namespace Module {

	int UseOne(int title,bool add) {
		int temp = 0;
		if (add) {
			temp = -4;
		}
		else {
			temp = 4;
		}
		return title + temp;
	}

	bool AnvilRestoration(ItemStack* item,Block* block,BlockPos pos,Player* sp) {
		if (block->getTypeName() == "minecraft:anvil") {
			auto aux = block->getTileData();
			if (item->getTypeName() == "minecraft:iron_ingot") {
				auto out = UseOne(aux, true);
				if (out >= 0 && out <= 11) {
					Level::setBlock(pos, sp->getDimensionId(), "minecraft:anvil", out);
					auto items = sp->getHandSlot();
					items->remove(1);
				}
				return false;
			}
			else if (item->getTypeName() == "minecraft:obsidian") {
				auto out = UseOne(aux, false);
				if (out >= 0 && out <= 11) {
					Level::setBlock(pos, sp->getDimensionId(), "minecraft:anvil", out);
					auto items = sp->getHandSlot();
					items->remove(1);
				}
				return false;
			}
		}
		return true;
	}
}