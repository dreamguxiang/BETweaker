// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Social.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class Connector {

#define AFTER_EXTRA
// Add Member There
public:
class ConnectionStateListener {
public:
    ConnectionStateListener() = delete;
    ConnectionStateListener(ConnectionStateListener const&) = delete;
    ConnectionStateListener(ConnectionStateListener const&&) = delete;
};
struct NatPunchInfo {
    NatPunchInfo() = delete;
    NatPunchInfo(NatPunchInfo const&) = delete;
    NatPunchInfo(NatPunchInfo const&&) = delete;
};

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CONNECTOR
public:
    class Connector& operator=(class Connector const &) = delete;
    Connector(class Connector const &) = delete;
    Connector() = delete;
#endif

public:
    /*0*/ virtual ~Connector();
    /*1*/ virtual void __unk_vfn_1();
    /*2*/ virtual std::string getLocalIp();
    /*3*/ virtual void __unk_vfn_3();
    /*4*/ virtual void __unk_vfn_4();
    /*5*/ virtual class Social::GameConnectionInfo const & getConnectedGameInfo() const;
    /*6*/ virtual void __unk_vfn_6();
    /*7*/ virtual struct Connector::NatPunchInfo getNatPunchInfo() const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CONNECTOR
    MCVAPI void addConnectionStateListener(class Connector::ConnectionStateListener *);
    MCVAPI unsigned short getIPv4Port() const;
    MCVAPI unsigned short getIPv6Port() const;
    MCVAPI std::vector<std::string> getLocalIps() const;
    MCVAPI unsigned short getPort() const;
    MCVAPI std::vector<struct RakNet::SystemAddress> getRefinedLocalIps() const;
    MCVAPI bool isIPv4Supported() const;
    MCVAPI bool isIPv6Supported() const;
    MCVAPI void removeConnectionStateListener(class Connector::ConnectionStateListener *);
    MCVAPI void setupNatPunch(bool);
    MCVAPI void startNatPunchingClient(std::string const &, unsigned short);
#endif
    MCAPI Connector(struct Connector::ConnectionCallbacks &);

};