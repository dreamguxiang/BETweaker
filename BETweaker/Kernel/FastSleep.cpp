#include "../Global.h"
#include <MC/ServerLevel.hpp>
#include <MC/GameRules.hpp>
#include <MC/LevelSettings.hpp>
#include <MC/GameRuleId.hpp>
#include <MC/SetTimePacket.hpp>
#include <MC/LevelData.hpp>
#include <ScheduleAPI.h>
#include <MC/AttributeInstance.hpp>
#include <MC/Weather.hpp>
#include <MC/Attribute.hpp>
#include <MC/Dimension.hpp>
#include <MC/SharedAttributes.hpp>

static_assert(sizeof(GameRuleId) == 4);
static_assert(sizeof(SetTimePacket) == 56);
static ScheduleTask temp;
namespace Module {
    bool canFastSleep() {
        auto Probability = Settings::FastSleepProbability;
        auto sleepPlayerCount = sleepList.size();
        auto ActivePlayerCount = Global<Level>->getActivePlayerCount();
        if ((float)ActivePlayerCount * Probability <= (float)sleepPlayerCount) {
            return true;
        }
        return false;
    }
    void cancelSleep() {
        if (!canFastSleep()) {
            temp.cancel();
        }
    }
	
    void FastSleep() {
        Global<Level>->forEachPlayer([](Player& sp)->bool {
            if (sp.isSleeping()) {
                if (canFastSleep()) {
                    temp.cancel();
                    temp = Schedule::delay([]() {
                        auto level = Global<Level>;
                        auto& gameRule = level->getGameRules();
                        if (gameRule.getBool(GameRuleId(1), 0)) {
                            level->setTime((unsigned int)(24000 * ((level->getTime() + 24000) / 24000)));
                            auto pkt = SetTimePacket(level->getTime());
                            level->getPacketSender()->send(pkt);
                            Global<Level>->forEachPlayer([](Player& pl)->bool {
                                if (pl.isSleeping()) {
                                    pl.stopSleepInBed(0, 0);
                                    if (!(unsigned int)Global<Level>->getLevelData().getGameDifficulty())
                                    {
                                        auto att = pl.getMutableAttribute(SharedAttributes::HEALTH);
                                        att->resetToMaxValue();
                                        *((int*)&pl + 172) = 20;
                                        pl._sendDirtyActorData();
                                    }
                                }
                                return true;
                                });
                            *(bool*)(level + 10408) = 0;
                            level->forEachDimension([](Dimension& dim)->bool {
                                dim.getWeather().stop();
                                return true;
                                });
                        }
                        sleepList.clear();
                        }, 80);
                }
            }
            return true;
         });
    }
}
