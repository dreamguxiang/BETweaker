#include "../Global.h"

static_assert(sizeof(Randomize) == 0x10);

bool loadBetterHarvestingCrop(BlockInstance blockin,Player* sp) {
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
        }
    }
    return true;
}