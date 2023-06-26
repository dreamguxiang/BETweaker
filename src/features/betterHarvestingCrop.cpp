#include <global.h>
#include <utils/time.h>

namespace BetterHarvestingCrop {

    enum class CropType {
        Regular,
        NetherWart
    };

    template <CropType T>
    void harvestCrop(Block* bl, Player* sp, BlockInstance blockin,int growthlevel) {

        Randomize* random = ll::memory::createObject<Randomize,0x10>(sp->getRandom());
        if constexpr (T == CropType::Regular) {
            auto block = static_cast<CropBlock*>(const_cast<BlockLegacy*>(&bl->getLegacyBlock()));
            auto bs = blockin.getBlockSource();
            auto pos = blockin.getPosition();
            auto Crop = block->getBaseCrop();
            if (!Crop.isNull()) {
                auto CropNum = block->getCropNum(*random, growthlevel, 0);
                if (CropNum) block->popResource(*bs, pos, Crop);
            }
            auto Seed = block->getBaseSeed();
            if (!Seed.isNull()) {
                auto level = EnchantUtils::getEnchantLevel(Enchant::Type::fortune, *sp->getHandSlot());
                auto seedNum = block->getSeedNum(*random, growthlevel, level) - 1;
                while (seedNum-- > 0) block->popResource(*bs, pos, Seed);
            }
        }
        else if constexpr (T == CropType::NetherWart) {
            auto block = static_cast<NetherWartBlock*>(const_cast<BlockLegacy*>(&bl->getLegacyBlock()));
            auto bs = blockin.getBlockSource();
            auto pos = blockin.getPosition();
            auto ResourceItem = block->getResourceItem(*random, *bl, NULL);
            if (!ResourceItem.isNull()) {
                auto level = EnchantUtils::getEnchantLevel(Enchant::Type::fortune, *sp->getHandSlot());
                auto Num = block->getResourceCount(*random, *bl, level) - 1;
                while (Num-- > 0) block->popResource(*bs, pos, ResourceItem);
            }
        }
        Level::setBlock(blockin.getPosition(), blockin.getDimensionId(), bl->getTypeName(), NULL);
    }

    void handleCropHarvest(BlockInstance blockin, Player* sp) {
        auto bl = blockin.getBlock();
        if (bl->isCropBlock()) {
            auto growthlevel = bl->getTileData();
            if (growthlevel == 7) {
                harvestCrop<CropType::Regular>(bl,sp, blockin, growthlevel);
                return;
            }
        }
    }

    void handleNetherWartHarvest(BlockInstance blockin, Player* sp) {
        auto bl = blockin.getBlock();
        if (bl->getTypeName() == "minecraft:nether_wart") {
            auto growthlevel = bl->getTileData();
            if (growthlevel == 3) {
                harvestCrop<CropType::NetherWart>(bl, sp, blockin, growthlevel);
                return;
            }
        }
    }


    void loadBetterHarvestingCrop(BlockInstance blockin, Player* sp) {
        handleCropHarvest(blockin, sp);
        handleNetherWartHarvest(blockin, sp);
    }
};

LL_AUTO_TYPED_INSTANCE_HOOK(
    BetterHarvestingCropHook,
    GameMode,
    HookPriority::High,
    "?useItemOn@GameMode@@UEAA?AVInteractionResult@@AEAVItemStack@@AEBVBlockPos@@EAEBVVec3@@PEBVBlock@@@Z",
    InteractionResult,
    ItemStack& item, BlockPos& blockPosPtr, unsigned char side, Vec3* clickPos, Block* block)
{
    auto sp = this->getPlayer();
    if (sp->isPlayer()) {
        if (!utils::debounceCheck(sp->getRealName())) {
            return InteractionResult{ InteractionResult::Fail };
        }
        utils::debounceUpdateTime(sp->getRealName());
        BetterHarvestingCrop::loadBetterHarvestingCrop(Level::getBlockInstance(blockPosPtr, &sp->getRegion()), sp);
    }
    return origin(item, blockPosPtr, side, clickPos, block);
}

