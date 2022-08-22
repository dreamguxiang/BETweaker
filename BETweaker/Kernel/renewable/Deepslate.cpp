#include "../../Global.h"
#include "../../Main/Module.h"

THook2("renewableDeepslate", void, "?solidify@LiquidBlock@@IEBAXAEAVBlockSource@@AEBVBlockPos@@1@Z",
    uintptr_t _this, BlockSource& bs, BlockPos& bp1, BlockPos& bp2) {
    original(_this, bs, bp1, bp2);
    if(Settings::RenewableDeepslate){
        if (bp1.y < 0) {
            if (bs.getBlock(bp1) == *Module::Stone) {
                bs.setBlockSimple(bp1, *VanillaBlocks::mDeepslate);
            }
            else if (bs.getBlock(bp1) == *Module::Cobblestone) {
                bs.setBlockSimple(bp1, *VanillaBlocks::mCobbledDeepslate);
            }
        }
    }
}