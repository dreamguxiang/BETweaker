#include "../pch.h"
#include <RegCommandAPI.h>
using namespace RegisterCommandHelper;
enum CommandParameterOption;
class BETCommand : public Command
{

    enum class Operation
    {
        BetterHarvestingCrop,
        NoFarmDestroy,
        FastSleeping
    } operation;
    bool isenable;

public:

    void execute(CommandOrigin const& ori, CommandOutput& output) const override
    {
        switch (operation)
        {
        case Operation::BetterHarvestingCrop:
            Settings::BetterHarvestingCrop = isenable;
            break;
        case Operation::NoFarmDestroy:
            Settings::NoFarmDestroy = isenable;
            break;
        case Operation::FastSleeping:
            Settings::FastSleeping = isenable;
            break;
        default:
            break;
        }
        Settings::reloadJson(JsonFile);
    }

    static void setup(CommandRegistry* registry)
    {
        // Register Cmd
        registry->registerCommand("bet", "BETweaker System",CommandPermissionLevel::Any, { (CommandFlagValue)0 }, { (CommandFlagValue)0x80 });

        // ll version & help
        registry->addEnum<Operation>("Operation_Num", {
            {"betterharvest", Operation::BetterHarvestingCrop},
            {"nofarmdestroy", Operation::NoFarmDestroy},
             {"fastsleep", Operation::FastSleeping}}
        );

        registry->registerOverload<BETCommand>(
            "bet",
            makeMandatory<CommandParameterDataType::ENUM>(&BETCommand::operation, "Operation", "Operation_Num"),
            makeMandatory(&BETCommand::isenable,"Enable"));
    }
};

void RegisterCommands()
{
    Event::RegCmdEvent::subscribe([](Event::RegCmdEvent ev) { // Register commands
        BETCommand::setup(ev.mCommandRegistry);

        return true;
        });
}
