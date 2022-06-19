#include "../Global.h"
#include <RegCommandAPI.h>
#include "../Main/Module.h"
#include <MC/ServerPlayer.hpp>
#include <MC/AdventureSettingsPacket.hpp>
#include <DynamicCommandAPI.h>
#include <MC/AdventureSettings.hpp>
#include <MC/RequestAbilityPacket.hpp>
#include <MC/ServerPlayer.hpp>
#include "../Main/Helper.h"

using namespace RegisterCommandHelper;

void BETweakerUpgradeCommand(CommandOutput& output, bool isForce)
{
    std::thread([isForce]() {
        // Set global SEH-Exception handler
        _set_se_translator(seh_exception::TranslateSEHtoCE);
       // checkUpdate();
        }).detach();
}


#include <MC/Abilities.hpp>
void setPlayerAbility(Player& player, AbilitiesIndex index, bool value)
{
    ActorUniqueID uid = player.getUniqueID();
	
    auto abilities = &dAccess<Abilities>(&player, 2512);

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
    AdventureSettingsPacket pkt(Global<Level>->getAdventureSettings(), *abilities, uid, false);

    pkt.mFlag &= ~static_cast<unsigned int>(AdventureFlag::Flying);
    if (flying)
        pkt.mFlag |= static_cast<unsigned int>(AdventureFlag::Flying);
    player._sendDirtyActorData();
    player.sendNetworkPacket(pkt);
}



void RegCommand()
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
                if (origin.getPermissionsLevel() > 0) {
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
                if (origin.getPermissionsLevel() > 0) {
                    auto PlayerName = results["PlayerName"].get<std::string>();
                    auto it = std::find(Settings::FlyPlayerList.begin(), Settings::FlyPlayerList.end(), PlayerName);
                    if (it != Settings::FlyPlayerList.end()) {
                        Settings::FlyPlayerList.erase(it);
                        output.success("Removed " + PlayerName + " from FlyList");
                        Settings::reloadJson(JsonFile);
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
        case Operation::BetterHarvestingCrop:
            Settings::BetterHarvestingCrop = isenable;
            output.success(std::to_string(isenable));
            break;
        case Operation::NoFarmDestroy:
            Settings::NoFarmDestroy = isenable;
            output.success(std::to_string(isenable));
            break;
        case Operation::FastSleeping:
            Settings::FastSleeping = isenable;
            output.success(std::to_string(isenable));
            break;
        case Operation::HUBinfo:
            output.error("Due to an unknown bug, this feature is temporarily closed!");
            break;
            //if (Settings::HUBinfo == isenable) break;
            //Settings::HUBinfo = isenable;
            //if (isenable)
            //    Module::HUBInfo();
            //else
            //    hubinfo.cancel();
            //break;
        case Operation::DispenserCrops:
            Settings::DispenserCrops = isenable;
            output.success(std::to_string(isenable));
            break;
        case Operation::EditSign:
            Settings::EditSign = isenable;
            output.success(std::to_string(isenable));
            break;
        case Operation::FastLeafDecay:
            Settings::FastLeafDecay = isenable;
            output.success(std::to_string(isenable));
            break;
        case Operation::AutoFish:
            Settings::AutoFish = isenable;
            output.success(std::to_string(isenable));
            break;
        case Operation::DoubleDoors:
            Settings::DoubleDoors = isenable;
            output.success(std::to_string(isenable));
            break;
        case Operation::FastSetMinecart:
            Settings::FastSetMinecart = isenable;
            output.success(std::to_string(isenable));
            break;
        case Operation::AutoSupplyItem:
            Settings::AutoSupplyItem = isenable;
            output.success(std::to_string(isenable));
            break;
        case Operation::CuttingTree:
            Settings::CuttingTree = isenable;
            output.success(std::to_string(isenable));
            break;
        case Operation::DispenserDestroyBlock:
            Settings::DispenserDestroyBlock = isenable;
            output.success(std::to_string(isenable));
            break;	
        case Operation::EndPortalDuplicateGravityBlock:
            Settings::EndPortalDuplicateGravityBlock = isenable;
            output.success(std::to_string(isenable));
            break;
        case Operation::Reload:
            Settings::LoadConfigFromJson(JsonFile);
            output.success("reload success");
            return;
        case Operation::Fly: {
            auto sp = ori.getPlayer();
            if (sp->isPlayer()) {
                setPlayerAbility(*sp, AbilitiesIndex::MayFly, isenable);           
            }
            return;
        }
        case Operation::Upgrade:
            BETweakerUpgradeCommand(output, hasUpgradeOption && upgradeOption == UpgradeOption::Force);
            return;
        }
        Settings::reloadJson(JsonFile);
    }

    static void setup(CommandRegistry* registry)
    {
        // Register Cmd
        registry->registerCommand("bet", "BETweaker System", CommandPermissionLevel::GameMasters, { (CommandFlagValue)1 }, { (CommandFlagValue)0x80 });

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
            {"endportalduplicatgravityblock", Operation::EndPortalDuplicateGravityBlock}
            }
        );
        registry->addEnum<Operation>("BetOperation_OptionalNames", {
            {"reload", Operation::Reload},
            });
        registry->addEnum<Operation>("BetOperation_WithOptions", {
            {"upgrade", Operation::Upgrade},
            });
        registry->addEnum<UpgradeOption>("BetUpgradeOptions", { 
            {"force", UpgradeOption::Force} 
            });
		
        registry->registerOverload<BETCommand>(
            "bet",
            makeMandatory<CommandParameterDataType::ENUM>(&BETCommand::operation, "Operation", "BetOperation_WithOptions").addOptions((CommandParameterOption)1),
            makeOptional<CommandParameterDataType::ENUM>(&BETCommand::upgradeOption, "Option", "BetUpgradeOptions", &BETCommand::hasUpgradeOption).addOptions((CommandParameterOption)1));
		
        registry->registerOverload<BETCommand>(
            "bet",
            makeMandatory<CommandParameterDataType::ENUM>(&BETCommand::operation, "Operation", "Function"),
            makeMandatory(&BETCommand::isenable,"Enable"));

		
        registry->registerOverload<BETCommand>(
            "bet",
            makeMandatory<CommandParameterDataType::ENUM>(&BETCommand::operation, "Operation", "BetOperation_OptionalNames").addOptions((CommandParameterOption)1));
		
    }
};
#include <MC/CommandOutputParameter.hpp>
class SeedCommand : public Command
{

public:

    void execute(CommandOrigin const& ori, CommandOutput& output) const override
    {
        vector<CommandOutputParameter>opt;
        opt.push_back(CommandOutputParameter::CommandOutputParameter(std::to_string(Global<Level>->getSeed())));
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
        RegCommand();
        BETCommand::setup(ev.mCommandRegistry);
        SeedCommand::setup(ev.mCommandRegistry);
        return true;
        });
}