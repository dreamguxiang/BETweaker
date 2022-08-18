#include "../Global.h"
#include <MC/Randomize.hpp>
#include <MC/Attribute.hpp>
#include <MC/AttributeInstance.hpp>

namespace Module {
	
	int getXpByLevel(int level)
	{
		if (!(level / 15))
			return 2 * level + 7;
		if (level / 15 == 1)
			return 5 * (level - 15) + 37;
		return 9 * (level - 30) + 112;
	}

	int getCurrentExperience(Player* sp) {
		auto& attr = sp->getAttribute(Player::EXPERIENCE);
		return attr.getCurrentValue() * sp->getXpNeededForNextLevel();
	}

	int getExperience(Player* sp) {
		auto level = sp->getPlayerLevel();
		int val = 0;
		for (int i = 0; i < level; i++) {
			val += getXpByLevel(i);
		}
		val += getCurrentExperience(sp);
		return val;
	}

	bool reduceExperience(Player*sp,int xp) {
		auto attr = sp->getMutableAttribute(Player::EXPERIENCE);
		if (!attr) {
			return false;
		}
		auto currExp = getCurrentExperience(sp);
		if (xp <= currExp) {
			attr->setCurrentValue(static_cast<float>(currExp - xp) / sp->getXpNeededForNextLevel());
			return true;
		}
		attr->setCurrentValue(0);
		int needExp = xp - currExp;
		int level = sp->getPlayerLevel();
		while (level > 0) {
			sp->addLevels(-1);
			int levelXp = sp->getXpNeededForNextLevel();
			needExp -= levelXp;
			if (needExp < levelXp) {
				attr->setCurrentValue(levelXp - static_cast<float>(needExp) / sp->getXpNeededForNextLevel());
				return true;
			}
			level = sp->getPlayerLevel();
		}
		return false;
	}
	
	void BetterThanMending(Player* sp) {
		auto item = sp->getHandSlot();
		if (!item->isNull()) {
			if (EnchantUtils::hasEnchant(Enchant::Type::mending, *item)) {
				if (item->isDamageableItem()) {
					auto damageValue = item->getMaxDamage();//总耐久
					auto needFixDamageValue = damageValue / 10;//每次修复的耐久
					//auto nowDamageValue = damageValue - item->getDamageValue();//当前耐久
					auto needDamageValue = item->getDamageValue();//需要修复的耐久
					auto playerExp = getExperience(sp);
					if (needDamageValue != 0) {
						if (needDamageValue < needFixDamageValue) {
							needFixDamageValue = needDamageValue;
						}
						auto needExp = needFixDamageValue / 2;//每次修复所需的经验
						if (playerExp < needExp) {
							needExp = playerExp;
							needFixDamageValue = needExp * 2;
						}
						reduceExperience(sp, needExp);
						item->setDamageValue(needDamageValue - needFixDamageValue);
						sp->sendInventory(1);
					}
				}
			}
		}
	}
}