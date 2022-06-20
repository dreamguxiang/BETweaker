#include "../Global.h"
#include "Module.h"
#include "setting.h"
#include <MC/AdventureSettingsPacket.hpp>
#include <MC/AdventureSettings.hpp>
#include <MC/RequestAbilityPacket.hpp>
#include <MC/ServerPlayer.hpp>
#include <MC/Abilities.hpp>
#include "../Main/Helper.h"
std::mutex DispenserejectItemLock;
bool nodis = false;

THook(void, "?updateSleepingPlayerList@ServerLevel@@UEAAXXZ", ServerLevel* self) {
	original(self);
	if (Settings::FastSleeping) {
		try {
			Module::FastSleep();
		}
		catch (...) {
			return;
		}
	}
}

THook(void, "?transformOnFall@FarmBlock@@UEBAXAEAVBlockSource@@AEBVBlockPos@@PEAVActor@@M@Z", void* __this, void* a2,
	void* a3, void* a4, float a5) {
	if (Settings::NoFarmDestroy) {
		return;
	}
	return original(__this, a2, a3, a4, a5);
}

THook(void, "?ejectItem@DispenserBlock@@IEBAXAEAVBlockSource@@AEBVVec3@@EAEBVItemStack@@AEAVContainer@@H@Z", DispenserBlock* a1,
	struct BlockSource* a2,
	const struct Vec3* a3,
	unsigned __int8 a4,
	const struct ItemStack* a5,
	struct Container* a6,
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
TInstanceHook(void, "?dispenseFrom@DispenserBlock@@MEBAXAEAVBlockSource@@AEBVBlockPos@@@Z", DispenserBlock, BlockSource* a2, BlockPos* a3) {
	if(!Settings::DispenserDestroyBlock) return original(this, a2, a3);
	DispenserBlockActor* BlockEntity = (DispenserBlockActor*)a2->getBlockEntity(*a3);
	if (BlockEntity)
	{
		auto Container = BlockEntity->getContainer();
		((RandomizableBlockActorContainerBase*)BlockEntity)->unPackLootTable(*Global<Level>, *Container, a2->getDimensionId(), 0);
		int v9 = BlockEntity->getRandomSlot();
		auto& items = Container->getItem(v9);
		if (!items.isNull() && items.getCount() > 0)
		{
			//std::cout << Facing::DIRECTIONS[1] << std::endl;
			int face = getFacing(a2->getBlock(*a3));
			auto newpos = a3->neighbor(face);		
			if( Module::DispenserDestroy((BlockActor*)BlockEntity,a2, &newpos, const_cast<ItemStack&>(items),v9, a3)) return;
		}
	}
	return original(this,a2,a3);
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
/*
#include <MC/ShovelItem.hpp>
#include <MC/ServerPlayer.hpp>
TInstanceHook(bool, "?_useOn@ShovelItem@@MEBA_NAEAVItemStack@@AEAVActor@@VBlockPos@@EAEBVVec3@@@Z"
	, ShovelItem, ItemStackBase* a2, Actor* a3, BlockPos& a4, char a5) {
	if (a3->isPlayer()) {
		auto sp = (ServerPlayer*)a3;
		auto block = Level::getBlock(a4, sp->getBlockSource());
		if (VanillaBlocks::mTopSnow && block == VanillaBlocks::mTopSnow) {
			auto i = block->getTileData();
			if (i > 2) {
				Level::setBlock(a4, sp->getDimensionId(), block->getTypeName(), i - 1);
			}
		}
	}
	return original(this, a2, a3, a4, a5);
}
*/


#include <MC/PlayerInventory.hpp>
#include <MC/GameMode.hpp>
#include <MC/Inventory.hpp>
#include <MC/ServerPlayer.hpp>


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

//TInstanceHook(bool, "?destroyBlock@SurvivalMode@@UEAA_NAEBVBlockPos@@E@Z",
//	SurvivalMode, BlockPos a3, unsigned __int8 a4)
//{
//	if (!Settings::CuttingTree) return original(this, a3, a4);
//	auto bs = getPlayer()->getBlockSource();
//	try {
//		Module::cutTree(&getPlayer()->getRegion(), a3, getPlayer());
//	}
//	catch (...) {
//		return  original(this, a3, a4);
//	}
//	return original(this, a3, a4);
//}



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

TInstanceHook(bool, "?baseUseItem@GameMode@@QEAA_NAEAVItemStack@@@Z",
	GameMode, ItemStack* item)
{
	if (!Settings::CuttingTree) return original(this, item);
	try {
		Module::cutTreeLore(getPlayer(), getPlayer()->getHandSlot());
	}
	catch (...) {
		return original(this, item);
	}
	return original(this, item);
}

TInstanceHook(bool, "?canChangeDimensions@FallingBlock@@UEBA_NXZ", FallingBlock) {
	
	return isAlive();
	
	return original(this);
}

TInstanceHook(AdventureSettingsPacket&, "??0AdventureSettingsPacket@@QEAA@AEBUAdventureSettings@@AEBVAbilities@@UActorUniqueID@@_N@Z",
	AdventureSettingsPacket, struct AdventureSettings const& settings, class Abilities const& abilities, struct ActorUniqueID uniqueId, bool unk_0)
{
	auto& pkt = original(this, settings, abilities, uniqueId, unk_0);
	if (abilities.getAbility(AbilitiesIndex::MayFly).getBool() && abilities.getAbility(AbilitiesIndex::Flying).getBool()) {
		pkt.mFlag |= (int)AdventureFlag::Flying;
	}
	return pkt;
}


TInstanceHook(void, "?handle@ServerNetworkHandler@@UEAAXAEBVNetworkIdentifier@@AEBVRequestAbilityPacket@@@Z",
	ServerNetworkHandler, class NetworkIdentifier const& nid, class RequestAbilityPacket const& pkt)
{
	original(this, nid, pkt);
	auto index = pkt.getAbility();
	if (index == AbilitiesIndex::Flying)
	{
		auto sp = _getServerPlayer(nid, pkt.clientSubId);
		if (!sp)
			return;
		if (!sp->getUserEntityIdentifierComponent())
			return;
		bool flying;
		if (!pkt.tryGetBool(flying))
			return;
		auto abilities = &dAccess<Abilities>(sp, 2512);
		auto mayFly = abilities->getAbility(AbilitiesIndex::MayFly).getBool();
		flying = flying && mayFly;
		AdventureSettingsPacket pkt(Global<Level>->getAdventureSettings(), *abilities, sp->getUniqueID(), false);
		pkt.mFlag &= ~static_cast<unsigned int>(AdventureFlag::Flying);
		if (flying)
			pkt.mFlag |= static_cast<unsigned int>(AdventureFlag::Flying);
		abilities->setAbility(AbilitiesIndex::Flying, flying);
		sp->sendNetworkPacket(pkt);
	}
}

//TClasslessInstanceHook(__int64, "?onEvent@VanillaServerGameplayEventListener@@UEAA?AW4EventResult@@AEBUPlayerOpenContainerEvent@@@Z", void* a2)
//{
//	Actor* pl = SymCall("??$tryUnwrap@VActor@@$$V@WeakEntityRef@@QEBAPEAVActor@@XZ", Actor*, void*)(a2);
//	if (pl->isPlayer())
//	{
//		auto sp = (Player*)pl;
//		BlockPos bp = dAccess<BlockPos>(a2, 28);
//		auto blockin = Level::getBlockInstance(bp, pl->getDimensionId());
//		if (sp->isSneaking()) {
//			auto blactor = blockin.getBlockEntity();
//			if (blactor) {
//				if (blactor->getType() == BlockActorType::Dispenser) {
//					Module::ChangeDispenserMode(blactor, pl->getBlockSource(), sp);
//					return 0;
//				}
//			}
//		}
//	}
//	return original(this, a2);
//}

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
	auto t = (ItemStack*)(*(__int64(__fastcall**)(Container*, unsigned long long))(*(unsigned long long*)a3 + 40i64))(a3, a4);//�����Դ�����Ͱ��itemstack
	//logger.info << t->getTypeName() << " " << a5->toBlockPos().toString() << "  " << rtn << logger.endl;
	return rtn;
}

