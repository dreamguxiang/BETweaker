// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class BlockPosTrackerComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLOCKPOSTRACKERCOMPONENT
public:
    class BlockPosTrackerComponent& operator=(class BlockPosTrackerComponent const &) = delete;
    BlockPosTrackerComponent(class BlockPosTrackerComponent const &) = delete;
    BlockPosTrackerComponent() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_BLOCKPOSTRACKERCOMPONENT
#endif
    MCAPI BlockPosTrackerComponent(bool, class BlockPos const &);
    MCAPI void onRemove(class Actor &);

};