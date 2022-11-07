// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "BlockActor.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ComparatorBlockActor : public BlockActor {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_COMPARATORBLOCKACTOR
public:
    class ComparatorBlockActor& operator=(class ComparatorBlockActor const &) = delete;
    ComparatorBlockActor(class ComparatorBlockActor const &) = delete;
    ComparatorBlockActor() = delete;
#endif

public:
    /*0*/ virtual ~ComparatorBlockActor();
    /*1*/ virtual void load(class Level &, class CompoundTag const &, class DataLoadHelper &);
    /*2*/ virtual bool save(class CompoundTag &) const;
    /*7*/ virtual void tick(class BlockSource &);
    /*12*/ virtual void __unk_vfn_12();
    /*16*/ virtual void __unk_vfn_16();
    /*28*/ virtual void __unk_vfn_28();
    /*29*/ virtual void __unk_vfn_29();
    /*30*/ virtual void __unk_vfn_30();
    /*32*/ virtual void __unk_vfn_32();
    /*33*/ virtual void __unk_vfn_33();
    /*34*/ virtual void __unk_vfn_34();
    /*38*/ virtual int getOutputSignal();
    /*39*/ virtual void setOutputSignal(int);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_COMPARATORBLOCKACTOR
#endif
    MCAPI ComparatorBlockActor(class BlockPos const &);

};