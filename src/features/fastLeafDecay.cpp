#include <global.h>

namespace FastLeafDecay {
    std::unordered_set<string> LeafBlocks{
        "minecraft:leaves",
        "minecraft:leaves2",
        "minecraft:azalea_leaves",
        "minecraft:azalea_leaves_flowered",
        "minecraft:mangrove_leaves",
    };

    std::queue<std::pair<BlockPos, int>> leafBlockQueue;

    bool processLeafBlock() {
        if (leafBlockQueue.empty())
        {
            return true;
        }
        auto leafBlockData = leafBlockQueue.front();
        leafBlockQueue.pop();
        BlockPos pos = leafBlockData.first;
        int dim = leafBlockData.second;
        Block* bl = Level::getBlockEx(pos, dim);
        if (!bl)
            return true;
        else if (LeafBlocks.count(bl->getTypeName()))
        {
            auto leaf = (LeavesBlock*)(bl->getLegacyBlock()).createWeakPtr().get();
            auto bs = Level::getBlockSource(dim);
            leaf->randomTick(*bs, pos, Random::getThreadLocal());
            return true;
        }
    }

    void addLeafBlockToQueue(BlockSource* a1, const BlockPos* a2)
    {
        for (size_t i = 0; i < 6; i++)
        {
            BlockPos pos = a2->neighbor(i);
            if (LeafBlocks.count(Level::getBlock(pos, a1)->getTypeName()))
            {
                leafBlockQueue.push({ pos, a1->getDimensionId() });
            }
        }
    }

    void processLeafBlocks() {
        std::vector<std::thread> threads;
        for (size_t i = 0; i < 7 && !leafBlockQueue.empty(); i++)
        {
            threads.emplace_back(processLeafBlock);
        }
        for (auto& th : threads) {
            th.join();
        }
    }
}

LL_AUTO_TYPED_INSTANCE_HOOK(
    FastLeafDecayLeavesBlockHook,
    LeavesBlock,
    HookPriority::Normal,
    "?onRemove@LeavesBlock@@UEBAXAEAVBlockSource@@AEBVBlockPos@@@Z",
    void,
    BlockSource* a2, const BlockPos* a3)
{
    if (settings::FastLeafDecay) {
        try {
            FastLeafDecay::addLeafBlockToQueue(a2, a3);
        }
        catch (...) {
            return origin(a2, a3);
        }
    }
    return origin(a2, a3);
}

LL_AUTO_TYPED_INSTANCE_HOOK(
    FastLeafDecayLogBlockHook,
    LogBlock,
    HookPriority::Normal,
    "?onRemove@LogBlock@@UEBAXAEAVBlockSource@@AEBVBlockPos@@@Z",
    void,
    BlockSource* a2, const BlockPos* a3)
{
    if (settings::FastLeafDecay) {
        try {
            FastLeafDecay::addLeafBlockToQueue(a2, a3);
        }
        catch (...) {
            return origin(a2, a3);
        }
    }
    return origin(a2, a3);
}
