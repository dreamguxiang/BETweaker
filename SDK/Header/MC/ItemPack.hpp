// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class ItemPack {

#define AFTER_EXTRA
public:
    std::unordered_map<ItemDescriptor, int> mIngredients;
#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ITEMPACK
public:
    class ItemPack& operator=(class ItemPack const &) = delete;
    ItemPack(class ItemPack const &) = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ITEMPACK
#endif
    MCAPI ItemPack();
    MCAPI void add(class RecipeIngredient const &, int);
    MCAPI ~ItemPack();

};