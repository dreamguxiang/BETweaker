// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "ContainerManagerModel.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class LoomContainerManagerModel : public ContainerManagerModel {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_LOOMCONTAINERMANAGERMODEL
public:
    class LoomContainerManagerModel& operator=(class LoomContainerManagerModel const &) = delete;
    LoomContainerManagerModel(class LoomContainerManagerModel const &) = delete;
    LoomContainerManagerModel() = delete;
#endif

public:
    /*0*/ virtual ~LoomContainerManagerModel();
    /*6*/ virtual std::vector<class ItemStack> getItemCopies() const;
    /*7*/ virtual void setSlot(int, class ItemStack const &, bool);
    /*8*/ virtual class ItemStack const & getSlot(int) const;
    /*9*/ virtual void setData(int, int);
    /*10*/ virtual void broadcastChanges();
    /*16*/ virtual bool isValid(float);
    /*17*/ virtual class ContainerScreenContext _postInit();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_LOOMCONTAINERMANAGERMODEL
#endif
    MCAPI LoomContainerManagerModel(enum ContainerID, class Player &, class BlockPos const &);
    MCAPI static int const BANNER_SLOT;
    MCAPI static int const DYE_SLOT;
    MCAPI static int const MATERIAL_SLOT;
    MCAPI static int const RESULT_SLOT;

};