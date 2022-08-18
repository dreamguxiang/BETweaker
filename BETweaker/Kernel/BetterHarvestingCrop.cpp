#include "../Global.h"
#include <MC/NetherWartBlock.hpp>

static_assert(sizeof(Randomize) == 0x10);

namespace Module {

    bool LoadBetterHarvestingCrop(BlockInstance blockin, Player* sp) {
        auto bl = blockin.getBlock();
        if (bl->isCropBlock()) {
            auto growthlevel = bl->getTileData();
            if (growthlevel == 7) {
                auto& block = (CropBlock&)bl->getLegacyBlock();
                auto bs = blockin.getBlockSource();
                auto pos = blockin.getPosition();
                auto rand = Randomize(sp->getRandom());
                auto Crop = block.getBaseCrop();
                if (!Crop.isNull())
                {
                    auto CropNum = block.getCropNum(rand, growthlevel, 0);
                    if (CropNum)
                        block.popResource(*bs, pos, Crop);
                }
                auto Seed = block.getBaseSeed();
                if (!Seed.isNull())
                {
                    auto level = EnchantUtils::getEnchantLevel(Enchant::Type::fortune, *sp->getHandSlot());
                    auto seedNum = block.getSeedNum(rand, growthlevel, level);
                    --seedNum;
                    if (seedNum > 0)
                    {
                        do {
                            block.popResource(*bs, pos, Seed);
                            --seedNum;
                        } while (seedNum);
                    }
                }
                Level::setBlock(blockin.getPosition(), blockin.getDimensionId(), bl->getTypeName(), NULL);
                return true;
            }
        }

        if (bl->getTypeName() == "minecraft:nether_wart") {
            auto growthlevel = bl->getTileData();
            if (growthlevel == 3) {
                auto& block = (NetherWartBlock&)bl->getLegacyBlock();
                auto bs = blockin.getBlockSource();
                auto pos = blockin.getPosition();
                auto rand = Randomize(sp->getRandom());
                auto ResourceItem = block.getResourceItem(rand, *bl, NULL);
                if (!ResourceItem.isNull())
                {
                    auto level = EnchantUtils::getEnchantLevel(Enchant::Type::fortune, *sp->getHandSlot());
                    auto Num = block.getResourceCount(rand, *bl, level);
                    --Num;
                    if (Num > 0)
                    {
                        do {
                            block.popResource(*bs, pos, ResourceItem);
                            --Num;
                        } while (Num);
                    }
                }
                Level::setBlock(blockin.getPosition(), blockin.getDimensionId(), bl->getTypeName(), NULL);
            }
        }
        return true;
    }
}
