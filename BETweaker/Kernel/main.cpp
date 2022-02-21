#include "pch.h"
#include <EventAPI.h>
#include <LoggerAPI.h>
#include <MC/Player.hpp>
#include <MC/BlockInstance.hpp>
#include <MC/Block.hpp>
#include <MC/CropBlock.hpp>
Logger logger("BetterHarvesting");
map<string, long > useitemonbug;


time_t getTimeStamp2()
{
    std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    auto tmp = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());
    std::time_t timestamp = tmp.count();
    return timestamp;
}
#include <MC/BlockLegacy.hpp>
#include <MC/ItemStack.hpp>
#include <MC/ItemInstance.hpp>
#include <mc/CompoundTag.hpp>
#include <MC/Level.hpp>
#include <MC/Randomize.hpp>
#include <MC/Random.hpp>
#include <MC/EnchantUtils.hpp>
bool PlayerUseOn(const Event::PlayerUseItemOnEvent& ev) {
    long a = getTimeStamp2();
    auto playername = ev.mPlayer->getRealName();
    for (auto iter = useitemonbug.rbegin(); iter != useitemonbug.rend(); iter++)
        if (iter->first == playername) {
            if (a - useitemonbug[playername] <= (long)50) {
                return false;
            }
        }
    useitemonbug[playername] = a;
    useitemonbug.insert(std::map < string, long > ::value_type(playername, a));
    auto blockin = ev.mBlockInstance;
    if (blockin.getBlock()->isCropBlock()) {
        auto& block = (CropBlock&)blockin.getBlock()->getLegacyBlock();
        auto growthlevel = blockin.getBlock()->getTileData();
        if (growthlevel == 7) {
            auto bs = blockin.getBlockSource();
            auto pos = blockin.getPosition();
            auto rand = Randomize(ev.mPlayer->getRandom());
            auto Crop = ItemStack::create();
            auto Seed = ItemStack::create();
            logger.warn("{}",dAccess<uintptr_t, 0>(&block) - (uintptr_t)GetModuleHandle(NULL));
            (*(void(__fastcall**)(BlockLegacy*, ItemStack*))(*(__int64*)&block + 1592i64))(&block, Crop);
            if (*((int64_t*)Crop + 1) && **((int64_t**)Crop + 1) && !Crop->isNull())
            {
                auto CropNum = SymCall("?getCropNum@CropBlock@@MEBAHAEAVRandomize@@HH@Z", bool, CropBlock&, Randomize&, int)(block, rand, growthlevel);
                if (CropNum) block.popResource(*bs, pos, *Crop);
            }
            (*(void(__fastcall**)(BlockLegacy*, ItemStack*))(*(__int64*)&block + 1584i64))(&block, Seed);
            if (*((int64_t*)Seed + 1) && **((int64_t**)Seed + 1) && !Seed->isNull())
            {
                auto level = EnchantUtils::getEnchantLevel(Enchant::Type::fortune, *ev.mPlayer->getHandSlot());
                //auto seedNum = block.getSeedNum(rand, 7, level);
                auto seedNum = SymCall("?getSeedNum@CropBlock@@MEBAHAEAVRandomize@@HH@Z", int, CropBlock&, Randomize&, int, int)(block, rand, growthlevel ,level);
                if (seedNum > 0)
                {
                    do {
                        block.popResource(*bs, pos, *Seed);
                        --seedNum;
                    } while (seedNum);
                }
            }
            Level::setBlock(blockin.getPosition(), blockin.getDimensionId(), blockin.getBlock()->getTypeName(), 1);
            delete Crop,Seed;
            return false;
        }
    }
    return true;
}

void PluginInit()
{
    Event::PlayerUseItemOnEvent::subscribe(PlayerUseOn);
	logger.info("Loaded success");


}