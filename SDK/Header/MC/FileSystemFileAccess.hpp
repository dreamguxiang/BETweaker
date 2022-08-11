// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Core.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class FileSystemFileAccess {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_FILESYSTEMFILEACCESS
public:
    class FileSystemFileAccess& operator=(class FileSystemFileAccess const &) = delete;
    FileSystemFileAccess(class FileSystemFileAccess const &) = delete;
    FileSystemFileAccess() = delete;
#endif

public:
    /*0*/ virtual ~FileSystemFileAccess();
    /*1*/ virtual void * fopen(class Core::Path const &, std::string const &);
    /*2*/ virtual int fclose(void *);
    /*3*/ virtual int fseek(void *, __int64, int);
    /*4*/ virtual __int64 ftell(void *);
    /*5*/ virtual class IFileReadAccess const * getReadInterface() const;
    /*6*/ virtual class IFileWriteAccess * getWriteInterface();
    /*7*/ virtual void unload();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_FILESYSTEMFILEACCESS
#endif
    MCAPI FileSystemFileAccess(enum FileSystemMode);

};