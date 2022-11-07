// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct BlockComponentDescription {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLOCKCOMPONENTDESCRIPTION
public:
    struct BlockComponentDescription& operator=(struct BlockComponentDescription const &) = delete;
    BlockComponentDescription(struct BlockComponentDescription const &) = delete;
    BlockComponentDescription() = delete;
#endif
public:
    /*0*/ virtual ~BlockComponentDescription();
    /*1*/ virtual std::string const & getName() const;
    /*2*/ virtual void __unk_vfn_2();
    /*3*/ virtual void __unk_vfn_3();
    /*4*/ virtual bool isNetworkComponent() const;
    /*5*/ virtual std::unique_ptr<class CompoundTag> buildNetworkTag() const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_BLOCKCOMPONENTDESCRIPTION
    MCVAPI void buildSchema(class std::shared_ptr<class JsonUtil::JsonSchemaObjectNode<class JsonUtil::EmptyClass, struct BlockComponentGroupDescription>> &, class BlockComponentFactory const &) const;
    MCVAPI void handleVersionBasedInitialization(class SemVersion const &);
    MCVAPI void initializeComponent(class EntityContext &) const;
    MCVAPI void initializeFromNetwork(class CompoundTag const &);
#endif
    MCAPI static void bindType();
    MCAPI static void registerVersionUpgrades(class CerealSchemaUpgradeSet &);

};