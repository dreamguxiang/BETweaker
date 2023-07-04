#include <global.h>

namespace FastLeafDecay {
    std::unordered_set<string> LeafBlocks{
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

    std::stack<BlockPos> leafBlockPos;
    std::stack<int> leafBlockDim;

    void processLeafBlock() {
        if (leafBlockDim.empty())
        {
            return;
        }
        BlockPos pos = leafBlockPos.top();
        leafBlockPos.pop();
        int dim = leafBlockDim.top();
        leafBlockDim.pop();
        Block* bl = Level::getBlockEx(pos, dim);
        if (!bl)
            return;
        else if (LeafBlocks.count(bl->getTypeName()))
        {
            auto leaf = (LeavesBlock*)(bl->getLegacyBlock()).createWeakPtr().get();
            auto bs = Level::getBlockSource(dim);
            leaf->randomTick(*bs, pos, Random::getThreadLocal());
            return;
        }
    }

    void addLeafBlockToQueue(BlockSource* a1, const BlockPos* a2)
    {
        for (size_t i = 0; i < 6; i++)
        {
            BlockPos pos = a2->neighbor(i);
            if (LeafBlocks.count(Level::getBlock(pos, a1)->getName().getString()))
            {
                leafBlockPos.push(pos);
                leafBlockDim.push(a1->getDimensionId());
            }
        }
    }

    void processLeafBlocks() {
        if (leafBlockDim.empty())
        {
            return;
        }
        else if (leafBlockDim.size() == leafBlockPos.size())
        {
            std::thread a[7];
            for (size_t i = 0; i < 7; i++)
            {
                a[i] = std::thread(processLeafBlock);
                a[i].join();
            }
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

THook(void, "?tick@Level@@UEAAXXZ", Level* _this) {
    if (settings::FastLeafDecay)
    {
        try {
            FastLeafDecay::processLeafBlocks();
        }
        catch (...) {
            return original(_this);
        }
    }
    return original(_this);
}