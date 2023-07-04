#include "global.h"

namespace AutoSupplyItem {

	bool useItemSupply(Player* sp, ItemStackBase& item, string itemname, short aux) {
		auto& plinv = sp->getSupplies();
		auto slotnum = dAccess<int, 16>(&plinv);
		if (item.getCount() == 0) {
			auto& inv = sp->getInventory();
			for (int i = 0; i <= inv.getSize(); i++) {
				auto& invItem = inv.getItem(i);
				if (!invItem.isNull() && invItem.getItem()->getSerializedName() == itemname && invItem.getAuxValue() == aux) {
					if (i == slotnum) continue;
					if (invItem.getTypeName().find("map") != string::npos) {
						return false;
					}
					auto snbt = const_cast<ItemStack*>(&invItem)->getNbt()->toSNBT();
					auto& uid = sp->getUniqueID();
					Schedule::delay([snbt, uid, slotnum, i]() {
						auto newitem = ItemStack::create(CompoundTag::fromSNBT(snbt));
						auto sp = Global<Level>->getPlayer(uid);
						if (sp && sp->getHandSlot()->isNull()) {
							auto& inv = sp->getInventory();
							inv.setItem(i, ItemStack::EMPTY_ITEM);
							inv.setItem(slotnum, *newitem);
							sp->refreshInventory();
						}
						delete newitem;
						}, 1);
				}
			}
		}
		return true;
	}

	void useItemSupply(Player* sp, string itemname) {
		auto& plinv = sp->getSupplies();
		auto slotnum = dAccess<int, 16>(&plinv);
		auto& inv = sp->getInventory();
		for (int i = 0; i <= inv.getSize(); i++) {
			auto& invItem = inv.getItem(i);
			if (!invItem.isNull() && invItem.getItem()->getSerializedName() == itemname) {
				if (i == slotnum) continue;
				auto snbt = const_cast<ItemStack*>(&invItem)->getNbt()->toSNBT();
				auto& uid = sp->getUniqueID();
				Schedule::delay([snbt, uid, slotnum, i]() {
					auto newitem = ItemStack::create(CompoundTag::fromSNBT(snbt));
					auto sp = Global<Level>->getPlayer(uid);
					if (sp && sp->getHandSlot()->isNull()) {
						auto& inv = sp->getInventory();
						inv.setItem(i, ItemStack::EMPTY_ITEM);
						inv.setItem(slotnum, *newitem);
						sp->refreshInventory();
					}
					delete newitem;
					}, 1);
			}
		}
	}
}

LL_AUTO_TYPED_INSTANCE_HOOK(
	AutoSupplyItemHook1,
	Player,
	HookPriority::Normal,
	"?useItem@Player@@UEAAXAEAVItemStackBase@@W4ItemUseMethod@@_N@Z",
	void, ItemStackBase& item, int a2, bool a3
) {
	auto itemname = item.getItem()->getSerializedName();
	auto aux = item.getAuxValue();
	origin(item, a2, a3);
	try {
		if (settings::AutoSupplyItem) {
			AutoSupplyItem::useItemSupply(this, item, itemname, aux);
		}
	}
	catch (...) {
		return;
	}
}

LL_AUTO_TYPED_INSTANCE_HOOK(
	AutoSupplyItemHook2,
	ItemStack,
	HookPriority::Normal,
	"?hurtAndBreak@ItemStackBase@@QEAA_NHPEAVActor@@@Z",
	bool, int a1, Actor* a2
) {
	auto itemname = getItem()->getSerializedName();
	auto out = origin(a1, a2);
	try {
		if (settings::AutoSupplyItem && a2->isPlayer() && (int)getNbt()->getByte("Count") == 0) {
			AutoSupplyItem::useItemSupply((ServerPlayer*)a2, itemname);
		}
	}
	catch (...) {
		return out;
	}
	return out;
}