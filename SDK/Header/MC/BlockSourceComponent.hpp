// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class BlockSourceComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLOCKSOURCECOMPONENT
public:
    class BlockSourceComponent& operator=(class BlockSourceComponent const &) = delete;
    BlockSourceComponent(class BlockSourceComponent const &) = delete;
    BlockSourceComponent() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_BLOCKSOURCECOMPONENT
#endif
    MCAPI BlockSourceComponent(class Level &, class Dimension &, class ChunkSource &, bool);
    MCAPI class StackRefResultT<struct SharePtrRefTraits<class BlockSource>> tryGetBlockSource() const;

};