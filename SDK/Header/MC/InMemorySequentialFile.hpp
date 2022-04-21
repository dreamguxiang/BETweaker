// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class InMemorySequentialFile {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_INMEMORYSEQUENTIALFILE
public:
    class InMemorySequentialFile& operator=(class InMemorySequentialFile const &) = delete;
    InMemorySequentialFile(class InMemorySequentialFile const &) = delete;
    InMemorySequentialFile() = delete;
#endif

public:
    /*0*/ virtual ~InMemorySequentialFile();
    /*1*/ virtual class leveldb::Status Read(unsigned __int64, class leveldb::Slice *, char *);
    /*2*/ virtual class leveldb::Status Skip(unsigned __int64);
    MCAPI InMemorySequentialFile(class std::shared_ptr<class InMemoryFile>);

protected:

private:

};