// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class RandomizableBlockActorContainer {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_RANDOMIZABLEBLOCKACTORCONTAINER
public:
    class RandomizableBlockActorContainer& operator=(class RandomizableBlockActorContainer const &) = delete;
    RandomizableBlockActorContainer(class RandomizableBlockActorContainer const &) = delete;
    RandomizableBlockActorContainer() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_RANDOMIZABLEBLOCKACTORCONTAINER
    MCVAPI void dropContents(class BlockSource &, class Vec3 const &, bool);
    MCVAPI void initializeContainerContents(class BlockSource &);
    MCVAPI void setContainerChanged(int);
    MCVAPI void startOpen(class Player &);
    MCVAPI ~RandomizableBlockActorContainer();
#endif
    MCAPI RandomizableBlockActorContainer(enum BlockActorType, std::string const &, class BlockPos const &, enum ContainerType);

};