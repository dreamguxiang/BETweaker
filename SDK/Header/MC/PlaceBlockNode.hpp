// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PlaceBlockNode {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PLACEBLOCKNODE
public:
    class PlaceBlockNode& operator=(class PlaceBlockNode const &) = delete;
    PlaceBlockNode(class PlaceBlockNode const &) = delete;
#endif

public:
    /*0*/ virtual ~PlaceBlockNode();
    /*1*/ virtual enum BehaviorStatus tick(class Actor &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_PLACEBLOCKNODE
#endif
    MCAPI PlaceBlockNode();

};