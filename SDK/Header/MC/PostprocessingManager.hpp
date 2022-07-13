// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PostprocessingManager {

#define AFTER_EXTRA
// Add Member There
public:
struct LockedChunk {
    LockedChunk() = delete;
    LockedChunk(LockedChunk const&) = delete;
    LockedChunk(LockedChunk const&&) = delete;
};

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_POSTPROCESSINGMANAGER
public:
    class PostprocessingManager& operator=(class PostprocessingManager const &) = delete;
    PostprocessingManager(class PostprocessingManager const &) = delete;
#endif


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_POSTPROCESSINGMANAGER
#endif
    MCAPI PostprocessingManager();
    MCAPI class std::optional<std::vector<struct PostprocessingManager::LockedChunk>> tryLock(class ChunkPos const &, class ChunkSource &);
    MCAPI ~PostprocessingManager();



};