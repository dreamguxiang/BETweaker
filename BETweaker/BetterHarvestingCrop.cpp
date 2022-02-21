#include "pch.h"

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
            auto Crop = CropBlockOff::getBaseCrop(&block);
            if (!Crop->isNull())
            {
                auto CropNum = CropBlockSym::getCropNum(block, rand, growthlevel);
                if (CropNum) 
                    block.popResource(*bs, pos, *Crop);
            }
            auto Seed = CropBlockOff::getBaseSeed(&block);
            if (!Seed->isNull())
            {
                auto level = EnchantUtils::getEnchantLevel(Enchant::Type::fortune, *sp->getHandSlot());
                auto seedNum = CropBlockSym::getSeedNum(block, rand, growthlevel,level);
                if (seedNum > 0)
                {
                    do {
                        block.popResource(*bs, pos, *Seed);
                        --seedNum;
                    } while (seedNum);
                }
            }
            Level::setBlock(blockin.getPosition(), blockin.getDimensionId(), bl->getTypeName(), NULL);
        }
    }
    return true;
}