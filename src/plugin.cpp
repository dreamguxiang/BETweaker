/**
 * @file plugin.cpp
 * @brief The main file of the plugin
 */
#include "global.h"
#include "version.h"
#include "llapi/EventAPI.h"
/**
 * @brief The entrypoint of the plugin. DO NOT remove or rename this function.
 *        
 */
namespace AutoCrafting {
    extern void initializeAutoCrafting();
}

void EventInit() {
    Event::ServerStartedEvent::subscribe([](const Event::ServerStartedEvent) {
        AutoCrafting::initializeAutoCrafting();
        return true;
     });
}

void PluginInit()
{
    EventInit();
    // Your code here
    logger.info("Hello, world!");
}
