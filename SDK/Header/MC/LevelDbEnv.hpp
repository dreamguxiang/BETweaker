// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class LevelDbEnv {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_LEVELDBENV
public:
    class LevelDbEnv& operator=(class LevelDbEnv const &) = delete;
    LevelDbEnv(class LevelDbEnv const &) = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_LEVELDBENV
    MCVAPI class leveldb::Status CreateDir(std::string const &);
    MCVAPI class leveldb::Status DeleteDir(std::string const &);
    MCVAPI class leveldb::Status DeleteFileA(std::string const &);
    MCVAPI bool FileExists(std::string const &);
    MCVAPI class leveldb::Status GetChildren(std::string const &, std::vector<std::string> *);
    MCVAPI class leveldb::Status GetFileSize(std::string const &, unsigned __int64 *);
    MCVAPI class leveldb::Status GetTestDirectory(std::string *);
    MCVAPI class leveldb::Status LockFile(std::string const &, class leveldb::FileLock **);
    MCVAPI class leveldb::Status NewAppendableFile(std::string const &, class leveldb::WritableFile **);
    MCVAPI class leveldb::Status NewLogger(std::string const &, class leveldb::Logger **);
    MCVAPI class leveldb::Status NewRandomAccessFile(std::string const &, class leveldb::RandomAccessFile **);
    MCVAPI class leveldb::Status NewSequentialFile(std::string const &, class leveldb::SequentialFile **);
    MCVAPI class leveldb::Status NewWritableFile(std::string const &, class leveldb::WritableFile **);
    MCVAPI unsigned __int64 NowMicros();
    MCVAPI class leveldb::Status RenameFile(std::string const &, std::string const &);
    MCVAPI void Schedule(void ( *)(void *), void *);
    MCVAPI void SleepForMicroseconds(int);
    MCVAPI void StartThread(void ( *)(void *), void *);
    MCVAPI class leveldb::Status UnlockFile(class leveldb::FileLock *);
    MCVAPI ~LevelDbEnv();
#endif
    MCAPI bool IsComplete() const;
    MCAPI LevelDbEnv();

//private:

private:
    MCAPI static class LevelDbEnv * sSingleton;

};