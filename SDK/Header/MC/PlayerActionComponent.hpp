// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct PlayerActionComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PLAYERACTIONCOMPONENT
public:
    struct PlayerActionComponent& operator=(struct PlayerActionComponent const &) = delete;
    PlayerActionComponent(struct PlayerActionComponent const &) = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_PLAYERACTIONCOMPONENT
#endif
    MCAPI PlayerActionComponent(struct PlayerActionComponent &&);
    MCAPI PlayerActionComponent();
    MCAPI void addAbortDestroyBlock(class BlockPos const &, int);
    MCAPI void addContinueDestroyBlock(class BlockPos const &, int);
    MCAPI void addStartDestroyBlock(class BlockPos const &, int);
    MCAPI void addStopDestroyBlock();
    MCAPI struct PlayerActionComponent & operator=(struct PlayerActionComponent &&);
    MCAPI ~PlayerActionComponent();

};