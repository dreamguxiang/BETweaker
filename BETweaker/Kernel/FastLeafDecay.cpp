#include "../Global.h"


namespace Module {

    std::unordered_set<string> LeafBlocks{
    "minecraft:leaves",
    "minecraft:leaves2",
    "minecraft:azalea_leaves",
    "minecraft:azalea_leaves_flowered"
    };

    std::stack<BlockPos> leafBlockPos;
    std::stack<int> leafBlockDim;

    bool FastLeafDecayFunc1(LeafBlock*, BlockSource* a2, const BlockPos* a3) 
{
        for (size_t i = 0; i < 6; i++)
        {
            BlockPos pos = a3->neighbor(i);
            if (LeafBlocks.count(Level::getBlock(pos, a2)->getTypeName()))
            {
                //std::cout << pos.toString() << std::endl;
                leafBlockPos.push(pos);
                leafBlockDim.push(a2->getDimensionId());
            }
        }
    }

    bool FastLeafDecayFunc() {
        if (leafBlockDim.size() == leafBlockPos.size() && !leafBlockDim.empty()) {
            BlockPos pos = leafBlockPos.top();
            leafBlockPos.pop();
            int dim = leafBlockDim.top();
            leafBlockDim.pop();
            Block* bl = Level::getBlockEx(pos, dim);
            if (!bl)
                return true;
            else if (LeafBlocks.count(bl->getTypeName()))
            {
                auto leaf = (LeafBlock*)(bl->getLegacyBlock()).createWeakPtr().get();
                auto bs = Level::getBlockSource(dim);
                leaf->randomTick(*bs, pos, Random::getThreadLocal());
                return true;
            }
        }
    }
}