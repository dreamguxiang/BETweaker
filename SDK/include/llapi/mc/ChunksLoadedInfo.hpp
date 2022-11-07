// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct ChunksLoadedInfo {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CHUNKSLOADEDINFO
public:
    struct ChunksLoadedInfo& operator=(struct ChunksLoadedInfo const &) = delete;
    ChunksLoadedInfo(struct ChunksLoadedInfo const &) = delete;
    ChunksLoadedInfo() = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CHUNKSLOADEDINFO
#endif
    MCAPI std::unique_ptr<class ChunkViewSource> getChunkViewSource() const;
    MCAPI enum ChunksLoadedStatus getChunksLoadedStatus() const;
    MCAPI static enum ChunksLoadedStatus areAllChunksLoadedAndTicking(class Dimension const &, class ChunkSource &, struct Bounds const &, bool, struct Tick, bool);
    MCAPI static struct ChunksLoadedInfo calculateChunksLoadedInfo(class Dimension const &, class ChunkSource &, struct Bounds const &, bool, struct Tick, bool, bool, bool);

};