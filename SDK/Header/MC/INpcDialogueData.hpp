// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct INpcDialogueData {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_INPCDIALOGUEDATA
public:
    struct INpcDialogueData& operator=(struct INpcDialogueData const &) = delete;
    INpcDialogueData(struct INpcDialogueData const &) = delete;
    INpcDialogueData() = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_INPCDIALOGUEDATA
    MCVAPI std::string const & getRawDialogueText() const;
    MCVAPI bool isRemoteFire();
#endif

};