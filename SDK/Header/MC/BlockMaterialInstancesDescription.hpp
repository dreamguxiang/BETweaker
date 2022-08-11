// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct BlockMaterialInstancesDescription {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLOCKMATERIALINSTANCESDESCRIPTION
public:
    struct BlockMaterialInstancesDescription& operator=(struct BlockMaterialInstancesDescription const &) = delete;
    BlockMaterialInstancesDescription(struct BlockMaterialInstancesDescription const &) = delete;
#endif
public:
    /*0*/ virtual ~BlockMaterialInstancesDescription();
    /*1*/ virtual std::string const & getName() const;
    /*2*/ virtual void initializeComponent(class EntityContext &) const;
    /*3*/ virtual void __unk_vfn_3();
    /*4*/ virtual bool isNetworkComponent() const;
    /*5*/ virtual std::unique_ptr<class CompoundTag> buildNetworkTag() const;
    /*6*/ virtual void initializeFromNetwork(class CompoundTag const &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_BLOCKMATERIALINSTANCESDESCRIPTION
#endif
    MCAPI BlockMaterialInstancesDescription();
    MCAPI struct BlockMaterialInstancesDescription & operator=(struct BlockMaterialInstancesDescription &&);
    MCAPI static std::string const NameID;
    MCAPI static void bindType();

};