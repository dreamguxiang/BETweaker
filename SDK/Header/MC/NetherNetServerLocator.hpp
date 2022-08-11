// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "RakNet.hpp"
#include "StubServerLocator.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class NetherNetServerLocator : public StubServerLocator {

#define AFTER_EXTRA
// Add Member There
public:
struct ServerData {
    ServerData() = delete;
    ServerData(ServerData const&) = delete;
    ServerData(ServerData const&&) = delete;
};

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_NETHERNETSERVERLOCATOR
public:
    class NetherNetServerLocator& operator=(class NetherNetServerLocator const &) = delete;
    NetherNetServerLocator(class NetherNetServerLocator const &) = delete;
#endif

public:
    /*0*/ virtual ~NetherNetServerLocator();
    /*2*/ virtual void __unk_vfn_2();
    /*3*/ virtual void startAnnouncingServer(std::string const &, std::string const &, enum GameType, int, int, bool, bool);
    /*4*/ virtual void stopAnnouncingServer();
    /*5*/ virtual void startServerDiscovery(struct PortPair);
    /*6*/ virtual void stopServerDiscovery();
    /*7*/ virtual void __unk_vfn_7();
    /*8*/ virtual void __unk_vfn_8();
    /*9*/ virtual std::vector<struct PingedCompatibleServer> getServerList() const;
    /*10*/ virtual void clearServerList();
    /*11*/ virtual void update();
    /*12*/ virtual void __unk_vfn_12();
    /*13*/ virtual void __unk_vfn_13();
    /*14*/ virtual void __unk_vfn_14();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_NETHERNETSERVERLOCATOR
#endif
    MCAPI NetherNetServerLocator();

//private:
    MCAPI bool _isNetherNetOverLANAllowed() const;
    MCAPI void _onBroadcastResponseCallback(unsigned __int64, void const *, int);
    MCAPI void _pruneStaleServers(class std::chrono::duration<__int64, struct std::ratio<1, 1>>);
    MCAPI void _setBroadcastDiscoveryResponse(struct NetherNetServerLocator::ServerData const &);
    MCAPI void _setIsAnnouncing(bool);
    MCAPI void _setIsDiscovering(bool);
    MCAPI struct PingedCompatibleServer _transformFrom(unsigned __int64, struct NetherNetServerLocator::ServerData const &);

private:

};