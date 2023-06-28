#include <global.h>
#include <utils/time.h>

namespace AnvilRestoration {

	int UseOne(int title, bool add) {
		int temp = add ? -4 : 4;
		return title + temp;
	}

	bool AnvilRestoration(ItemStack* item, Block* block, BlockPos pos, Player* sp) {
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

LL_AUTO_TYPED_INSTANCE_HOOK(
	AnvilRestorationHook,
	GameMode,
	HookPriority::Low,
	"?useItemOn@GameMode@@UEAA?AVInteractionResult@@AEAVItemStack@@AEBVBlockPos@@EAEBVVec3@@PEBVBlock@@@Z",
	InteractionResult,
	ItemStack& item, BlockPos& blockPosPtr, unsigned char side, Vec3* clickPos, Block* block)
{
	auto sp = this->getPlayer();
	if (sp->isPlayer()) {
		if (settings::AnvilRestoration) {
			if (sp->isSneaking()) {
				auto blockin = Level::getBlockInstance(&blockPosPtr, &sp->getRegion());
				AnvilRestoration::AnvilRestoration(&item, blockin.getBlock(), blockin.getPosition(), sp);
			    return InteractionResult{ InteractionResult::Fail };;
			}
		}
	}
	return origin(item, blockPosPtr, side, clickPos, block);
}

