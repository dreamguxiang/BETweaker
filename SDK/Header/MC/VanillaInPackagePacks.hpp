// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class VanillaInPackagePacks {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_VANILLAINPACKAGEPACKS
public:
    class VanillaInPackagePacks& operator=(class VanillaInPackagePacks const &) = delete;
    VanillaInPackagePacks(class VanillaInPackagePacks const &) = delete;
    VanillaInPackagePacks() = delete;
#endif

public:
    /*0*/ virtual ~VanillaInPackagePacks();
    /*1*/ virtual std::vector<struct IInPackagePacks::MetaData> getPacks(enum PackType) const;

protected:

private:

};