#include "../Global.h"
#include <MC/Recipes.hpp>
#include <MC/ItemRegistry.hpp>
#include <MC/CreativeItemRegistry.hpp>
#include <MC/SortItemInstanceIdAux.hpp>
#include <MC/ItemInstance.hpp>
#include <MC/Recipe.hpp>
THook(void, "?_loadHardcodedRecipes@Recipes@@AEAAXXZ", Recipes& recipes) {
    original(recipes);
    vector<string> shapeMatrix{"AAA","ABA","AAA",};
    vector<Recipes::Type> types{ 
        Recipes::Type("minecraft:stick", 'A', 1, 0),
        Recipes::Type("minecraft:diamond", 'B', 1, 0)
    };
    vector<HashedString> craftingTags{ "crafting_table" };
    recipes.addShapedRecipe("betweaker::betskick", Helper::cteateBetStick(), shapeMatrix, types, craftingTags, 2, nullptr);
}
#include <mc/ItemRegistryManager.hpp>
#include <mc/ItemRegistryRef.hpp>
void regtest() {
	auto& recipes = Global<Level>->getRecipes();
    vector<HashedString> fTags{ "furnace" };
    recipes.addFurnaceRecipeAuxData(ItemInstance(*ItemRegistryManager::getItemRegistry().lookupByName("minecraft:stick"), 0, 0, 0), Helper::cteateBetStick(), fTags);
}

THook(void, "?addLooseCreativeItems@Item@@SAX_NAEBVBaseGameVersion@@@Z", void* a1) {
    original(a1);
    Item::addCreativeItem(Helper::cteateBetStick());
}
