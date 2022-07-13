// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class FileAccessTransforms {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_FILEACCESSTRANSFORMS
public:
    class FileAccessTransforms& operator=(class FileAccessTransforms const &) = delete;
    FileAccessTransforms(class FileAccessTransforms const &) = delete;
    FileAccessTransforms() = delete;
#endif


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_FILEACCESSTRANSFORMS
    MCVAPI bool readTransform(std::vector<unsigned char> &) const;
    MCVAPI bool writeTransform(std::vector<unsigned char> &) const;
#endif



};