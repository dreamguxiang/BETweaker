// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class LevelChunkMetaData {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_LEVELCHUNKMETADATA
public:
    class LevelChunkMetaData& operator=(class LevelChunkMetaData const &) = delete;
    LevelChunkMetaData() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_LEVELCHUNKMETADATA
#endif
    MCAPI LevelChunkMetaData(class IDataInput &);
    MCAPI LevelChunkMetaData(class LevelChunkMetaData const &);
    MCAPI unsigned __int64 getCurrentHash() const;
    MCAPI void serialize(class IDataOutput &) const;
    MCAPI ~LevelChunkMetaData();
    MCAPI static unsigned __int64 const INVALID_META_DATA;

//protected:
    MCAPI void _deserialize(class IDataInput &);
    MCAPI void _recomputeHash() const;

protected:

};