// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Bedrock.hpp"
#include "Core.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class Minecraft {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MINECRAFT
public:
    class Minecraft& operator=(class Minecraft const &) = delete;
    Minecraft(class Minecraft const &) = delete;
    Minecraft() = delete;
#endif

public:
    /*0*/ virtual ~Minecraft();
    /*1*/ virtual void __unk_vfn_1();
    /*2*/ virtual void __unk_vfn_2();
    /*3*/ virtual void setSimTimePause(bool);
    /*4*/ virtual void setSimTimeScale(float);
    /*5*/ virtual bool getSimPaused() const;
    /*6*/ virtual bool isOnlineClient() const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_MINECRAFT
    MCVAPI class StackRefResultT<struct EntityRegistryRefTraits> getEntityRegistry();
    MCVAPI class StackRefResultT<struct EntityRegistryConstRefTraits> getEntityRegistry() const;
#endif
    MCAPI Minecraft(class IMinecraftApp &, class GameCallbacks &, class AllowList &, class PermissionsFile *, class gsl::not_null<class Bedrock::NonOwnerPointer<class Core::FilePathManager>> const &, class std::chrono::duration<__int64, struct std::ratio<1, 1>>, class IMinecraftEventing &, class NetworkHandler &, class PacketSender &, enum SubClientId, class Timer &, class Timer &, class gsl::not_null<class Bedrock::NonOwnerPointer<class IContentTierManager const>> const &, class ServerMetrics *);
    MCAPI void activateAllowList();
    MCAPI void configureGameTest(class Level &, class Experiments const &);
    MCAPI void disconnectClient(class NetworkIdentifier const &, std::string const &);
    MCAPI class MinecraftCommands & getCommands();
    MCAPI class Bedrock::NonOwnerPointer<class Editor::IEditorManager> getEditorManager();
    MCAPI class GameModuleServer & getGameModuleServer();
    MCAPI class optional_ref<class MinecraftGameTest> getGameTest();
    MCAPI double getLastTimestep();
    MCAPI class Level * getLevel() const;
    MCAPI class NetworkHandler & getNetworkHandler();
    MCAPI class ResourcePackManager & getResourceLoader();
    MCAPI class Bedrock::NonOwnerPointer<class ServerNetworkHandler> getServerNetworkHandler();
    MCAPI class gsl::not_null<class Bedrock::NonOwnerPointer<class StructureManager>> getStructureManager();
    MCAPI bool hostMultiplayer(std::string const &, struct std::pair<std::unique_ptr<class Level>, class OwnerPtrT<struct EntityRefTraits>>, class Player *, class mce::UUID const &, std::unique_ptr<class NetEventCallback>, int, bool, bool, std::vector<std::string> const &, std::string, struct ConnectionDefinition const &, class std::unordered_map<struct PackIdVersion, std::string, struct std::hash<struct PackIdVersion>, struct std::equal_to<struct PackIdVersion>, class std::allocator<struct std::pair<struct PackIdVersion const, std::string>>> const &, class Scheduler &, class TextFilteringProcessor *);
    MCAPI void init();
    MCAPI void initAsDedicatedServer();
    MCAPI bool isLeaveGameDone() const;
    MCAPI void requestResourceReload();
    MCAPI bool requestServerShutdown();
    MCAPI void startLeaveGame(bool);
    MCAPI bool update();

//private:
    MCAPI void _tryCatchupMovementTicks();

private:

};