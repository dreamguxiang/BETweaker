#include <global.h>

// 使用 std::map 来存储钓鱼钩的状态
std::map<FishingHook*, int> fishingHook;

namespace AutoFishing {
    // 自动钓鱼函数，接收一个FishingHook指针作为参数
    bool AutoFish(FishingHook* a1) {
        auto pl = a1->getPlayerOwner(); // 获取钓鱼钩的拥有者

        // 如果钓鱼钩已经在服务器上并且还未被记录
        if (a1->_serverHooked() && !fishingHook.count(a1)) {
            fishingHook[a1] = 0; // 记录钓鱼钩状态
            return true;
        }
        // 如果钓鱼钩已经在服务器上并且状态是 0
        else if (a1->_serverHooked() && fishingHook[a1] == 0) {
            fishingHook[a1] = 1; // 更新钓鱼钩状态
            return true;
        }
        // 如果钓鱼钩不在服务器上并且状态是 1
        else if (!a1->_serverHooked() && fishingHook[a1] == 1) {
            ItemStack* item = pl->getHandSlot(); // 获取玩家手中的物品
            item->getItem()->use(*item, *pl); // 使用物品
            fishingHook.erase(a1); // 删除钓鱼钩的记录
            pl->refreshInventory(); // 刷新玩家的物品栏

            auto& uid = pl->getUniqueID(); // 获取玩家的唯一ID
            Schedule::delay([uid]() {
                auto pl = Global<Level>->getPlayer(uid); // 根据ID获取玩家
                if (pl->isPlayer()) // 如果是玩家
                {
                    ItemStack* item = pl->getHandSlot(); // 获取手中物品
                    if (!item->isNull()) {
                        if (item->getTypeName() == VanillaItemNames::FishingRod.getString()) {
                            item->getItem()->use(*item, *pl); // 如果是钓鱼竿则使用
                        }
                    }
                }
                }, 10); // 延迟10毫秒执行
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
    if (settings::AutoFish) // 如果设置中的AutoFish为真
    {
        try {
            AutoFishing::AutoFish(this); // 尝试执行自动钓鱼函数
        }
        catch (...) {
            return origin(); // 如果出现异常则返回原函数
        }
    }
    return origin(); // 返回原函数
}