// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "LevelContainerManagerModel.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ChestContainerManagerModel : public LevelContainerManagerModel {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CHESTCONTAINERMANAGERMODEL
public:
    class ChestContainerManagerModel& operator=(class ChestContainerManagerModel const &) = delete;
    ChestContainerManagerModel(class ChestContainerManagerModel const &) = delete;
    ChestContainerManagerModel() = delete;
#endif

public:
    /*0*/ virtual ~ChestContainerManagerModel();
    /*16*/ virtual bool isValid(float);
    /*17*/ virtual class ContainerScreenContext _postInit();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CHESTCONTAINERMANAGERMODEL
#endif
    MCAPI ChestContainerManagerModel(enum ContainerID, class Player &, class BlockPos const &, enum BlockActorType);
    MCAPI ChestContainerManagerModel(enum ContainerID, class Player &, struct ActorUniqueID);

};