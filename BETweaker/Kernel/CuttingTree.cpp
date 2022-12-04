#include "../Global.h"
#include <MC/Material.hpp>
#include <MC/ServerPlayer.hpp>
#include <MC/FeatureRegistry.hpp>
#include <MC/ListTag.hpp>
#include <mc/PlayerInventory.hpp>
#include <MC/BedrockBlocks.hpp>
enum class MaterialType;
namespace Module {
    std::unordered_set<string> LogBlocks{
        "minecraft:log",
        "minecraft:log2",
        "minecraft:mangrove_log",
        "minecraft:crimson_stem",
        "minecraft:warped_stem"
    };
    std::unordered_set<string> LeafBlockss{
    "minecraft:leaves",
    "minecraft:leaves2",
    "minecraft:azalea_leaves",
    "minecraft:azalea_leaves_flowered",
    "minecraft:mangrove_leaves",
	"minecraft:nether_wart_block",
    "minecraft:warped_wart_block"
    "minecraft:shroomlight"
    };

    std::unordered_set<string> AxeList{
        "minecraft:wooden_axe",
		"minecraft:stone_axe",
		"minecraft:iron_axe",
		"minecraft:golden_axe",
		"minecraft:diamond_axe",
		"minecraft:netherite_axe"
    };
	class tree{
    private:
        int max = 1024;
        int leaves = 0;
        int call = 0;
        std::list<BlockPos> visited;

    static BlockPos test(BlockPos pos,int a1) {
        switch (a1)
        {
        case 0:
            return pos.add(0, 0, 1);
        case 1:
            return pos.add(0, 0, -1);
        case 2:
            return pos.add(1, 0, 0);
        case 3:
            return pos.add(-1, 0, 0);		
        case 4:
            return pos.add(1, 0, 1);
        case 5:
            return pos.add(-1, 0, -1);
        case 6:
            return pos.add(1, 0, -1);
        case 7:
			return pos.add(-1, 0, 1);		
        case 8:
            return pos.add(-1, 1, -1);
        case 9:
            return pos.add(1, 1, -1);
        case 10:
            return pos.add(-1, 1, 1);
        case 11:
            return pos.add(1, 1, 1);
        case 12:
            return pos.add(-1, 1, 0);
        case 13:
            return pos.add(1, 1, 0);
        case 14:
            return pos.add(0, 1, 1);
        case 15:
            return pos.add(0, 1, 1);
        case 16:
            return pos.add(0, 1, 0);
        case 17:
            return pos.add(0, -1, 0);
        default:
            break;
        }
    }
	
    static bool isAxe(ItemStack& item,Player* sp) {
        if (!AxeList.count(item.getTypeName())) return false;
        auto lorelist = item.getCustomLore();
		if(lorelist.size() == 0 || lorelist[0] != getI18n("betweaker.cuttingtree.loreon", sp->getLanguageCode()))
            return false;
		return true;
    }
	
    void get(BlockInstance block) {
        call++;

        if (call >= max) {
            return;
        }

        if (block.getBlock()->getMaterial().isType(MaterialType(0))) {
            return;
        }
        for (auto& blocks : visited) {
            if (blocks == block.getPosition()) return;
        }		
       
        if (LogBlocks.count(block.getBlock()->getTypeName())) {
            visited.push_back(block.getPosition());
            for (int i = 0; i <= 7; i++)
            {
                auto a3 = block.getPosition();
                BlockPos pos = test(block.getPosition(), i);
                auto bs = block.getBlockSource();
                auto bl = BlockInstance::createBlockInstance(Level::getBlock(pos, bs), pos, bs->getDimensionId());
                if (LogBlocks.count(bl.getBlock()->getTypeName()))
                {
                    visited.push_back(bl.getPosition());
                    break;
                }
            }
            for (int i = 0; i <= 17; i++)
            {
                auto a3 = block.getPosition();
                //BlockPos pos = a3.neighbor(i);
                BlockPos pos = test(block.getPosition(), i);
                auto bs = block.getBlockSource();
                get(BlockInstance::createBlockInstance(Level::getBlock(pos, bs), pos, bs->getDimensionId()));               
            }
            return;
        }
        if (LeafBlockss.count(block.getBlock()->getTypeName())) {
            visited.push_back(block.getPosition());
            leaves++;
        }
    }

    bool isTree() const {
        return leaves > 5;
    }
	
    void destroy(BlockSource* bs,Player* sp) {
        auto item = sp->getHandSlot();
		for (auto& block : visited) {
            if (item->isNull()) {
                return;
            }
            if (LeafBlockss.count(Level::getBlock(block,sp->getBlockSource())->getTypeName())) {
                continue;
            }
            Global<Level>->destroyBlock(*bs, block, 1);			
            item->hurtAndBreak(1, sp);
		}
    }
      public:
     tree(BlockInstance block,BlockSource* bs,Player* sp) {
         auto item = sp->getHandSlot();
		if (!isAxe(*item,sp)) {
			 return;
		 }	
        get(block);
        if (isTree()) {	
            destroy(bs,sp);
        }
    }
    };

    void cutTree(BlockSource* bs, BlockPos a3, Player* sp) {
		if(LogBlocks.count(bs->getBlock(a3).getTypeName())){
            if (bs->getBlock(a3.add(0, -1, 0)).getTypeName() ==  "minecraft:dirt"
                || bs->getBlock(a3.add(0, -1, 0)) == *VanillaBlocks::mGrass
                || bs->getBlock(a3.add(0, -1, 0)).getTypeName() ==  "minecraft:mycelium"
                || bs->getBlock(a3.add(0, -1, 0)).getTypeName() == "minecraft:podzol"
                || bs->getBlock(a3.add(0, -1, 0)) == *VanillaBlocks::mMangroveRoots
                || bs->getBlock(a3.add(0, -1, 0)).getTypeName() == "minecraft:netherrack"
                || bs->getBlock(a3.add(0, -1, 0)) == *VanillaBlocks::mCrimsonNylium
                || bs->getBlock(a3.add(0, -1, 0)) == *VanillaBlocks::mWarpedNylium
                || LogBlocks.count(bs->getBlock(a3.add(0, -1, 0)).getTypeName())
                ) {
                for (int i = 0; i < 6; i++)
                {  
                    BlockPos pos = a3.neighbor(i);
                    if (i == 1 && !Module::LogBlocks.count(Level::getBlock(pos, bs)->getTypeName())) return;
                    if (Module::LogBlocks.count(Level::getBlock(pos, bs)->getTypeName()))
                    {
                        auto id = bs->getDimensionId();
                        auto bs = Level::getBlockSource(id);
                        Module::tree(BlockInstance::createBlockInstance(Level::getBlock(pos, bs), pos, bs->getDimensionId()), bs, sp);
                    }
                }
            }
        }
    }
	
    void addLore(ItemStack* item,string lores) {
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
            if (!sp->isSneaking()) return;
            auto lorelist = item->getCustomLore();
            vector<string> lore;
            if (lorelist.size() == 0)
            {
                lore.push_back(getI18n("betweaker.cuttingtree.loreon", sp->getLanguageCode()));
                item->setCustomLore(lore);
                sp->refreshInventory();
                sp->sendTextPacket("§b[BETweaker-Axe]"+ getI18n("betweaker.cuttingtree.loreon", sp->getLanguageCode()), TextType::JUKEBOX_POPUP);
            }
            else
            {
                if (lorelist[0] == getI18n("betweaker.cuttingtree.loreon", sp->getLanguageCode())) {
                    lore.push_back(getI18n("betweaker.cuttingtree.loreoff", sp->getLanguageCode()));
                    item->setCustomLore(lore);
                    sp->refreshInventory();
                    sp->sendTextPacket("§a[BETweaker-Axe]"+ getI18n("betweaker.cuttingtree.loreoff", sp->getLanguageCode()), TextType::JUKEBOX_POPUP);
                }
                else {
                    lore.push_back(getI18n("betweaker.cuttingtree.loreon", sp->getLanguageCode()));
                    item->setCustomLore(lore);					
                    sp->refreshInventory();
                    sp->sendTextPacket("§b[BETweaker-Axe]"+ getI18n("betweaker.cuttingtree.loreon", sp->getLanguageCode()), TextType::JUKEBOX_POPUP);
                }
            }
        }
    }
}