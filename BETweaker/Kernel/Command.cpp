#include "../Global.h"
#include <RegCommandAPI.h>
#include "../Main/Module.h"
#include <MC/ServerPlayer.hpp>
#include <DynamicCommandAPI.h>
#include <MC/AdventureSettings.hpp>
#include <MC/UpdateAbilitiesPacket.hpp>

#include <MC/RequestAbilityPacket.hpp>
#include <MC/ServerPlayer.hpp>
#include "../Main/Helper.hpp"
#include <magic_enum/magic_enum.hpp>
#include <ServerAPI.h>
using namespace RegisterCommandHelper;

#define COMMAND_PERM(X)                                            \
if ((int)ori.getPermissionsLevel() < 1) {                                 \
    output.error("You don't have permission to use this command"); \
    break;                                                         \
}                                                                  \

void BETweakerUpgradeCommand(CommandOutput& output, bool isForce)
{
    std::thread([isForce]() {
        // Set global SEH-Exception handler
        _set_se_translator(seh_exception::TranslateSEHtoCE);
       // checkUpdate();
        }).detach();
}


#include <MC/Abilities.hpp>
#include <MC/LayeredAbilities.hpp>
#include <mc/UpdateAdventureSettingsPacket.hpp>
#include <mc/AdventureSettings.hpp>
enum class AbilitiesLayer;
void setPlayerAbility(Player& player, AbilitiesIndex index, bool value)
{
    ActorUniqueID uid = player.getUniqueID();
	
    auto abilities = player.getAbilities();

    auto flying = abilities->getAbility(AbilitiesIndex::Flying).getBool();
    if (index == AbilitiesIndex::Flying && value && player.isOnGround())
    {
        abilities->setAbility(AbilitiesIndex::MayFly, value);
    }
    if (index == AbilitiesIndex::MayFly && value == false && flying)
    {
        abilities->setAbility(AbilitiesIndex::Flying, false);
    }
    abilities->setAbility(index, value);
    auto mayfly = abilities->getAbility(AbilitiesIndex::MayFly).getBool();
    auto noclip = abilities->getAbility(AbilitiesIndex::NoClip).getBool();
    player.setCanFly(mayfly || noclip);
    if (index == AbilitiesIndex::NoClip)
    {
        abilities->setAbility(AbilitiesIndex::Flying, value);
    }
    flying = abilities->getAbility(AbilitiesIndex::Flying).getBool();
    Ability& ab = abilities->getAbility(AbilitiesLayer(1), AbilitiesIndex::Flying);
    ab.setBool(0);
    if (flying)
        ab.setBool(1);
    UpdateAbilitiesPacket pkt(uid, *abilities);
    auto pkt2= UpdateAdventureSettingsPacket(AdventureSettings());
    abilities->setAbility(AbilitiesIndex::Flying, flying);
    player.sendNetworkPacket(pkt2);
    player.sendNetworkPacket(pkt);
}



void RegHubInfoCommand()
{
    using ParamType = DynamicCommand::ParameterType;

    auto command = DynamicCommand::createCommand("hubinfo", "HubInfo switch", CommandPermissionLevel::Any);

    
    command->mandatory("Hubenable", ParamType::Bool);
    //auto& NoHubList = command->setEnum("NoHubEnum", { "true","false" });

    command->addOverload("Hubenable");

    command->setCallback([](DynamicCommand const& command, CommandOrigin const& origin, CommandOutput& output, std::unordered_map<std::string, DynamicCommand::Result>& results) {
        if (origin.getPlayer()->isPlayer()) {
            auto isenable = results["Hubenable"].getRaw<bool>();
            auto PlayerName = origin.getPlayer()->getRealName();
            if (isenable) {
                Settings::NoHubList.erase(PlayerName);
            }
            else {
                Settings::NoHubList.insert(PlayerName);
            }
            output.success(PlayerName + " Hubinfo " + (isenable ? "open" : "close") + " successful");
            Settings::reloadJson(JsonFile);
        }
        });
    DynamicCommand::setup(std::move(command));
}



void RegFlyCommand()
{
    using ParamType = DynamicCommand::ParameterType;
	
    auto command = DynamicCommand::createCommand("fly", "Flying", CommandPermissionLevel::Any);

	
    auto& FlyList = command->setEnum("FlyList", { "add","remove" });

	
    command->mandatory("enable", ParamType::Bool);
    command->mandatory("PlayerName", ParamType::String);
    command->mandatory("FlyEnum", ParamType::Enum, FlyList);
	
    command->addOverload({"enable"});
    command->addOverload({ FlyList, "PlayerName" });
	
    command->setCallback([](DynamicCommand const& command, CommandOrigin const& origin, CommandOutput& output, std::unordered_map<std::string, DynamicCommand::Result>& results) {
        auto sp = origin.getPlayer();
        if (results["FlyEnum"].isSet) {
            auto action = results["FlyEnum"].get<std::string>();
            switch (do_hash(action.c_str())) {
            case do_hash("add"): {
                if ((int)const_cast<CommandOrigin&>(origin).getPermissionsLevel() > 0) {
                    auto PlayerName = results["PlayerName"].get<std::string>();
                    Settings::FlyPlayerList.insert(PlayerName);
                    output.success("Added " + PlayerName + " to FlyList");
                    Settings::reloadJson(JsonFile);
                }
                else {
                    output.error("You don't have permission to use this command");
                }
                break;
            }
            case do_hash("remove"): {
                if ((int)const_cast<CommandOrigin&>(origin).getPermissionsLevel() > 0) {
                    auto PlayerName = results["PlayerName"].get<std::string>();
                    auto it = std::find(Settings::FlyPlayerList.begin(), Settings::FlyPlayerList.end(), PlayerName);
                    if (it != Settings::FlyPlayerList.end()) {
                        Settings::FlyPlayerList.erase(it);
                        output.success("Removed " + PlayerName + " from FlyList");
                        auto sp = Global<Level>->getPlayer(PlayerName);
                        Settings::reloadJson(JsonFile);
                        if (sp->isPlayer()) {
                            setPlayerAbility(*sp, AbilitiesIndex::MayFly, 0);
                        }
                    }
                    else {
                        output.error("Player " + PlayerName + " is not in FlyList");
                    }
                }
                else {
                    output.error("You don't have permission to use this command");
                }
                break;
            }
            }
        }else{
            if (sp->isPlayer()) {
                auto name = sp->getRealName();
                if (Settings::FlyPlayerList.count(name)) {
                    auto isenable = results["enable"].getRaw<bool>();
                    setPlayerAbility(*sp, AbilitiesIndex::MayFly, isenable);
                    output.success("Set " + name + " " + (isenable ? "enabled" : "disabled") + " flying");
                }
                else {
                    output.error("You are not in FlyList");
                }
            }
        }  
        });
       DynamicCommand::setup(std::move(command));
}

#if 0
void RegEmoteCommand()
{
    using ParamType = DynamicCommand::ParameterType;

    auto command = DynamicCommand::createCommand("emote", "Play Emote", CommandPermissionLevel::Any);


    auto& EmoteList1 = command->setEnum("EmoteList1", { "gui", });
    auto& EmoteList2 = command->setEnum("EmoteList2", { "play" });

    command->mandatory("NameEnum", ParamType::SoftEnum, command->setSoftEnum("NameList", {}));
	
    command->mandatory("EmoteEnum", ParamType::Enum, EmoteList1);
    command->mandatory("EmoteEnum", ParamType::Enum, EmoteList2);

    command->addOverload({ EmoteList1 });
    command->addOverload({ EmoteList2 ,"NameEnum"});

    command->setCallback([](DynamicCommand const& command, CommandOrigin const& origin, CommandOutput& output, std::unordered_map<std::string, DynamicCommand::Result>& results) {
        auto sp = origin.getPlayer();
        auto action = results["EmoteEnum"].get<std::string>();
        switch (do_hash(action.c_str())) {
        case do_hash("gui"): {
			
            break;
        }
        case do_hash("play"): {
            auto name = results["NameEnum"].get<std::string>();
            Module::PlayEmote(sp, name);
            break;
        }
        }
        });
    auto cmd = DynamicCommand::setup(std::move(command));
    Schedule::repeat([cmd] {
        vector<string> out;
        for (auto& i : Module::elist) {
            out.push_back(i.first);
        }
        cmd->addSoftEnumValues("NameList", out);
        }, 200);
}
#endif


class BETCommand : public Command
{

    enum class Operation
    {
        Upgrade,
		Reload,
        BetterHarvestingCrop,
        NoFarmDestroy,
        FastSleeping,
        HUBinfo,
        EditSign,
        DispenserCrops,
        FastLeafDecay,
        AutoFish,
        DoubleDoors,
        FastSetMinecart,
        AutoSupplyItem,
        CuttingTree,
        DispenserDestroyBlock,
        EndPortalDuplicateGravityBlock,
		Fly,
        AnvilRestoration,
        BetterThanMending,
        AutoCrafting,
        RenewableDeepslate,
        RenewableSponges,
        Help,
        Config
    } operation;
	
    bool isenable;
    enum class UpgradeOption
    {
        Force
    }upgradeOption;
    bool hasUpgradeOption;
	
public:

    void execute(CommandOrigin const& ori, CommandOutput& output) const override
    {
        switch (operation)
        {
        case Operation::BetterHarvestingCrop: {
            COMMAND_PERM();
            Settings::BetterHarvestingCrop = isenable;
            auto func = magic_enum::enum_name(Operation::BetterHarvestingCrop).data();
            output.success("§6[BETweaker]§r " + (string)func + " is " + (isenable ? "enabled" : "disabled"));
            break;
        }
        case Operation::NoFarmDestroy: {
            COMMAND_PERM();
            Settings::NoFarmDestroy = isenable;
            auto func1 = magic_enum::enum_name(Operation::NoFarmDestroy).data();
            output.success("§6[BETweaker]§r " + (string)func1 + " is " + (isenable ? "enabled" : "disabled"));
            break;
        }
        case Operation::FastSleeping: {
            COMMAND_PERM();
            Settings::FastSleeping = isenable;
            auto func2 = magic_enum::enum_name(Operation::FastSleeping).data();
            output.success("§6[BETweaker]§r " + (string)func2 + " is " + (isenable ? "enabled" : "disabled"));
            break;
        }
        case Operation::DispenserCrops: {
            COMMAND_PERM();
            Settings::DispenserCrops = isenable;
            auto func3 = magic_enum::enum_name(Operation::DispenserCrops).data();
            output.success("§6[BETweaker]§r " + (string)func3 + " is " + (isenable ? "enabled" : "disabled"));
            break;
        }
        case Operation::EditSign: {
            COMMAND_PERM();
            Settings::EditSign = isenable;
            auto func4 = magic_enum::enum_name(Operation::EditSign).data();
            output.success("§6[BETweaker]§r " + (string)func4 + " is " + (isenable ? "enabled" : "disabled"));
            break;
        }
        case Operation::FastLeafDecay: {
            COMMAND_PERM();
            Settings::FastLeafDecay = isenable;
            auto func5 = magic_enum::enum_name(Operation::FastLeafDecay).data();
            output.success("§6[BETweaker]§r " + (string)func5 + " is " + (isenable ? "enabled" : "disabled"));
            break;
        }
        case Operation::AutoFish: {
            COMMAND_PERM();
            Settings::AutoFish = isenable;
            auto func6 = magic_enum::enum_name(Operation::AutoFish).data();
            output.success("§6[BETweaker]§r " + (string)func6 + " is " + (isenable ? "enabled" : "disabled"));
            break;
        }
        case Operation::DoubleDoors: {
            COMMAND_PERM();
            Settings::DoubleDoors = isenable;
            auto func7 = magic_enum::enum_name(Operation::DoubleDoors).data();
            output.success("§6[BETweaker]§r " + (string)func7 + " is " + (isenable ? "enabled" : "disabled"));
            break;
        }
        case Operation::FastSetMinecart: {
            COMMAND_PERM();
            Settings::FastSetMinecart = isenable;
            auto func8 = magic_enum::enum_name(Operation::FastSetMinecart).data();
            output.success("§6[BETweaker]§r " + (string)func8 + " is " + (isenable ? "enabled" : "disabled"));
            break;
        }
        case Operation::AutoSupplyItem: {
            COMMAND_PERM();
            Settings::AutoSupplyItem = isenable;
            auto func9 = magic_enum::enum_name(Operation::AutoSupplyItem).data();
            output.success("§6[BETweaker]§r " + (string)func9 + " is " + (isenable ? "enabled" : "disabled"));
            break;
        }
        case Operation::CuttingTree: {
            COMMAND_PERM();
            Settings::CuttingTree = isenable;
            auto func10 = magic_enum::enum_name(Operation::CuttingTree).data();
            output.success("§6[BETweaker]§r " + (string)func10 + " is " + (isenable ? "enabled" : "disabled"));
            break;
        }
        case Operation::DispenserDestroyBlock: {
            COMMAND_PERM();
            Settings::DispenserDestroyBlock = isenable;
            auto func11 = magic_enum::enum_name(Operation::DispenserDestroyBlock).data();
            output.success("§6[BETweaker]§r " + (string)func11 + " is " + (isenable ? "enabled" : "disabled"));
            break;
        }
        case Operation::EndPortalDuplicateGravityBlock: {
            COMMAND_PERM();
            Settings::EndPortalDuplicateGravityBlock = isenable;
            auto func12 = magic_enum::enum_name(Operation::EndPortalDuplicateGravityBlock).data();
            output.success("§6[BETweaker]§r " + (string)func12 + " is " + (isenable ? "enabled" : "disabled"));
            break;
        }
        case Operation::BetterThanMending: {
            COMMAND_PERM();
            Settings::BetterThanMending = isenable;
            auto func13 = magic_enum::enum_name(Operation::BetterThanMending).data();
            output.success("§6[BETweaker]§r " + (string)func13 + " is " + (isenable ? "enabled" : "disabled"));
            break;
        }
        case Operation::AnvilRestoration: {
            COMMAND_PERM();
            Settings::AnvilRestoration = isenable;
            auto func14 = magic_enum::enum_name(Operation::AnvilRestoration).data();
            output.success("§6[BETweaker]§r " + (string)func14 + " is " + (isenable ? "enabled" : "disabled"));
            break;
        }
        case Operation::AutoCrafting: {
            COMMAND_PERM();
            Settings::AutoCrafting = isenable;
            auto func15 = magic_enum::enum_name(Operation::AutoCrafting).data();
            output.success("§6[BETweaker]§r " + (string)func15 + " is " + (isenable ? "enabled" : "disabled"));
            break;
        }
        case Operation::RenewableDeepslate: {
            COMMAND_PERM();
            Settings::RenewableDeepslate = isenable;
            auto func16 = magic_enum::enum_name(Operation::RenewableDeepslate).data();
            output.success("§6[BETweaker]§r " + (string)func16 + " is " + (isenable ? "enabled" : "disabled"));
            break;
        }
        case Operation::RenewableSponges: {
            COMMAND_PERM();
            Settings::RenewableSponges = isenable;
            auto func17 = magic_enum::enum_name(Operation::RenewableSponges).data();
            output.success("§6[BETweaker]§r " + (string)func17 + " is " + (isenable ? "enabled" : "disabled"));
            break;
        }
        case Operation::Reload:      
            COMMAND_PERM();
            Settings::LoadConfigFromJson(JsonFile);
            output.success("reload success");
            return;
        case Operation::Fly: {
            COMMAND_PERM();
            auto sp = ori.getPlayer();
            if (sp->isPlayer()) {
                setPlayerAbility(*sp, AbilitiesIndex::MayFly, isenable);
            }
            return;
        }
        
        case Operation::Config: {
            COMMAND_PERM();
            string temp;
            output.success("§6§l————————Feature List————————\n"
                "§bBetterHarvestingCrop §d-> " + temp + (Settings::BetterHarvestingCrop ? "§a✔" : "§c✖") + "\n"
                "§bNoFarmDestroy §d-> " + (Settings::NoFarmDestroy ? "§a✔" : "§c✖") + "\n"
                "§bFastSleeping §d-> " + (Settings::FastSleeping ? "§a✔" : "§c✖") + "\n"
                "§bDispenserCrops §d-> " + (Settings::DispenserCrops ? "§a✔" : "§c✖") + "\n"
                "§bEditSign §d-> " + (Settings::EditSign ? "§a✔" : "§c✖") + "\n"
                "§bFastLeafDecay §d-> " + (Settings::FastLeafDecay ? "§a✔" : "§c✖") + "\n"
                "§bAutoFish §d-> " + (Settings::AutoFish ? "§a✔" : "§c✖") + "\n"
                "§bDoubleDoors §d-> " + (Settings::DoubleDoors ? "§a✔" : "§c✖") + "\n"
                "§bFastSetMinecart §d-> " + (Settings::FastSetMinecart ? "§a✔" : "§c✖") + "\n"
                "§bAutoSupplyItem §d-> " + (Settings::AutoSupplyItem ? "§a✔" : "§c✖") + "\n"
                "§bCuttingTree §d-> " + (Settings::CuttingTree ? "§a✔" : "§c✖") + "\n"
                "§bDispenserDestroyBlock §d-> " + (Settings::DispenserDestroyBlock ? "§a✔" : "§c✖") + "\n"
                "§bEndPortalDuplicateGravityBlock §d-> " + (Settings::EndPortalDuplicateGravityBlock ? "§a✔" : "§c✖") + "\n"
                "§bBetterThanMending §d-> " + (Settings::BetterThanMending ? "§a✔" : "§c✖") + "\n"
                "§bAnvilRestoration §d-> " + (Settings::AnvilRestoration ? "§a✔" : "§c✖") + "\n"
                "§bAutoCrafting §d-> " + (Settings::AutoCrafting ? "§a✔" : "§c✖") + "\n"
                "§bRenewableDeepslate §d-> " + (Settings::RenewableDeepslate ? "§a✔" : "§c✖") + "\n"
                "§bRenewableSponges §d-> " + (Settings::RenewableSponges ? "§a✔" : "§c✖") + "\n"
				"§bSeedCommand §d-> " + (Settings::SeedCommand ? "§a✔" : "§c✖") + "\n"
                "§6———————————————");
            return;
        }
        case Operation::Help:
            output.success("§6§l————————BETweaker————————\n"
                "§bAuthor: §a@DreamGuXiang\n"
                "§bThanks: §a@CanXuee,@ΘΣΦΓΥΔΝ,@tofus | Server:FineServer,CAS\n"
                "§bGithub: §ahttps://github.com/dreamguxiang/BETweaker\n"
                "§bVersion: §a" + VERSION.toString() + " for BDS "+ ll::getBdsVersion() + "\n"
                "§bUsage:\n"
                "§d/bet reload - §6Reload Config\n"
                "§d/bet help - §6Show this help\n"
                "§d/bet §c[feature] §e[enable|disable] - §6Enable or Disable a feature\n"
                "§d/fly §e[enable|disable] - §6Enable or Disable fly\n"
                "§d/hubinfo §e[enable|disable] - §6Enable or Disable HUB info\n"
                "§d/seed - §6Show seed\n"
                "§6§l————————BETweaker————————");
            return;
        case Operation::Upgrade:
            COMMAND_PERM();
            BETweakerUpgradeCommand(output, hasUpgradeOption && upgradeOption == UpgradeOption::Force);
            return;
        }
        Settings::reloadJson(JsonFile);
    }

    static void setup(CommandRegistry* registry)
    {
        // Register Cmd
        registry->registerCommand("betweaker", "BETweaker System", CommandPermissionLevel::Any, { (CommandFlagValue)1 }, { (CommandFlagValue)0x80 });
        registry->registerAlias("betweaker","bet");
        registry->addEnum<Operation>("Function", {
            {"betterharvest", Operation::BetterHarvestingCrop},
            {"nofarmdestroy", Operation::NoFarmDestroy},
            {"fastsleep", Operation::FastSleeping},
            {"dispensercrops", Operation::DispenserCrops},
            {"hubinfo", Operation::HUBinfo},
            {"editsign", Operation::EditSign},
            {"fastleafdecay", Operation::FastLeafDecay},
            {"autofish", Operation::AutoFish},
            {"doubledoors", Operation::DoubleDoors},
            {"fastsetminecart", Operation::FastSetMinecart},
            {"autosupplyitem", Operation::AutoSupplyItem},
            {"cuttingtree", Operation::CuttingTree},
            {"dispenserdestroyblock", Operation::DispenserDestroyBlock},
            {"endportalduplicatgravityblock", Operation::EndPortalDuplicateGravityBlock},
            {"anvilrestoration", Operation::AnvilRestoration},
            {"betterthanmending", Operation::BetterThanMending},
            {"autocrafting", Operation::AutoCrafting},
            {"renewablesponges", Operation::RenewableSponges},
            {"renewabledeepslate", Operation::RenewableDeepslate}
            }
        );
        registry->addEnum<Operation>("BetOperation_OptionalNames", {
            {"reload", Operation::Reload},
            {"help", Operation::Help},
            {"config", Operation::Config},
            });
        registry->addEnum<Operation>("BetOperation_WithOptions", {
            {"upgrade", Operation::Upgrade},
            });
        registry->addEnum<UpgradeOption>("BetUpgradeOptions", { 
            {"force", UpgradeOption::Force} 
            });
		
        registry->registerOverload<BETCommand>(
            "betweaker",
            makeMandatory<CommandParameterDataType::ENUM>(&BETCommand::operation, "Operation", "BetOperation_WithOptions").addOptions((CommandParameterOption)1),
            makeOptional<CommandParameterDataType::ENUM>(&BETCommand::upgradeOption, "Option", "BetUpgradeOptions", &BETCommand::hasUpgradeOption).addOptions((CommandParameterOption)1));
		
        registry->registerOverload<BETCommand>(
            "betweaker",
            makeMandatory<CommandParameterDataType::ENUM>(&BETCommand::operation, "Operation", "Function"),
            makeMandatory(&BETCommand::isenable,"Enable"));

		
        registry->registerOverload<BETCommand>(
            "betweaker",
            makeMandatory<CommandParameterDataType::ENUM>(&BETCommand::operation, "Operation", "BetOperation_OptionalNames").addOptions((CommandParameterOption)1));
		
    }
};
#include <MC/LevelSeed64.hpp>
#include <MC/CommandOutputParameter.hpp>
class SeedCommand : public Command
{

public:

    void execute(CommandOrigin const& ori, CommandOutput& output) const override
    {
        vector<CommandOutputParameter>opt;
        opt.push_back(CommandOutputParameter::CommandOutputParameter(std::to_string(Global<Level>->getLevelSeed64().mSeed)));
        output.success("commands.seed.success",opt);
    }

    static void setup(CommandRegistry* registry)
    {
        // Register Cmd
        registry->registerCommand("seed", "get level's seed", CommandPermissionLevel::GameMasters, { (CommandFlagValue)0 }, { (CommandFlagValue)0x80 });
        registry->registerOverload<SeedCommand>("seed");
    }
};

void RegisterCommands()
{
    Event::RegCmdEvent::subscribe([](Event::RegCmdEvent ev) { // Register commands
        if(Settings::FlyEnabled) RegFlyCommand();
        if (Settings::HUBinfo) RegHubInfoCommand();
       // RegEmoteCommand();
        BETCommand::setup(ev.mCommandRegistry);
       if(Settings::SeedCommand) SeedCommand::setup(ev.mCommandRegistry);
        return true;
        });
}
