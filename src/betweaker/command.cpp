#include <global.h>
#include <llapi/EventAPI.h>
#include <llapi/ServerAPI.h>
#include <magic_enum/magic_enum.hpp>

using namespace RegisterCommandHelper;

#define COMMAND_PERM()                                             \
if ((int)ori.getPermissionsLevel() < 1) {                          \
    output.error("You don't have permission to use this command"); \
    return;                                                        \
}                                                                  \

void BETweakerUpgradeCommand(CommandOutput& output, bool isForce)
{
    std::thread([isForce]() {
        // Set global SEH-Exception handler
        _set_se_translator(seh_exception::TranslateSEHtoCE);
        // checkUpdate();
        }).detach();
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
                settings::NoHubList.erase(PlayerName);
            }
            else {
                settings::NoHubList.insert(PlayerName);
            }
            output.success(PlayerName + " Hubinfo " + (isenable ? "open" : "close") + " successful");
            settings::reloadJson(JsonFile);
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

    command->addOverload({ "enable" });
    command->addOverload({ FlyList, "PlayerName" });

    command->setCallback([](DynamicCommand const& command, CommandOrigin const& origin, CommandOutput& output, std::unordered_map<std::string, DynamicCommand::Result>& results) {
        auto player = origin.getPlayer();
        if (results["FlyEnum"].isSet) {
            if ((int)origin.getPermissionsLevel() > 0) {
                auto action = results["FlyEnum"].get<std::string>();
                auto PlayerName = results["PlayerName"].get<std::string>();
                switch (do_hash(action.c_str())) {
                case do_hash("add"): {
                    settings::FlyPlayerList.insert(PlayerName);
                    output.success("Added " + PlayerName + " to FlyList");
                    settings::reloadJson(JsonFile);
                    break;
                }
                case do_hash("remove"): {
                    auto it = std::find(settings::FlyPlayerList.begin(), settings::FlyPlayerList.end(), PlayerName);
                    if (it != settings::FlyPlayerList.end()) {
                        settings::FlyPlayerList.erase(it);
                        output.success("Removed " + PlayerName + " from FlyList");
                        auto sp = Global<Level>->getPlayer(PlayerName);
                        settings::reloadJson(JsonFile);
                        if (sp->isPlayer()) {
                            sp->setAbility(AbilitiesIndex::MayFly, 0);
                        }
                    }
                    else {
                        output.error("Player " + PlayerName + " is not in FlyList");
                    }
                    break;
                }
                }
            }
            else {
                output.error("You don't have permission to use this command");
            }
        }
        else {
            if (player->isPlayer()) {
                auto name = player->getRealName();
                if (settings::FlyPlayerList.count(name)) {
                    auto isenable = results["enable"].getRaw<bool>();
                    player->setAbility(AbilitiesIndex::MayFly, isenable);
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
    command->addOverload({ EmoteList2 ,"NameEnum" });

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
        DispenserCrops,
        FastLeafDecay,
        AutoFish,
        DoubleDoors,
        FastSetMinecart,
        AutoSupplyItem,
        CuttingTree,
        DispenserDestroyBlock,
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
        auto setAndOutput = [&](auto& setting, auto operation) {
            COMMAND_PERM();
            setting = isenable;
            auto func = magic_enum::enum_name(operation).data();
            output.success("§6[BETweaker]§r " + (string)func + " is " + (isenable ? "enabled" : "disabled"));
        };

        switch (operation)
        {
        case Operation::BetterHarvestingCrop: {
            setAndOutput(settings::BetterHarvestingCrop, Operation::BetterHarvestingCrop);
            break;
        }
        case Operation::NoFarmDestroy: {
            setAndOutput(settings::NoFarmDestroy, Operation::NoFarmDestroy);
            break;
        }
        case Operation::FastSleeping: {
            setAndOutput(settings::FastSleeping, Operation::FastSleeping);
            break;
        }
        case Operation::DispenserCrops: {
            setAndOutput(settings::DispenserCrops, Operation::DispenserCrops);
            break;
        }
        case Operation::FastLeafDecay: {
            setAndOutput(settings::FastLeafDecay, Operation::FastLeafDecay);
            break;
        }
        case Operation::AutoFish: {
            setAndOutput(settings::AutoFish, Operation::AutoFish);
            break;
        }
        case Operation::DoubleDoors: {
            setAndOutput(settings::DoubleDoors, Operation::DoubleDoors);      
            break;
        }
        case Operation::FastSetMinecart: {
            setAndOutput(settings::FastSetMinecart, Operation::FastSetMinecart);  
            break;
        }
        case Operation::AutoSupplyItem: {
            setAndOutput(settings::AutoSupplyItem, Operation::AutoSupplyItem);
            break;
        }
        case Operation::CuttingTree: {
            setAndOutput(settings::CuttingTree, Operation::CuttingTree);
            break;
        }
        case Operation::DispenserDestroyBlock: {
            setAndOutput(settings::DispenserDestroyBlock, Operation::DispenserDestroyBlock);
            break;
        }
        case Operation::BetterThanMending: {
            setAndOutput(settings::BetterThanMending, Operation::BetterThanMending);
            break;
        }
        case Operation::AnvilRestoration: {
            setAndOutput(settings::AnvilRestoration, Operation::AnvilRestoration);
            break;
        }
        case Operation::AutoCrafting: {
            setAndOutput(settings::AutoCrafting, Operation::AutoCrafting);
            break;
        }
        case Operation::RenewableDeepslate: {
            setAndOutput(settings::RenewableDeepslate, Operation::RenewableDeepslate);
            break;
        }
        case Operation::RenewableSponges: {
            setAndOutput(settings::RenewableSponges, Operation::RenewableSponges);
            break;
        }
        case Operation::Reload:
            COMMAND_PERM();
            settings::loadConfigFromJson(JsonFile);
            output.success("reload success");
            return;
        case Operation::Fly: {
            COMMAND_PERM();
            auto sp = ori.getPlayer();
            if (sp->isPlayer()) {
                sp->setAbility(AbilitiesIndex::MayFly, isenable);
            }
            return;
        }

        case Operation::Config: {
            COMMAND_PERM();
            string temp;
            output.success("§6§l————————Feature List————————\n"
                "§bBetterHarvestingCrop §d-> " + temp + (settings::BetterHarvestingCrop ? "§a✔" : "§c✖") + "\n"
                "§bNoFarmDestroy §d-> " + (settings::NoFarmDestroy ? "§a✔" : "§c✖") + "\n"
                "§bFastSleeping §d-> " + (settings::FastSleeping ? "§a✔" : "§c✖") + "\n"
                "§bDispenserCrops §d-> " + (settings::DispenserCrops ? "§a✔" : "§c✖") + "\n"
                "§bFastLeafDecay §d-> " + (settings::FastLeafDecay ? "§a✔" : "§c✖") + "\n"
                "§bAutoFish §d-> " + (settings::AutoFish ? "§a✔" : "§c✖") + "\n"
                "§bDoubleDoors §d-> " + (settings::DoubleDoors ? "§a✔" : "§c✖") + "\n"
                "§bFastSetMinecart §d-> " + (settings::FastSetMinecart ? "§a✔" : "§c✖") + "\n"
                "§bAutoSupplyItem §d-> " + (settings::AutoSupplyItem ? "§a✔" : "§c✖") + "\n"
                "§bCuttingTree §d-> " + (settings::CuttingTree ? "§a✔" : "§c✖") + "\n"
                "§bDispenserDestroyBlock §d-> " + (settings::DispenserDestroyBlock ? "§a✔" : "§c✖") + "\n"
                "§bBetterThanMending §d-> " + (settings::BetterThanMending ? "§a✔" : "§c✖") + "\n"
                "§bAnvilRestoration §d-> " + (settings::AnvilRestoration ? "§a✔" : "§c✖") + "\n"
                "§bAutoCrafting §d-> " + (settings::AutoCrafting ? "§a✔" : "§c✖") + "\n"
                "§bRenewableDeepslate §d-> " + (settings::RenewableDeepslate ? "§a✔" : "§c✖") + "\n"
                "§bRenewableSponges §d-> " + (settings::RenewableSponges ? "§a✔" : "§c✖") + "\n"
                "§bSeedCommand §d-> " + (settings::SeedCommand ? "§a✔" : "§c✖") + "\n"
                "§6———————————————");
            return;
        }
        case Operation::Help:
            output.success("§6§l————————BETweaker————————\n"
                "§bAuthor: §a@DreamGuXiang\n"
                "§bThanks: §a@CanXuee,@ΘΣΦΓΥΔΝ,@tofus | Server:FineServer,CAS\n"
                "§bGithub: §ahttps://github.com/dreamguxiang/BETweaker\n"
                "§bVersion: §a" + BETVERSION.toString() + " for BDS " + ll::getBdsVersion() + "\n"
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
        settings::reloadJson(JsonFile);
    }

    static void setup(CommandRegistry* registry)
    {
        // Register Cmd
        registry->registerCommand("betweaker", "BETweaker System", CommandPermissionLevel::Any, { (CommandFlagValue)1 }, { (CommandFlagValue)0x80 });
        registry->registerAlias("betweaker", "bet");
        registry->addEnum<Operation>("Function", {
            {"betterharvest", Operation::BetterHarvestingCrop},
            {"nofarmdestroy", Operation::NoFarmDestroy},
            {"fastsleep", Operation::FastSleeping},
            {"dispensercrops", Operation::DispenserCrops},
            {"hubinfo", Operation::HUBinfo},
            {"fastleafdecay", Operation::FastLeafDecay},
            {"autofish", Operation::AutoFish},
            {"doubledoors", Operation::DoubleDoors},
            {"fastsetminecart", Operation::FastSetMinecart},
            {"autosupplyitem", Operation::AutoSupplyItem},
            {"cuttingtree", Operation::CuttingTree},
            {"dispenserdestroyblock", Operation::DispenserDestroyBlock},
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
            makeMandatory(&BETCommand::isenable, "Enable"));


        registry->registerOverload<BETCommand>(
            "betweaker",
            makeMandatory<CommandParameterDataType::ENUM>(&BETCommand::operation, "Operation", "BetOperation_OptionalNames").addOptions((CommandParameterOption)1));

    }
};


class LevelSeed64 {
public:
    uint64_t mSeed;
};

class SeedCommand : public Command
{
public:

    void execute(CommandOrigin const& ori, CommandOutput& output) const override
    {
        vector<CommandOutputParameter>opt;
        opt.push_back(CommandOutputParameter::CommandOutputParameter(std::to_string(Global<Level>->getLevelSeed64().mSeed)));
        output.success("commands.seed.success", opt);
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
        if (settings::FlyEnabled) RegFlyCommand();
        if (settings::HUBinfo) RegHubInfoCommand();
        // RegEmoteCommand();
        BETCommand::setup(ev.mCommandRegistry);
        if (settings::SeedCommand) SeedCommand::setup(ev.mCommandRegistry);
        return true;
        });
}