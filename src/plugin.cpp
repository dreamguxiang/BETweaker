/**
 * @file plugin.cpp
 * @brief The main file of the plugin
 */
#include "global.h"

/**
 * @brief The entrypoint of the plugin. DO NOT remove or rename this function.
 *        
 */
namespace AutoCrafting {
    extern void initializeAutoCrafting();
}
extern void RegisterCommands();

void EventInit() {
    Event::ServerStartedEvent::subscribe([](const Event::ServerStartedEvent) {
        AutoCrafting::initializeAutoCrafting();
        return true;
     });
}

void PluginInit()
{
    EventInit();
    RegisterCommands();

}
