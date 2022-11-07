// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class RandomizableBlockActorFillingContainer {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_RANDOMIZABLEBLOCKACTORFILLINGCONTAINER
public:
    class RandomizableBlockActorFillingContainer& operator=(class RandomizableBlockActorFillingContainer const &) = delete;
    RandomizableBlockActorFillingContainer(class RandomizableBlockActorFillingContainer const &) = delete;
    RandomizableBlockActorFillingContainer() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_RANDOMIZABLEBLOCKACTORFILLINGCONTAINER
    MCVAPI void dropContents(class BlockSource &, class Vec3 const &, bool);
    MCVAPI void initializeContainerContents(class BlockSource &);
    MCVAPI void setContainerChanged(int);
    MCVAPI void startOpen(class Player &);
    MCVAPI ~RandomizableBlockActorFillingContainer();
#endif
    MCAPI RandomizableBlockActorFillingContainer(enum BlockActorType, std::string const &, class BlockPos const &, int, enum ContainerType);

};