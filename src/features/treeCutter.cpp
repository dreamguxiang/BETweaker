#include <global.h>

enum class MaterialType;
namespace TreeCutter {
    std::unordered_set<string> LogBlocks{
        "minecraft:oak_log",
        "minecraft:spruce_log",
        "minecraft:birch_log",
        "minecraft:jungle_log",
        "minecraft:acacia_log",
        "minecraft:dark_oak_log",
        "minecraft:mangrove_log",
        "minecraft:cherry_log",
        "minecraft:warped_stem",
        "minecraft:crimson_stem",
    };
    std::unordered_set<string> LeafBlockss{
        "minecraft:leaves",
        "minecraft:leaves2",
        "minecraft:azalea_leaves",
        "minecraft:azalea_leaves_flowered",
        "minecraft:mangrove_leaves",
        "minecraft:nether_wart_block",
        "minecraft:warped_wart_block",
        "minecraft:shroomlight",
        "minecraft:cherry_leaves",
    };
    std::unordered_set<string> AxeList{
        "minecraft:wooden_axe",
        "minecraft:stone_axe",
        "minecraft:iron_axe",
        "minecraft:golden_axe",
        "minecraft:diamond_axe",
        "minecraft:netherite_axe"
    };

    class tree {
    private:
        int max = 1024;
        int leaves = 0;
        int call = 0;
        std::unordered_set<BlockPos> visited;

        std::vector<std::tuple<int, int, int>> directions = {
           {0, 0, 1}, {0, 0, -1}, {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {1, 0, 1}, {-1, 0, -1}, {1, 0, -1}, {-1, 0, 1},
           {1, 1, 1}, {-1, -1, -1}, {1, 1, -1}, {-1, -1, 1}, {1, -1, 1}, {-1, 1, -1}, {1, -1, -1}, {-1, 1, 1}

        };

        static bool isAxe(ItemStack& item, Player* sp) {
            if (!AxeList.count(item.getTypeName())) return false;
            auto lorelist = item.getCustomLore();
            if (lorelist.size() == 0 || lorelist[0] != I18N_GET("betweaker.cuttingtree.loreon", sp->getLanguageCode()))
                return false;
            return true;
        }

        void get(BlockInstance block) {
            call++;

            if (call >= max || block.getBlock()->getMaterial().isType(MaterialType(0)) || visited.count(block.getPosition())) {
                return;
            }

            if (LogBlocks.count(block.getBlock()->getTypeName())) {
                visited.insert(block.getPosition());
                for (int i = 0; i <= 9; i++)
                {
                    BlockPos pos = block.getPosition().add(std::get<0>(directions[i]), std::get<1>(directions[i]), std::get<2>(directions[i]));
                    auto bs = block.getBlockSource();
                    auto bl = BlockInstance::createBlockInstance(Level::getBlock(pos, bs), pos, bs->getDimensionId());
                    if (LogBlocks.count(bl.getBlock()->getTypeName()))
                    {
                        visited.insert(block.getPosition());
                        break;
                    }
                }
                for (int i = 0; i <= 17; i++)
                {
                    BlockPos pos = block.getPosition().add(std::get<0>(directions[i]), std::get<1>(directions[i]), std::get<2>(directions[i]));
                    auto bs = block.getBlockSource();
                    get(BlockInstance::createBlockInstance(Level::getBlock(pos, block.getBlockSource()), pos, bs->getDimensionId()));
                }
                return;
            }
            if (LeafBlockss.count(block.getBlock()->getTypeName())) {
                visited.insert(block.getPosition());
                leaves++;
            }
        }

        bool isTree() const {
            return leaves > 5;
        }

        void destroy(BlockSource* bs, Player* sp) {
            auto item = sp->getHandSlot();
            if (item->isNull()) {
                return;
            }

            for (auto& block : visited) {
                auto blockType = Level::getBlock(block, sp->getBlockSource())->getTypeName();
                if (LeafBlockss.count(blockType) == 0) {
                    Global<Level>->destroyBlock(*bs, block, 1);
                    item->hurtAndBreak(1, sp);
                    if (item->isNull()) {
                        break;
                    }
                }
            }
        }

    public:
        tree(BlockInstance block, BlockSource* bs, Player* sp) {
            auto item = sp->getHandSlot();
            if (!isAxe(*item, sp)) {
                return;
            }
            get(block);
            if (isTree()) {
                destroy(bs, sp);
            }
        }
    };

    void cutTree(BlockSource* bs, BlockPos a3, Player* sp) {
        auto blockType = bs->getBlock(a3).getTypeName();
        if (LogBlocks.count(blockType)) {
            auto& belowBlock = bs->getBlock(a3.add(0, -1, 0));
            auto belowBlockType = belowBlock.getTypeName();
            std::set<Block const*> allowedBlocks = { StaticVanillaBlocks::mDirt, StaticVanillaBlocks::mGrass, StaticVanillaBlocks::mMycelium, StaticVanillaBlocks::mPodzol, StaticVanillaBlocks::mMangroveRoots, StaticVanillaBlocks::mNetherrack, StaticVanillaBlocks::mCrimsonNylium, StaticVanillaBlocks::mWarpedNylium };
            if (allowedBlocks.count(&belowBlock) || LogBlocks.count(belowBlockType)) {
                for (int i = 0; i < 6; i++) {
                    BlockPos pos = a3.neighbor(i);
                    auto neighborBlock = Level::getBlock(pos, bs);
                    auto neighborBlockType = neighborBlock->getTypeName();
                    if (i == 1 && !TreeCutter::LogBlocks.count(neighborBlockType)) return;
                    if (TreeCutter::LogBlocks.count(neighborBlockType)) {
                        auto id = bs->getDimensionId();
                        auto bs = Level::getBlockSource(id);
                        TreeCutter::tree(BlockInstance::createBlockInstance(neighborBlock, pos, bs->getDimensionId()), bs, sp);
                    }
                }
            }
        }
    }

    void addLore(ItemStack* item, string lores) {
        auto nbt = item->getNbt();
        if (nbt->getCompound("tag") == nullptr)
            nbt->putCompound("tag", CompoundTag::create());
        if (nbt->getCompound("tag")->getCompound("display") == nullptr)
            nbt->getCompound("tag")->putCompound("display", CompoundTag::create());
        if (nbt->getCompound("tag")->getCompound("display")->getCompound("Lore") == nullptr)
            nbt->getCompound("tag")->getCompound("display")->put("Lore", ListTag::create());
        auto lore = nbt->getCompound("tag")->getCompound("display")->getList("Lore");
        lore->addString(lores);
        item->setNbt(nbt.get());
    }

    void cutTreeLore(Player* sp, ItemStack* item) {
        if (AxeList.count(item->getTypeName())) {
            auto lorelist = item->getCustomLore();
            vector<string> lore;

            auto loreOn = I18N_GET("betweaker.cuttingtree.loreon", sp->getLanguageCode());
            auto loreOff = I18N_GET("betweaker.cuttingtree.loreoff", sp->getLanguageCode());

            bool isLoreOn = lorelist.size() > 0 && lorelist[0] == loreOn;
            string newLore = isLoreOn ? loreOff : loreOn;
            string messageColor = isLoreOn ? "§a" : "§b";

            lore.push_back(newLore);
            item->setCustomLore(lore);
            sp->refreshInventory();
            sp->sendTextPacket(messageColor + "[BETweaker]" + newLore, TextType::JUKEBOX_POPUP);
        }
    }
}

LL_AUTO_TYPED_INSTANCE_HOOK(
    TreeCutterHook1,
    Block,
    HookPriority::Normal,
    "?playerWillDestroy@Block@@QEBA_NAEAVPlayer@@AEBVBlockPos@@@Z",
    bool,
    Player* player, const BlockPos* pos)
{
    if (!settings::CuttingTree) return origin(player,pos);
    try {
        TreeCutter::cutTree(&player->getRegion(), *pos, player);
    }
    catch (...) {
        return  origin(player, pos);
    }
    return origin(player, pos);
}

LL_AUTO_TYPED_INSTANCE_HOOK(
    TreeCutterHook2,
    GameMode,
    HookPriority::Normal,
    "?baseUseItem@GameMode@@QEAA_NAEAVItemStack@@@Z",
    bool,
    ItemStack* item){
    auto sp = getPlayer();
    try {
        if (settings::CuttingTree) {
            if (sp->isSneaking()) {
                TreeCutter::cutTreeLore(sp, sp->getHandSlot());
            }
        }
    }
    catch (...) {
        return origin(item);
    }
    return origin(item);
}
