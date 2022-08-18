#include "../Global.h"
#include <MC/Player.hpp>
#include <MC/PlayerInventory.hpp>
#include <MC/Tag.hpp>
namespace Module {
	
	bool UseItemSupply(Player* sp, ItemStackBase& item, string itemname,short aux) {
		auto& plinv = sp->getSupplies();
		auto slotnum = dAccess<int, 16>(&plinv);
		if (item.getCount() == 0) {
			auto& inv = sp->getInventory();
			for (int i = 0; i <= inv.getSize(); i++) {
				auto& item = inv.getItem(i);
				if (!item.isNull()) {
					if (item.getItem()->getSerializedName() == itemname) {
						if (item.getAuxValue() == aux) {
							if (i == slotnum) continue;
							if (item.getTypeName().find("map") != item.getTypeName().npos) {
								return false;
							}
							auto snbt = const_cast<ItemStack*>(&item)->getNbt()->toSNBT();
							auto& uid = sp->getUniqueID();
							Schedule::delay([snbt, uid, slotnum, i] {
								auto newitem = ItemStack::create(CompoundTag::fromSNBT(snbt));
								auto sp = Global<Level>->getPlayer(uid);
								if (sp) {
									if (sp->getHandSlot()->isNull()) {
										auto& inv = sp->getInventory();
										inv.setItem(i, ItemStack::EMPTY_ITEM);
										auto& plinv = sp->getSupplies();
										inv.setItem(slotnum, *newitem);
										sp->refreshInventory();
									}
								}
								delete newitem;
								}, 1);
						}
					}
				}			
			}
		}
	}
	bool UseItemSupply(Player* sp, string itemname) {
		auto& plinv = sp->getSupplies();
		auto slotnum = dAccess<int, 16>(&plinv);
		auto& inv = sp->getInventory();
		for (int i = 0; i <= inv.getSize(); i++) {
			auto& item = inv.getItem(i);
			if (!item.isNull()) {
				if (item.getItem()->getSerializedName() == itemname) {
					if (i == slotnum) 	continue;
					auto snbt = const_cast<ItemStack*>(&item)->getNbt()->toSNBT();
					auto& uid = sp->getUniqueID();
					Schedule::delay([snbt, uid, slotnum, i] {
						auto newitem = ItemStack::create(CompoundTag::fromSNBT(snbt));
						auto sp = Global<Level>->getPlayer(uid);
						if (sp) {
							if (sp->getHandSlot()->isNull()) {
								auto& inv = sp->getInventory();
								inv.setItem(i, ItemStack::EMPTY_ITEM);
								auto& plinv = sp->getSupplies();
								inv.setItem(slotnum,*newitem);
								sp->refreshInventory();
							}
						}
						delete newitem;
						}, 1);
				}

			}
		}
	}
	
}