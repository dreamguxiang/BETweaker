#pragma once
#include "../Global.h"

namespace Module {
	extern std::unordered_map<string, string> elist;
	bool LoadBetterHarvestingCrop(BlockInstance blockin, Player* sp);
	void FastSleep();
	bool EditSign(Player* pl, BlockInstance bi);
	void HUBInfo();
	bool FastLeafDecayFunc1(LeafBlock* a1, BlockSource* a2, const BlockPos* a3);
	bool FastLeafDecayFunc();
	bool DispenserItemFunc(BlockSource* a2, Vec3* a3, FaceID a4, ItemStack* a5);
	bool AutoFish(FishingHook* a1);
	bool DoubleDoors(DoorBlock* a1, Player* pl, BlockPos* a3, UCHAR a4);
	bool FastSetMinecart(Player* pl, Actor* ac);
	bool UseItemSupply(Player* sp, ItemStackBase& item, string itemname, short aux);
	bool UseItemSupply(Player* sp, string itemname);
	void cutTree(BlockSource* bs, BlockPos a3, Player* sp);
	void cutTreeLore(Player* sp, ItemStack* item);
	bool DispenserDestroy(BlockActor* ba, BlockSource* a2, BlockPos* pos, ItemStack& a5, int solt, BlockPos* old); 
	void ChangeDispenserMode(BlockActor* ba, BlockSource* bs, Player* sp);
	bool AnvilRestoration(ItemStack* item, Block* block, BlockPos pos, Player* sp);
	void BetterThanMending(Player* sp);
	void cancelSleep();
	bool AutoCrafting(DispenserBlockActor* ba, BlockSource* a2, BlockPos pos);
	void InitAutoCrafting();
	extern const Block* craftingTable;
	extern const Block* Stone;
	extern const Block* Cobblestone;
	//void PlayEmote(Player* a1, string uuid);
	//void readElistJsonData();
}

void downloadEmoteList();