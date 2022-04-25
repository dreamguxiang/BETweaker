#include "./Global.h"
#include <MC/Material.hpp>
#include <concurrencpp/concurrencpp.h>
#include <MC/ServerPlayer.hpp>
#include <MC/FeatureRegistry.hpp>

namespace Module {
    std::unordered_set<string> LogBlocks{
        "minecraft:log",
        "minecraft:log2"
    };
    std::unordered_set<string> LeafBlockss{
    "minecraft:leaves",
    "minecraft:leaves2",
    "minecraft:azalea_leaves",
    "minecraft:azalea_leaves_flowered"
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

    BlockPos test(BlockPos pos,int a1) {
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
        default:
            break;
        }
    }
	
    bool isAxe(ItemStack& item) {
		return AxeList.count(item.getTypeName());
    }
	
    void get(BlockInstance block) {
        call++;

        if (call >= max) {
            return;
        }

        if (block.getBlock()->getTypeName() == "minecraft:air") {
            return;
        }
        for (auto& blocks : visited) {
            if (blocks == block.getPosition()) return;
        }		
       
        if (LogBlocks.count(block.getBlock()->getTypeName())) {
            visited.push_back(block.getPosition());
            for (size_t i = 0; i < 9; i++)
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
            for (size_t i = 0; i < 17; i++)
            {
                auto a3 = block.getPosition();
               // BlockPos pos = a3.neighbor(i);
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

    boolean isTree() {
        return leaves > 5;
    }
	
    void destroy(BlockSource* bs,Player* sp) {
        auto item = sp->getHandSlot();
		for (auto& block : visited) {
            if (item->isNull()) {
                return;
            }
            Level::breakBlockNaturally(bs, block);
            item->hurtAndBreak(1, sp);
		}
    }
    public:
     tree(BlockInstance block,BlockSource* bs,Player* sp) {
         auto item = sp->getHandSlot();
		if (!isAxe(*item)) {
			 return;
		 }	
        get(block);
        if (isTree()) {		
            destroy(bs,sp);
        }
    }
    };

    void cutTree(BlockSource* bs,BlockPos a3,Player* sp) {
        if (bs->getBlock(a3.add(0, -1, 0)).getTypeName() == VanillaBlocks::mDirt->getTypeName()
            || bs->getBlock(a3.add(0, -1, 0)).getTypeName() == VanillaBlocks::mGrass->getTypeName()
            || bs->getBlock(a3.add(0, -1, 0)).getTypeName() == VanillaBlocks::mMycelium->getTypeName()
            || bs->getBlock(a3.add(0, -1, 0)).getTypeName() == VanillaBlocks::mPodzol->getTypeName()
            ) {
            for (size_t i = 0; i < 6; i++)
            {
                BlockPos pos = a3.neighbor(i);
                if (Module::LogBlocks.count(Level::getBlock(pos, bs)->getTypeName()))
                {
                    auto id = bs->getDimensionId();
                    // auto& uid = getPlayer()->getUniqueID();
                    // concurrencpp::runtime runtime;
                    // auto result = runtime.thread_executor()->submit([pos, id, a3, uid] {
                    auto bs = Level::getBlockSource(id);
                    // auto sp = Level::getPlayer(uid);
                     //if (sp) {
                    Module::tree(BlockInstance::createBlockInstance(Level::getBlock(pos, bs), pos, bs->getDimensionId()), bs, sp);
                    // }
                //     });
                }
            }
        }
    }
}