// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "TreeHelper.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class SimpleTreeCanopy {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SIMPLETREECANOPY
public:
    class SimpleTreeCanopy& operator=(class SimpleTreeCanopy const &) = delete;
    SimpleTreeCanopy(class SimpleTreeCanopy const &) = delete;
    SimpleTreeCanopy() = delete;
#endif

public:
    /*0*/ virtual ~SimpleTreeCanopy();
    /*1*/ virtual class std::optional<class BlockPos> placeCanopy(class IBlockWorldGenAPI &, class BlockPos const &, class Random &, class RenderParams &, struct TreeHelper::TreeParams const &, std::vector<class BlockPos> const &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SIMPLETREECANOPY
#endif

};