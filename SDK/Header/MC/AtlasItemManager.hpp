// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class AtlasItemManager {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ATLASITEMMANAGER
public:
    class AtlasItemManager& operator=(class AtlasItemManager const &) = delete;
    AtlasItemManager(class AtlasItemManager const &) = delete;
    AtlasItemManager() = delete;
#endif


public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ATLASITEMMANAGER
#endif
    MCAPI class TextureAtlasItem const & getTextureItem(std::string const &) const;



};