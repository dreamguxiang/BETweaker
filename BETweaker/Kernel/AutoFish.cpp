#include "../Global.h"

std::map<FishingHook*, int>fishingHook;
namespace Module {
	bool AutoFish(FishingHook* a1) {
        auto pl = a1->getPlayerOwner();
        if (a1->_serverHooked() && !fishingHook.count(a1))
        {
            if (!fishingHook.count(a1)) {
                fishingHook[a1] = 0;
                return true;
            }
        }
        else if (a1->_serverHooked() && fishingHook[a1] == 0)
        {
            fishingHook[a1] = 1;
            return true;
        }
        else if (!a1->_serverHooked() && fishingHook[a1] == 1)
        {
            ItemStack* item = pl->getHandSlot();
            item->getItem()->use(*item, *pl);
            fishingHook.erase(a1);
            pl->refreshInventory();
            auto& uid = pl->getUniqueID();
            Schedule::delay([uid]() {
                auto pl = Global<Level>->getPlayer(uid);
                if (pl->isPlayer())
                {
                    ItemStack* item = pl->getHandSlot();
                    if (!item->isNull()) {
                        if (item->getTypeName() == "minecraft:fishing_rod") {
                            item->getItem()->use(*item, *pl);
                        }
                    }
                }
                }, 10);
        }
	}
}