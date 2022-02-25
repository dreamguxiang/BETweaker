#pragma once
#include "../Global.h"
#include <MC/I18n.hpp>
#include <MC/HashedString.hpp>

class NetworkIdentifierWithSubId;
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

namespace Helper {
	inline string buildActorDisplayName(ActorType a2, string& a3, Actor* a4) {
		string Src;
		 SymCall("?buildActorDisplayName@@YA?AUKeyOrNameResult@@W4ActorType@@AEBV?$basic_string@DU?$c"
			"har_traits@D@std@@V?$allocator@D@2@@std@@PEBVActor@@@Z", void, string*, ActorType, string&, Actor*)(&Src,a2,a3,a4);
		 return Src;
	}
	inline string getDisplayName(string displayname, string lang) {
		return I18n::get(displayname, I18n::getLanguage(lang));
	}
	inline string getActorDisplayName(Actor* ac,string lang) {
		string a1 = ac->getNameTag();
		auto a2 = ac->getEntityTypeId();
		auto disname = buildActorDisplayName(a2, a1, ac);
		return getDisplayName(disname, lang);
	}

}

enum ActorCategory : int
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
inline string GetDefaultLang()
{
	//LANGID lang_id = GetSystemDefaultLangID();
	LANGID lang_id = GetUserDefaultUILanguage();//"win10>设置>语言>Windows显示语言"
	int size = sizeof(COUNTRY_LANG) / sizeof(COUNTRY_LANG[0]);

	//char _country[16] = { 0 };//国际代码缩写
	//strcpy_s(_country, "US");
	//char _lang[32] = { 0 };//语言
	//strcpy_s(_lang, "en");
	char _userlang[32] = { 0 };//用户语言
	strcpy_s(_userlang, "en_US");

	for (int i = 0; i < size; i++)
	{
		if (lang_id == COUNTRY_LANG[i].langId)
		{
			//memset(_country, 0, sizeof(_country));
			//memset(_lang, 0, sizeof(_lang));
			memset(_userlang, 0, sizeof(_userlang));
			//strcpy(_country, COUNTRY_LANG[i].country);
			//strcpy(_lang, COUNTRY_LANG[i].lang);
			strcpy_s(_userlang, COUNTRY_LANG[i].userLang);
			break;
		}
	}
	return std::string(_userlang);
}