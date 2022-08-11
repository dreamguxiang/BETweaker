// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

struct BlockCraftingTableDescription {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLOCKCRAFTINGTABLEDESCRIPTION
public:
    struct BlockCraftingTableDescription& operator=(struct BlockCraftingTableDescription const &) = delete;
    BlockCraftingTableDescription(struct BlockCraftingTableDescription const &) = delete;
    BlockCraftingTableDescription() = delete;
#endif
public:
    /*0*/ virtual ~BlockCraftingTableDescription();
    /*1*/ virtual std::string const & getName() const;
    /*2*/ virtual void initializeComponent(class EntityContext &) const;
    /*3*/ virtual void __unk_vfn_3();
    /*4*/ virtual bool isNetworkComponent() const;
    /*5*/ virtual std::unique_ptr<class CompoundTag> buildNetworkTag() const;
    /*6*/ virtual void initializeFromNetwork(class CompoundTag const &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_BLOCKCRAFTINGTABLEDESCRIPTION
#endif
    MCAPI static std::string const NameID;
    MCAPI static void bindType();
    MCAPI static void registerVersionUpgrades(class CerealSchemaUpgradeSet &);

};