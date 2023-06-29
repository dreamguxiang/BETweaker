#include "global.h"

namespace BetterThanMending {

    int getExperienceByLevel(int level) {
        if (level < 15) {
            return 2 * level + 7;
        }
        else if (level < 30) {
            return 5 * (level - 15) + 37;
        }
        else {
            return 9 * (level - 30) + 112;
        }
    }

    int getCurrentExperience(Player* player) {
        auto& attr = player->getAttribute(Player::EXPERIENCE);
        return attr.getCurrentValue() * player->getXpNeededForNextLevel();
    }

    int getTotalExperience(Player* player) {
        int level = player->getPlayerLevel();
        int totalExp = 0;
        for (int i = 0; i < level; i++) {
            totalExp += getExperienceByLevel(i);
        }
        totalExp += getCurrentExperience(player);
        return totalExp;
    }

    bool reduceExperience(Player* player, int xp) {
        auto attr = player->getMutableAttribute(Player::EXPERIENCE);
        if (!attr) {
            return false;
        }
        auto currExp = getCurrentExperience(player);
        if (xp <= currExp) {
            attr->setCurrentValue(static_cast<float>(currExp - xp) / player->getXpNeededForNextLevel());
            return true;
        }
        attr->setCurrentValue(0);
        int needExp = xp - currExp;
        int level = player->getPlayerLevel();
        while (level > 0) {
            player->addLevels(-1);
            int levelXp = player->getXpNeededForNextLevel();
            needExp -= levelXp;
            if (needExp < levelXp) {
                attr->setCurrentValue(levelXp - static_cast<float>(needExp) / player->getXpNeededForNextLevel());
                return true;
            }
            level = player->getPlayerLevel();
        }
        return false;
    }

    void betterThanMending(Player* player) {
        auto item = player->getHandSlot();
        if (!item->isNull() && EnchantUtils::hasEnchant(Enchant::Type::mending, *item) && item->isDamageableItem()) {
            auto maxDamage = item->getMaxDamage();
            auto fixDamage = maxDamage / 10;
            auto currentDamage = item->getDamageValue();
            auto playerExp = getTotalExperience(player);
            if (currentDamage != 0 && currentDamage < fixDamage) {
                fixDamage = currentDamage;
            }
            auto expToReduce = std::min(fixDamage / 2, playerExp);
            reduceExperience(player, expToReduce);
            item->setDamageValue(currentDamage - fixDamage);
            player->sendInventory(1);
        }
    }
}


LL_AUTO_TYPED_INSTANCE_HOOK(
    BetterThanMendingHook,
    GameMode,
    HookPriority::Normal,
    "?baseUseItem@GameMode@@QEAA_NAEAVItemStack@@@Z",
    bool,
    ItemStack* item)
{
    auto sp = getPlayer();
    try {
        if (settings::BetterThanMending) {
            if (sp->isSneaking()) {
                BetterThanMending::betterThanMending(sp);
            }
        }
    }
    catch (...) {
        return origin(item);
    }
    return origin(item);
}
