// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct BlockUnitCubeDescription {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLOCKUNITCUBEDESCRIPTION
public:
    struct BlockUnitCubeDescription& operator=(struct BlockUnitCubeDescription const &) = delete;
    BlockUnitCubeDescription(struct BlockUnitCubeDescription const &) = delete;
    BlockUnitCubeDescription() = delete;
#endif
public:
    /*0*/ virtual ~BlockUnitCubeDescription();
    /*1*/ virtual std::string const & getName() const;
    /*2*/ virtual void initializeComponent(class EntityContext &) const;
    /*3*/ virtual void initializeFromNetwork(class CompoundTag const &);
    /*4*/ virtual bool isNetworkComponent() const;
    /*5*/ virtual std::unique_ptr<class CompoundTag> buildNetworkTag() const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_BLOCKUNITCUBEDESCRIPTION
#endif
    MCAPI static std::string const NameID;
    MCAPI static void bindType();

};