// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Recipe.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class RepairItemRecipe : public Recipe {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_REPAIRITEMRECIPE
public:
    class RepairItemRecipe& operator=(class RepairItemRecipe const &) = delete;
    RepairItemRecipe(class RepairItemRecipe const &) = delete;
    RepairItemRecipe() = delete;
#endif

public:
    /*0*/ virtual ~RepairItemRecipe();
    /*1*/ virtual std::vector<class ItemInstance> const & assemble(class CraftingContainer &) const;
    /*2*/ virtual int getCraftingSize() const;
    /*3*/ virtual class RecipeIngredient const & getIngredient(int, int) const;
    /*4*/ virtual std::vector<class ItemInstance> const & getResultItem() const;
    /*6*/ virtual bool matches(class CraftingContainer &, class Level &) const;
    /*7*/ virtual int size() const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_REPAIRITEMRECIPE
#endif
    MCAPI RepairItemRecipe(class gsl::basic_string_span<char const, -1>, class mce::UUID const *);
    MCAPI static class mce::UUID ID;

};