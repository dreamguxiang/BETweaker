#include "pch.h"
#include <MC/CommandUtils.hpp>
#include <MC/SetActorDataPacket.hpp>
#include <MC/DataItem.hpp>
#include <MC/LoopbackPacketSender.hpp>
#include <MC/NetworkIdentifier.hpp>
#include <MC/Block.hpp>
#include <MC/Item.hpp>
#include <MC/PropertiesSettings.hpp>
#include <MC/Localization.hpp>
#include <MC/Material.hpp>
#include <MC/Monster.hpp>
#include <MC/HashedString.hpp>
#include <MC/Container.hpp>
#include <MC/SynchedActorData.hpp>
#include <ScheduleAPI.h>

static_assert(offsetof(SetActorDataPacket, mitems) == 64);
static_assert(sizeof(SetActorDataPacket) == 88);

namespace HUBHelper {
    string canDestroy(Block* block, ItemStack* tool) {
        auto& material = block->getMaterial();
        bool canDestory = material.isAlwaysDestroyable() || tool->canDestroySpecial(*block);
        if (!canDestory)return u8"§4§l✖§r§7";
        return u8"§a§l✔§r§7";
    }

    string getStandardName(ItemStackBase& item, string language)
    {

        I18n::chooseLanguage(language);
        string standardName = item.getItem()->buildDescriptionName(item);
        I18n::chooseLanguage(Global<PropertiesSettings>->getLanguage());
        return (standardName);
    };

    string getCategoryName(ItemStackBase& item, string language)
    {
        I18n::chooseLanguage(language);
        return item.getCategoryName();
    };

    string actorCategory(Actor* ac, Player* sp) {
        string out = u8"§c" + getI18n("betweaker.hubinfo.hostile");
        if (ac->findAttackTarget() != sp && !ac->isAngry())
            out = u8"§2" + getI18n("betweaker.hubinfo.frinedly");
        return out;
    }

    string getDim(Player& sp) {
        switch (sp.getDimensionId())
        {
        case 0:return u8"§g";
        case 1:return u8"§c";
        case 2:return u8"§d";
        }
    }
}

void HUBInfo() {
    auto info = Schedule::repeat([]() {
        Level::forEachPlayer([](Player& sp)->bool {
            Actor* ac = sp.getActorFromViewVector(5.25);
            auto posdim = HUBHelper::getDim(sp);
            if (ac) {
                auto pos = ac->getBlockPos().toVec3();
                sp.sendFormattedText(u8"§f{}\n§c❤ §a{}/{}\n§7X:{}{} §7Y:{}{} §7Z:{}{}\n§7{} {}",
                    Helper::getActorDisplayName(ac, sp.getLanguageCode()),
                    toStr(ac->getHealth()), toStr(ac->getMaxHealth()),
                    posdim, pos.x, posdim, pos.y, posdim, pos.z,
                    getI18n("betweaker.hubinfo.status"), HUBHelper::actorCategory(ac, &sp)
                );
            }
            else
            {
                auto bi = sp.getBlockFromViewVector();
                if (!bi.isNull()) {
                    auto block = bi.getBlock();
                    ItemInstance item = block->getSilkTouchItemInstance();
                    auto blpos = bi.getPosition();
                    sp.sendFormattedText(u8"§f{}\n§7{} §6{}\n{} {}\n§7X:{}{} §7Y:{}{} §7Z:{}{}\n{}",
                        Helper::getDisplayName(block->buildDescriptionId(), sp.getLanguageCode()),
                        getI18n("betweaker.hubinfo.destroytime"), fmt::format("{:.1f}s", 0.1 / sp.getDestroyProgress(*block)),
                        HUBHelper::canDestroy(block, sp.getHandSlot()), getI18n("betweaker.hubinfo.harvestable"),
                        posdim, blpos.x, posdim, blpos.y, posdim, blpos.z,
                        HUBHelper::getCategoryName(item, sp.getLanguageCode())
                    );
                }
            }
            });
        }, 5);
}
