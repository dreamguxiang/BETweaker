#pragma once
#include "../Global.h"
#include <MC/I18n.hpp>
#include <MC/HashedString.hpp>
#include <MC/ToastRequestPacket.hpp>
#include <MC/ServerPlayer.hpp>
#include <mc/ItemStackNetIdVariant.hpp>
struct NetworkIdentifierWithSubId;
class PacketSender {
public:
	uint8_t mSenderSubId;

	virtual ~PacketSender() {}
	virtual void send(Packet&) = 0;
	virtual void sendToServer(Packet&) = 0;
	virtual void sendToClient(NetworkIdentifier const&, Packet const&, uint8_t subId) = 0;
	virtual void sendToClients(std::vector<NetworkIdentifierWithSubId> const&, Packet const&) = 0;
	virtual void sendBroadcast(Packet const&) = 0;
	virtual void sendBroadcast(NetworkIdentifier const&, uint8_t mSubId, Packet const&) = 0;
	virtual void flush(NetworkIdentifier const&, std::function<void()>) = 0;
};
#include <MC/Types.hpp>
#include <MC/KeyOrNameResult.hpp>

namespace Helper {

	inline static struct KeyOrNameResult buildActorDisplayName(enum ActorType a0, std::string const& a1, class Actor const* a2) {
		struct KeyOrNameResult(*rv)(enum ActorType, std::string const&, class Actor const*);
		*((void**)&rv) = dlsym("?buildActorDisplayName@@YA?AUKeyOrNameResult@@W4ActorType@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEBVActor@@@Z");
		return (*rv)(std::forward<enum ActorType>(a0), std::forward<std::string const&>(a1), std::forward<class Actor const*>(a2));
	}
	
	inline string buildActorDisplayNames(ActorType a2, string a3, Actor* a4) {
		auto key = buildActorDisplayName(a2, a3, a4);
		if (!key.misKey) {
			return key.mName;
		}
		return "";
	}

	inline string getDisplayName(string displayname, string lang) {
		auto a1 = I18n::get(displayname, I18n::getLanguage(lang));
		return a1;
	}
	
	inline string getActorDisplayName(Actor* ac,string lang) {
		if (ac->isPlayer()) return ((Player*)ac)->getRealName();
		return getDisplayName(buildActorDisplayNames(ac->getEntityTypeId(), "", ac), lang);
	}
	
	inline vector<string> split(const string& str, const string& pattern)
	{
		vector<string> res;
		if (str == "")
			return res;
		string strs = str + pattern;
		size_t pos = strs.find(pattern);

		while (pos != strs.npos)
		{
			string temp = strs.substr(0, pos);
			res.push_back(temp);
			strs = strs.substr(pos + 1, strs.size());
			pos = strs.find(pattern);
		}

		return res;
	}

	inline bool isBETstick(Player* sp) {
		auto item = sp->getHandSlot();
		if (item->isNull()) {
			return false;
		}
		auto lore = item->getCustomLore();
		if (lore.empty()) return false;
		if(lore.size()>1){
			if (lore[1] == "§6§lBETweakerStick") {
				//if (EnchantUtils::hasEnchant(Enchant::Type::unbreaking, *item)) {
				return true;
				//}
			}
		}
		return false;
	}
	inline ItemInstance cteateBetStick() {
		auto item = ItemStack::create("minecraft:stick");
		std::vector<string> lore{"§l§kBETweakerStick§r","§6§lBETweakerStick" ,"§kBETweakerStick"};
		item->setCustomLore(lore);
		EnchantUtils::applyEnchant(*item, EnchantmentInstance(Enchant::Type::unbreaking, 0), 1);
		item->setCustomName("§g§lBETStick");
		return ItemInstance(*item);
	}

	inline void sendToast(Player* sp, string title, string msg) {
		ToastRequestPacket pkt(title, msg);
		sp->sendNetworkPacket(pkt);
	}
}

enum class ActorCategory : int
{
	mBoat = 0x20000,
	mNone = 0x0,
	mWaterAnimal = 0x30,
	mWater = 0x20,
	mUndead = 0x4000,
	mPlayer = 0x1,
	mAnimal = 0x10,
	mMob = 0x2,
	mMonster = 0x4,
	mPathable = 0x40,
	mHumanoid = 0x8,
	mTamable = 0x80,
	mRidable = 0x100,
	mItem = 0x400,
	mAmbient = 0x800,
	mVillager = 0x1000,
	mArthropod = 0x2000,
	mZombie = 0x8000,
	mMinecart = 0x10000,
	mBoatrideable = 0x20100,
	mMinecartRidable = 0x10100,
	mHumanoidMonster = 0xC,
	mTamableAnimal = 0x90,
	mUndeadMob = 0x4004,
	mZombieMonster = 0x8004
};


namespace
{
	struct countryLang
	{
		LANGID langId;//
		char country[16];//国际代码缩写
		char lang[32];//
		char userLang[32];//
	};

	const countryLang COUNTRY_LANG[] =
	{
		{0x0804, "CN", "zh", "zh_CN"},//中国
		{0x0409, "US", "en", "en_US"},//美国
		{0x0412, "KR", "ko", "ko_KR"},//韩国
		{0x0411, "JP", "ja", "ja_JP"},//日本
		{0x0421, "ID", "en", "en_ID"},//印度尼西亚
		{0x0407, "DE", "de", "de_DE"},//德国
		{0x040c, "FR", "fr", "fr_Fr"},//法国
		{0x0410, "IT", "it", "it_IT"},//意大利
		{0x0416, "BR", "pt", "pt_BR"},//葡萄牙
		{0x0c0a, "ES", "es", "es_Es"},//西班牙
		{0x0419, "RU", "ru", "ru_RU"},//俄国
		{0x041f, "TR", "tr", "tr_TR"},//土耳其
		{0x042a, "VI", "vi", "vi_VI"},//越南
		{0x041e, "TH", "en", "en_TH"},//泰国
		{0x0809, "GB", "en", "en_US"}//英国
	};
}
//