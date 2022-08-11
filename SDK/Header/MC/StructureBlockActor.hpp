// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "BlockActor.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class StructureBlockActor : public BlockActor {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_STRUCTUREBLOCKACTOR
public:
    class StructureBlockActor& operator=(class StructureBlockActor const &) = delete;
    StructureBlockActor(class StructureBlockActor const &) = delete;
    StructureBlockActor() = delete;
#endif

public:
    /*0*/ virtual ~StructureBlockActor();
    /*1*/ virtual void load(class Level &, class CompoundTag const &, class DataLoadHelper &);
    /*2*/ virtual bool save(class CompoundTag &) const;
    /*8*/ virtual void onChanged(class BlockSource &);
    /*12*/ virtual void __unk_vfn_12();
    /*16*/ virtual void __unk_vfn_16();
    /*28*/ virtual void __unk_vfn_28();
    /*29*/ virtual void __unk_vfn_29();
    /*30*/ virtual void __unk_vfn_30();
    /*32*/ virtual void __unk_vfn_32();
    /*33*/ virtual void __unk_vfn_33();
    /*34*/ virtual void __unk_vfn_34();
    /*35*/ virtual std::unique_ptr<class BlockActorDataPacket> _getUpdatePacket(class BlockSource &);
    /*36*/ virtual void _onUpdatePacket(class CompoundTag const &, class BlockSource &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_STRUCTUREBLOCKACTOR
#endif
    MCAPI StructureBlockActor(class BlockPos const &);
    MCAPI class StructureEditorData const & getStructureData() const;
    MCAPI void setPowered(class BlockSource &, class BlockPos const &, bool, bool);
    MCAPI void setStructureData(class StructureEditorData const &);
    MCAPI static float const MAX_WIREFRAME_RENDER_DISTANCE;
    MCAPI static class mce::Color const X_AXIS_COLOR;
    MCAPI static class mce::Color const Y_AXIS_COLOR;
    MCAPI static class mce::Color const Z_AXIS_COLOR;

//private:
    MCAPI bool _loadStructure(class BlockSource &, class BlockPos const &, class BaseGameVersion const &);
    MCAPI bool _saveStructure(class BlockSource &, class BlockPos const &, bool);
    MCAPI void _trigger(class BlockSource &, class BlockPos const &, class BaseGameVersion const &, bool);

private:

};