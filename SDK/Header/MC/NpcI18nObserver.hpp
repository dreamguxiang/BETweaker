// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class NpcI18nObserver {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_NPCI18NOBSERVER
public:
    class NpcI18nObserver& operator=(class NpcI18nObserver const &) = delete;
    NpcI18nObserver(class NpcI18nObserver const &) = delete;
    NpcI18nObserver() = delete;
#endif

public:
    /*0*/ virtual ~NpcI18nObserver();
    /*1*/ virtual void onLanguageChanged(std::string const &, bool);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_NPCI18NOBSERVER
    MCVAPI void onLanguageKeywordsLoadedFromPack(class PackManifest const &);
    MCVAPI void onLanguagesLoaded();
#endif

//private:
    MCAPI void _loadNpcData();

private:

};