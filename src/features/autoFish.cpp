#include <global.h>

std::map<FishingHook*, int> fishingHook;

namespace AutoFishing {
    void AutoFish(FishingHook* a1) {
        auto pl = a1->getPlayerOwner();

        if (a1->_serverHooked() && !fishingHook.count(a1)) {
            fishingHook[a1] = 0;
            return;
        }
        else if (a1->_serverHooked() && fishingHook[a1] == 0) {
            fishingHook[a1] = 1;
            return;
        }
        else if (!a1->_serverHooked() && fishingHook[a1] == 1) {
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
                        if (item->getTypeName() == VanillaItemNames::FishingRod.getString()) {
                            item->getItem()->use(*item, *pl);
                        }
                    }
                }
                }, 10);
        }
    }
}

LL_AUTO_TYPED_INSTANCE_HOOK(
    AutoFishHook,
    FishingHook,
    HookPriority::Normal,
    "?_updateServer@FishingHook@@IEAAXXZ",
    void
) {
    if (settings::AutoFish)
    {
        try {
            AutoFishing::AutoFish(this);
        }
        catch (...) {
            return origin();
        }
    }
    return origin();
}