// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PillagerOutpostStart {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PILLAGEROUTPOSTSTART
public:
    class PillagerOutpostStart& operator=(class PillagerOutpostStart const &) = delete;
    PillagerOutpostStart(class PillagerOutpostStart const &) = delete;
    PillagerOutpostStart() = delete;
#endif

public:
    /*0*/ virtual ~PillagerOutpostStart();
    /*1*/ virtual bool postProcess(class BlockSource &, class Random &, class BoundingBox const &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_PILLAGEROUTPOSTSTART
#endif

};