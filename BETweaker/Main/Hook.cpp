#include "../Global.h"
#include "Module.h"
#include "setting.h"
#include <MC/AdventureSettings.hpp>
#include <MC/RequestAbilityPacket.hpp>
#include <MC/ServerPlayer.hpp>
#include <MC/Abilities.hpp>
#include <MC/ServerLevel.hpp>
#include "../Main/Helper.hpp"
bool nodis = false;

//THook(void, "?updateSleepingPlayerList@ServerLevel@@UEAAXXZ", Level* self) {
//	original(self);
//	if (Settings::FastSleeping) {
//		try {
//			Module::FastSleep();
//		}
//		catch (...) {
//			return;
//		}
//	}
//}
std::set<string> sleepList;

THook(__int64, "?startSleepInBed@Player@@UEAA?AW4BedSleepingResult@@AEBVBlockPos@@@Z",
	Player* a1, int* a2, const char* a3)
{
	auto out = original(a1, a2, a3);
	if (out == 0) {
		sleepList.insert(a1->getRealName());
		Module::FastSleep();
	}
	return out;
}

THook(void, "?stopSleepInBed@Player@@UEAAX_N0@Z",
	Player* self, bool a2, char a3)
{
	if (self->isSleeping()) {
		sleepList.erase(self->getRealName());
		Module::cancelSleep();
	}
	original(self, a2, a3);
}


THook(void, "?transformOnFall@FarmBlock@@UEBAXAEAVBlockSource@@AEBVBlockPos@@PEAVActor@@M@Z", void* __this, void* a2,
	void* a3, void* a4, float a5) {
	if (Settings::NoFarmDestroy) {
		return;
	}
	return original(__this, a2, a3, a4, a5);
}
#include <Utils/CsLock.h>
CsLock DispenserejectItemLock;
THook(void, "?ejectItem@DispenserBlock@@IEBAXAEAVBlockSource@@AEBVVec3@@EAEBVItemStack@@AEAVContainer@@H@Z", DispenserBlock* a1,
      BlockSource* a2,
      Vec3* a3,
	unsigned __int8 a4,
    ItemStack* a5,
    Container* a6,
	unsigned int a7) {
	if (Settings::DispenserCrops){
		DispenserejectItemLock.lock();
		nodis = true;
		original(a1, a2, a3, a4, a5, a6, a7);
		DispenserejectItemLock.unlock();
		return;
	}
	return original(a1, a2, a3, a4, a5, a6, a7);
}

#include <MC/BlockActor.hpp>
#include <MC/DispenserBlockActor.hpp>
#include <MC/Container.hpp>
#include <MC/RandomizableBlockActorContainerBase.hpp>
typedef std::chrono::high_resolution_clock timer_clock;
#define TIMER_START auto start = timer_clock::now();
#define TIMER_END                                                      \
    auto elapsed = timer_clock::now() - start;                         \
    long long timeReslut =                                             \
        std::chrono::duration_cast<std::chrono::microseconds>(elapsed) \
            .count();

TInstanceHook2("AutoCrafting", void, "?dispenseFrom@DispenserBlock@@MEBAXAEAVBlockSource@@AEBVBlockPos@@@Z", DispenserBlock, BlockSource* a2, BlockPos* a3) {
	if(!Settings::AutoCrafting) return original(this, a2, a3);
	DispenserBlockActor* BlockEntity = (DispenserBlockActor*)a2->getBlockEntity(*a3);
	if (BlockEntity)
	{
		auto Container = BlockEntity->getContainer();
		((RandomizableBlockActorContainerBase*)BlockEntity)->unPackLootTable(*Global<Level>, *Container, a2->getDimensionId(), 0);
		int v9 = BlockEntity->getRandomSlot();
		auto& items = Container->getItem(v9);
		if (!items.isNull() && items.getCount() > 0)
		{
			int face = getFacing(a2->getBlock(*a3));
			auto newpos = a3->neighbor(face);
			if(Settings::AutoCrafting)
				if (!Module::AutoCrafting(BlockEntity, a2, newpos))return;
		}
	}
	return original(this,a2,a3);
}

TInstanceHook2("DispenserDestroy", void, "?dispenseFrom@DispenserBlock@@MEBAXAEAVBlockSource@@AEBVBlockPos@@@Z", DispenserBlock, BlockSource* a2, BlockPos* a3) {
	if (!Settings::DispenserDestroyBlock ) return original(this, a2, a3);
	DispenserBlockActor* BlockEntity = (DispenserBlockActor*)a2->getBlockEntity(*a3);
	if (BlockEntity)
	{
		auto Container = BlockEntity->getContainer();
		((RandomizableBlockActorContainerBase*)BlockEntity)->unPackLootTable(*Global<Level>, *Container, a2->getDimensionId(), 0);
		int v9 = BlockEntity->getRandomSlot();
		auto& items = Container->getItem(v9);
		if (!items.isNull() && items.getCount() > 0)
		{
			int face = getFacing(a2->getBlock(*a3));
			auto newpos = a3->neighbor(face);
			if (Settings::DispenserDestroyBlock)
				if (Module::DispenserDestroy((BlockActor*)BlockEntity, a2, &newpos, const_cast<ItemStack&>(items), v9, a3)) return;
		}
	}
	return original(this, a2, a3);
}

THook(void, "?ejectItem@DispenserBlock@@SAXAEAVBlockSource@@AEBVVec3@@EAEBVItemStack@@@Z", 
	BlockSource* a2, Vec3* a3, FaceID a4, ItemStack* a5) {
	if (!Settings::DispenserCrops) return original(a2, a3, a4, a5);
	if (nodis) {
		nodis = false;
		return original(a2, a3, a4, a5);
	}
	if (Module::DispenserItemFunc( a2, a3, a4, a5))
		return;
	return original(a2, a3, a4, a5);
}

BlockPos getTargeBlock(Vec3 pos, FaceID a5) {
	switch (a5) {
	case FaceID::Down:
		return pos.toBlockPos().add(0, -1, 0);
	case FaceID::Up:
		return pos.toBlockPos().add(0, 1, 0);
	case FaceID::North:
		return pos.toBlockPos().add(0, 0, -1);
	case FaceID::South:
		return pos.toBlockPos().add(0, 0, 1);
	case FaceID::West:
		return pos.toBlockPos().add(-1, 0, 0);
	case FaceID::East:
		return pos.toBlockPos().add(1, 0, 0);
	}
}
CsLock getMaxStackSize;
bool IsComparatorSignal = 0;
THook(__int64, "?getMaxStackSize@ItemStackBase@@QEBAEXZ",
	ItemStackBase* self)
{
	if (IsComparatorSignal) {
		return 1;
	}
	return original(self);
}

THook(int, "?getComparatorSignal@DispenserBlock@@UEBAHAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@E@Z",
	DispenserBlock* self, BlockSource* a2, BlockPos a3, Block* a4)
{
	auto newpos = a3.neighbor(self->getFacing(*a4));
	auto outputpos = a3.add(0, -1);
	if (a2->getBlock(newpos) == *Module::craftingTable) {
		getMaxStackSize.lock();
		IsComparatorSignal = 1;
		auto out = original(self, a2, a3, a4);
		IsComparatorSignal = 0;
		getMaxStackSize.unlock();
		return out;
	}
	return original(self, a2, a3, a4);
}

#include <MC/BaseCircuitComponent.hpp>
#include <MC/Hopper.hpp>
TInstanceHook(bool, "?_pushOutItems@Hopper@@IEAA_NAEAVBlockSource@@AEAVContainer@@AEBVVec3@@H@Z",
	Hopper, BlockSource& region, Container* fromContainer, Vec3 position, unsigned int attachedFace)
{
	auto pos = getTargeBlock(position, (FaceID)attachedFace);
	auto ba = region.getBlockEntity(pos);
	if (ba) {
		if (ba->getType() == BlockActorType::Dispenser) {
			auto& block = region.getBlock(pos);
			auto newpos = pos.neighbor(((DispenserBlock*)&block.getLegacyBlock())->getFacing(block));
			auto outputpos = pos.add(0, -1);
			if (region.getBlock(newpos) == *Module::craftingTable) {
				if (fromContainer) {
					auto fromitemlist = fromContainer->getAllSlots();
					for (int i = 0; i < fromitemlist.size(); ++i) {
						auto item = fromitemlist[i];
						if (!item->isNull()) {
							auto toContainer = _getAttachedContainerInBlock(region, position, attachedFace);
							if (toContainer) {
								auto itemlist = toContainer->getAllSlots();
								for (auto j = 0; j < itemlist.size(); ++j) {
									auto items = itemlist[j];
									if (items->isNull()) {
										auto newitem = item->clone_s();
										newitem->set(1);
										toContainer->setItem(j, *newitem);
										fromContainer->removeItem_s(i, 1);
										delete newitem;
										break;
									}
								}
							}
							break;
						}
					}
				}
				return 1;
			}
		}
	}
	original(this, region, fromContainer, position, attachedFace);
	return 1;
}


THook(void, "?onRemove@LeafBlock@@UEBAXAEAVBlockSource@@AEBVBlockPos@@@Z",
	LeafBlock* _this, BlockSource* a2, const BlockPos* a3) {
	if (Settings::FastLeafDecay) {
		try {
			Module::FastLeafDecayFunc1(_this, a2, a3);
		}		
		catch (...) {
			return original(_this, a2, a3);
		}
	}		
	return original(_this, a2, a3);
}

THook(void, "?onRemove@LogBlock@@UEBAXAEAVBlockSource@@AEBVBlockPos@@@Z",
	LogBlock* _this, BlockSource* a2, const BlockPos* a3) {
	if (Settings::FastLeafDecay) {
		try {
			Module::FastLeafDecayFunc1((LeafBlock*)_this, a2, a3);
		}
		catch (...) {
			return original(_this, a2, a3);
		}
	}
	return original(_this, a2, a3);
}



THook(void, "?tick@Level@@UEAAXXZ", Level* _this) {
	if (Settings::FastLeafDecay)
	{
		try {
			Module::FastLeafDecayFunc();
		}
		catch (...) {
			return original(_this);
		}
	}
	return original(_this);
}

TInstanceHook(void, "?_updateServer@FishingHook@@IEAAXXZ", FishingHook) {
	if (Settings::AutoFish)
	{
		try {
			Module::AutoFish(this);
		}
		catch (...) {
			return original(this);
		}
	}
	return original(this);
}

TInstanceHook(bool, "?use@DoorBlock@@UEBA_NAEAVPlayer@@AEBVBlockPos@@E@Z", DoorBlock, Player* pl, BlockPos* a3, UCHAR a4) {
	if (Settings::DoubleDoors && this->getTypeName() != "minecraft:iron_door") {
		try {
			Module::DoubleDoors(this, pl, a3, a4);
		}
		catch (...) {
			return  original(this, pl, a3, a4);
		}
	}		
	return  original(this, pl, a3, a4);
}

TInstanceHook(__int64, "?interact@Player@@QEAA_NAEAVActor@@AEBVVec3@@@Z",
	Player, Actor* a2, Vec3* a3) {
	if (Settings::FastSetMinecart) {
		if (this->isSneaking() && a2->getTypeName() == "minecraft:minecart")
			try {
			Module::FastSetMinecart(this, a2);
		}
		catch (...) {
			return original(this, a2, a3);
		}
	}
	return original(this, a2, a3);
}


#include <MC/PlayerInventory.hpp>
#include <MC/GameMode.hpp>
#include <MC/Inventory.hpp>
#include <MC/ServerPlayer.hpp>
#include <MC/NetworkItemStackDescriptor.hpp>

TInstanceHook(void, "?useItem@Player@@UEAAXAEAVItemStackBase@@W4ItemUseMethod@@_N@Z", Player, ItemStackBase& item, int a2, bool a3)
{
	auto itemname = item.getItem()->getSerializedName();
	auto aux = item.getAuxValue();
	original(this, item, a2, a3);
	try {
		if (Settings::AutoSupplyItem) Module::UseItemSupply(this, item, itemname, aux);
	}
	catch(...) {
		return;
	}
}

TInstanceHook(bool, "?hurtAndBreak@ItemStackBase@@QEAA_NHPEAVActor@@@Z", ItemStack, int a1, Actor* a2)
{ 
	auto itemname = getItem()->getSerializedName();
	auto out = original(this, a1,a2);
	try {
		if (Settings::AutoSupplyItem) {
			if (a2->isPlayer()) {
				auto sp = (ServerPlayer*)a2;
				if ((int)getNbt()->getByte("Count") == 0) {
					Module::UseItemSupply(sp, itemname);
				}
			}
		}
	}
	catch (...) {
		return out;
	}
	return out;
}

#include <MC/SurvivalMode.hpp>

TInstanceHook(bool, "?destroyBlock@GameMode@@UEAA_NAEBVBlockPos@@E@Z",
	GameMode, BlockPos a3, unsigned __int8 a4)
{
	if (!Settings::CuttingTree) return original(this, a3, a4);
	try {
		Module::cutTree(&getPlayer()->getRegion(), a3, getPlayer());
	}
	catch (...) {
		return  original(this, a3, a4);
	}
	return original(this, a3, a4);
}
#include <MC/ChunkSource.hpp>
#include <MC/LevelChunkMetaData.hpp>

#include <MC/LevelChunkMetaDataDictionary.hpp>
TInstanceHook(bool, "?baseUseItem@GameMode@@QEAA_NAEAVItemStack@@@Z",
	GameMode, ItemStack* item)
{
	auto sp = getPlayer();
	try {
		if (Settings::BetterThanMending) {
			if (sp->isSneaking()) {
				Module::BetterThanMending(sp);
			}
		}
		if (Settings::CuttingTree) {
			Module::cutTreeLore(sp, sp->getHandSlot());
		}
	}
	catch (...) {
		return original(this, item);
	}
	return original(this, item);
}

TInstanceHook(bool, "?canChangeDimensionsUsingPortal@FallingBlock@@UEBA_NXZ", FallingBlock) {
	if (Settings::EndPortalDuplicateGravityBlock) {
		return isAlive();
	}
	return original(this);
}
#if 0
TInstanceHook(AdventureSettingsPacket&, "??0AdventureSettingsPacket@@QEAA@AEBUAdventureSettings@@AEBVLayeredAbilities@@UActorUniqueID@@@Z",
	AdventureSettingsPacket, struct AdventureSettings const& settings, class Abilities const& abilities, struct ActorUniqueID uniqueId)
{
	auto& pkt = original(this, settings, abilities, uniqueId);
	if (abilities.getAbility(AbilitiesIndex::MayFly).getBool() && abilities.getAbility(AbilitiesIndex::Flying).getBool()) {
		pkt.mFlag |= (int)AdventureFlag::Flying;
	}
	return pkt;
}
#endif

#include <MC/UpdateAdventureSettingsPacket.hpp>
#include <MC/UpdateAbilitiesPacket.hpp>
#include <MC/LayeredAbilities.hpp>
#include <mc/Ability.hpp>
enum class AbilitiesLayer;
TInstanceHook(void, "?handle@ServerNetworkHandler@@UEAAXAEBVNetworkIdentifier@@AEBVRequestAbilityPacket@@@Z",
	ServerNetworkHandler, class NetworkIdentifier const& nid, class RequestAbilityPacket const& pkt)
{
	original(this, nid, pkt);
	auto index = pkt.getAbility();
	if (index == AbilitiesIndex::Flying)
	{
		auto sp = getServerPlayer(nid);
		if (!sp)
			return;
		if (!sp->getUserEntityIdentifierComponent())
			return;
		bool flying;
		if (!pkt.tryGetBool(flying))
			return;
		auto abilities = &dAccess<LayeredAbilities>(sp, 2196);
		auto mayFly = abilities->getAbility(AbilitiesIndex::MayFly).getBool();
		flying = flying && mayFly;
		Ability& ab = abilities->getAbility(AbilitiesLayer(1), AbilitiesIndex::Flying);
		ab.setBool(0);
		if (flying)
			ab.setBool(1);
		UpdateAbilitiesPacket pkt(sp->getUniqueID(), *abilities);
		auto pkt2 = UpdateAdventureSettingsPacket(AdventureSettings());
		abilities->setAbility(AbilitiesIndex::Flying, flying);
		sp->sendNetworkPacket(pkt2);
		sp->sendNetworkPacket(pkt);
	}
}

#include <MC/BucketItem.hpp>
#include <MC/LootTableContext.hpp>
THook(char, "?dispense@BucketItem@@UEBA_NAEAVBlockSource@@AEAVContainer@@HAEBVVec3@@E@Z",
	BucketItem* _this,
	BlockSource* a2,
	Container* a3,
	unsigned int a4,
	const Vec3* a5,
	unsigned __int8 a6) {
	bool rtn = original(_this, a2, a3, a4, a5, a6);
	//auto t = (ItemStack*)(*(__int64(__fastcall**)(Container*, unsigned long long))(*(unsigned long long*)a3 + 40i64))(a3, a4);//�����Դ�����Ͱ��itemstack
	//logger.info << t->getTypeName() << " " << a5->toBlockPos().toString() << "  " << rtn << logger.endl;
	return rtn;
}
//#include <MC/LeashableComponent.hpp>
//#include <MC/SynchedActorData.hpp>
//#include <MC/VanillaItemNames.hpp>
//#include <MC/ActorComponentFactory.hpp>
//TInstanceHook(void, "?handle@ItemUseOnActorInventoryTransaction@@UEBA?AW4InventoryTransactionError@@AEAVPlayer@@_N@Z",
//	ServerNetworkHandler, ServerPlayer* sp, bool unk) {
//	auto uid = dAccess<ActorRuntimeID, 104>(this);
//	auto id = dAccess<int, 112>(this);
//	if (id == 0) {
//		auto ac = Global<Level>->getRuntimeEntity(uid, true);
//		auto out = SymCall("??$tryGetDefinitionInstance@VLeashableDefinition@@@DefinitionInstanceGroup@@QEBAPEBVLeashableDefinition@@XZ",
//			void*, __int64)(*((__int64*)ac + 31) + 472);
//		if (ac->getEntityTypeId() == ActorType::VillagerV2) {
//			if (!ac->isLeashed()) {
//
//				auto item = sp->getHandSlot();
//				if (!item->isNull() && item->isInstance(VanillaItemNames::Lead, 0)) {
//					ac->dropLeash(0, 1);
//					auto aaa = dAccess<SynchedActorData*>(ac, 376);
//					aaa->setStatusFlag((ActorFlags)30, 1);
//					ac->setLeashHolder(sp->getUniqueID());
//				}
//			}
//		}
//	}
//	return original(this, sp, unk);
//}
