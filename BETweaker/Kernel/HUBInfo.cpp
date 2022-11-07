#include "../Global.h"
#include <MC/CommandUtils.hpp>
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
#include "../Main/setting.h"
#include <MC/Dimension.hpp>
#include <MC/Abilities.hpp>

namespace HUBHelper {
    string canDestroy(Block* block, ItemStack* tool) {
        auto& material = block->getMaterial();
        bool canDestory = material.isAlwaysDestroyable() || tool->canDestroySpecial(*block);
        if (!canDestory)return "§4§l✖§r§7";
        return "§a§l✔§r§7";
    }

    string getStandardName(ItemStackBase& item, string language)
    {

        I18n::chooseLanguage(language);
        string standardName = const_cast<Item*>(item.getItem())->buildDescriptionName(item);
        I18n::chooseLanguage(Global<PropertiesSettings>->getLanguage());
        return (standardName);
    };

    string getCategoryName(ItemStackBase& item, string language)
    {
        I18n::chooseLanguage(language);
        auto out = item.getCategoryName();
        I18n::chooseLanguage(Global<PropertiesSettings>->getLanguage());
        return out;
    };
    Actor* findAttackTarget(Actor* a1) {
        char Bool; // al

        auto& DimensionConst = a1->getDimension();
        auto NearestAttackablePlayer = DimensionConst.fetchNearestAttackablePlayer(*a1, float(16.0));
        if (!NearestAttackablePlayer || !a1->canSee(*NearestAttackablePlayer))
        {
            return nullptr;
        }
        auto abilities = &dAccess<Abilities>(&NearestAttackablePlayer, 2508);//AbilityCommand::execute
        Bool = abilities->getBool(AbilitiesIndex::ExposedAbilityCount);
        if (!Bool)
            return NearestAttackablePlayer;
        return nullptr;
    }
	
    string actorCategory(Actor* ac, Player* sp) {
        string out = "§c" + getI18n("betweaker.hubinfo.hostile", sp->getLanguageCode());
        if (!ac->hasFamily("monster")) {
            if (findAttackTarget(ac) != sp && !ac->isAngry())
                out = "§2" + getI18n("betweaker.hubinfo.frinedly", sp->getLanguageCode());
        }
        return out;
    }
    string test(Block* block) {
        auto rand = Randomize(Random::getThreadLocal());
        if (block->getLegacyBlock().getResourceCount(rand, *block, 0) == 0)
            return " §l§6⚠️";
    }
    string getDim(Player& sp) {
        switch (sp.getDimensionId())
        {
        case 0:return "§g";
        case 1:return "§c";
        case 2:return "§d";
        }
    }
}

ScheduleTask hubinfo;
namespace Module {
    void HUBInfo() {
        Schedule::repeat([]() {
            Global<Level>->forEachPlayer([](Player& sp)->bool {
                if (Settings::NoHubList.find(sp.getRealName()) == std::end(Settings::NoHubList)){
                    Actor* ac = sp.getActorFromViewVector(5.25);
                    auto posdim = HUBHelper::getDim(sp);
                    string lang = sp.getLanguageCode();
                    if (Settings::HUBInfoShow == "TIP") {
                        if (ac) {
                            auto pos = ac->getBlockPos().toVec3();
                            sp.sendFormattedText("§f{}\n§c❤ §a{}/{}\n§7X:{}{} §7Y:{}{} §7Z:{}{}\n§7{} {}",
                                Helper::getActorDisplayName(ac, sp.getLanguageCode()),
                                toStr(ac->getHealth()), toStr(ac->getMaxHealth()),
                                posdim, pos.x, posdim, pos.y, posdim, pos.z,
                                getI18n("betweaker.hubinfo.status", lang), HUBHelper::actorCategory(ac, &sp)
                            );
                        }
                        else
                        {
                            auto bi = sp.getBlockFromViewVector();
                            if (!bi.isNull()) {
                                auto block = bi.getBlock();
                                ItemInstance item = block->getLegacyBlock().getSilkTouchItemInstance(*block);
                                auto blpos = bi.getPosition();

                                if (block->getTypeName() == "minecraft:redstone_wire")
                                {
                                    sp.sendFormattedText("§f{}\n§7{} §6{}\n{} {}\n§7X:{}{} §7Y:{}{} §7Z:{}{}\n{}\n§c{}§7:§e{}",
                                        Helper::getDisplayName(block->buildDescriptionId(), sp.getLanguageCode()),
                                        getI18n("betweaker.hubinfo.destroytime", lang), fmt::format("{:.1f}s", 0.1 / sp.getDestroyProgress(*block)),
                                        HUBHelper::canDestroy(block, sp.getHandSlot()), getI18n("betweaker.hubinfo.harvestable", lang),
                                        posdim, blpos.x, posdim, blpos.y, posdim, blpos.z,
                                        HUBHelper::getCategoryName(item, sp.getLanguageCode()),
                                        getI18n("betweaker.hubinfo.redstonelevel", lang),
                                        block->getNbt()->getCompoundTag("states")->getInt("redstone_signal")
                                    );
                                }
                                else
                                {
                                    sp.sendFormattedText("§f{}\n§7{} §6{}\n{} {}\n§7X:{}{} §7Y:{}{} §7Z:{}{}\n{}",
                                        Helper::getDisplayName(block->buildDescriptionId(), sp.getLanguageCode()),
                                        getI18n("betweaker.hubinfo.destroytime", lang), fmt::format("{:.1f}s", 0.1 / sp.getDestroyProgress(*block)),
                                        HUBHelper::canDestroy(block, sp.getHandSlot()), getI18n("betweaker.hubinfo.harvestable", lang),
                                        posdim, blpos.x, posdim, blpos.y, posdim, blpos.z,
                                        HUBHelper::getCategoryName(item, sp.getLanguageCode())
                                    );
                                }
                            }
                        }
                    }
                    else if (Settings::HUBInfoShow == "Scoreboard") {
                        if (ac) {
                            auto pos = ac->getBlockPos().toVec3();
                            sp.removeSidebar();
                            sp.setSidebar("HubInfo", vector<std::pair<string, int>>{
                                { fmt::format("§f{}", Helper::getActorDisplayName(ac, sp.getLanguageCode())), 0},
                                { fmt::format("§c❤ §a{}/{}", toStr(ac->getHealth()), toStr(ac->getMaxHealth())),1 },
                                { fmt::format("§7X:{}{}", posdim, pos.x), 2 },
                                { fmt::format("§7Y:{}{}", posdim, pos.y), 3 },
                                { fmt::format("§7Z:{}{}", posdim, pos.z), 4 },
                                { fmt::format("§7{} {}", getI18n("betweaker.hubinfo.status", lang), HUBHelper::actorCategory(ac, &sp)), 5 }
                            }, ObjectiveSortOrder::Ascending);
                        }
                        else
                        {
                            auto bi = sp.getBlockFromViewVector();
                            if (!bi.isNull()) {
                                auto block = bi.getBlock();
                                ItemInstance item = block->getLegacyBlock().getSilkTouchItemInstance(*block);
                                auto blpos = bi.getPosition();
                                sp.removeSidebar();
                                sp.setSidebar("HubInfo", vector<std::pair<string, int>>{
                                    { fmt::format("§f{}", Helper::getDisplayName(block->buildDescriptionId(), sp.getLanguageCode())), 0},
                                    { fmt::format("§7{} §6{}",  getI18n("betweaker.hubinfo.destroytime", lang), fmt::format("{:.1f}s", 0.1 / sp.getDestroyProgress(*block))),1 },
                                    { fmt::format("{} {}",  HUBHelper::canDestroy(block, sp.getHandSlot()), getI18n("betweaker.hubinfo.harvestable", lang)), 2 },
                                    { fmt::format("§7X:{}{}", posdim, blpos.x), 3 },
                                    { fmt::format("§7Y:{}{}", posdim, blpos.y), 4 },
                                    { fmt::format("§7Z:{}{}", posdim, blpos.z), 5 },
                                    { fmt::format("{}",HUBHelper::getCategoryName(item, sp.getLanguageCode())), 6 },
                                }, ObjectiveSortOrder::Ascending);
                            }
                        }
                    }
                }
                });
            }, 3);
    }
}
