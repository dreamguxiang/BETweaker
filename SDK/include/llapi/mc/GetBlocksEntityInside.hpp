// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "SideBySideEntityInsideBlocksComponent.hpp"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class GetBlocksEntityInside {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_GETBLOCKSENTITYINSIDE
public:
    class GetBlocksEntityInside& operator=(class GetBlocksEntityInside const &) = delete;
    GetBlocksEntityInside(class GetBlocksEntityInside const &) = delete;
    GetBlocksEntityInside() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_GETBLOCKSENTITYINSIDE
#endif
    MCAPI static std::vector<struct SideBySideEntityInsideBlocksComponent::InternalData> get(class AABB const &, class IConstBlockSource const &);

};