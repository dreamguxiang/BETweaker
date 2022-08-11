// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ScatterParams {

#define AFTER_EXTRA
// Add Member There
public:
class ScatteredPositions {
public:
    ScatteredPositions() = delete;
    ScatteredPositions(ScatteredPositions const&) = delete;
    ScatteredPositions(ScatteredPositions const&&) = delete;
};

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SCATTERPARAMS
public:
    class ScatterParams& operator=(class ScatterParams const &) = delete;
    ScatterParams(class ScatterParams const &) = delete;
    ScatterParams() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SCATTERPARAMS
#endif
    MCAPI void addAdditionalSaveData(class CompoundTag &) const;
    MCAPI void readAdditionalSaveData(class CompoundTag const &);
    MCAPI class ScatterParams::ScatteredPositions scatter(class RenderParams &, class BlockPos const &, class Random &) const;
    MCAPI ~ScatterParams();
    MCAPI static void initMolangParams(class RenderParams &, class BlockPos const &, class Random &);
    MCAPI static void initScatterParamIndices();

//private:
    MCAPI class BlockPos _getPos(unsigned int, class BlockPos const &, class Random &, class RenderParams &) const;
    MCAPI void _parseExpressionNodeFloat(class CompoundTag const &, std::string const &, std::string const &, class ExpressionNode &, float);

private:

};