// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct NpcDialogueScene {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_NPCDIALOGUESCENE
public:
    struct NpcDialogueScene& operator=(struct NpcDialogueScene const &) = delete;
    NpcDialogueScene(struct NpcDialogueScene const &) = delete;
    NpcDialogueScene() = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_NPCDIALOGUESCENE
#endif
    MCAPI ~NpcDialogueScene();
    MCAPI static struct NpcDialogueScene parse(class Json::Value const &, std::string const &, int);

};