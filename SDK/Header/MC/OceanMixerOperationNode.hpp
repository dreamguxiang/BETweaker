// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class OceanMixerOperationNode {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_OCEANMIXEROPERATIONNODE
public:
    class OceanMixerOperationNode& operator=(class OceanMixerOperationNode const &) = delete;
    OceanMixerOperationNode(class OceanMixerOperationNode const &) = delete;
    OceanMixerOperationNode() = delete;
#endif

public:
    /*0*/ virtual ~OceanMixerOperationNode();
    /*1*/ virtual void __unk_vfn_1();
    /*2*/ virtual void __unk_vfn_2();
    /*3*/ virtual void _fillArea(class OperationNodeDetails::WorkingData<class Biome *, class Biome *> &, class Pos2d const &, class Pos2d const &, int, class OperationGraphResult<enum BiomeTemperatureCategory>) const;
    /*4*/ virtual class std::tuple<class Pos2d, class Pos2d> _getAreaRead(class Pos2d const &, class Pos2d const &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_OCEANMIXEROPERATIONNODE
#endif
    MCAPI OceanMixerOperationNode(unsigned int, class std::shared_ptr<class OperationNode<class Biome *, class Pos2d>> &, class std::shared_ptr<class OperationNode<enum BiomeTemperatureCategory, class Pos2d>> &, class BiomeRegistry const &, class Biome &, class Biome &);

};