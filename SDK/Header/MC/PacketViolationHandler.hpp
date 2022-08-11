// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PacketViolationHandler {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PACKETVIOLATIONHANDLER
public:
    class PacketViolationHandler& operator=(class PacketViolationHandler const &) = delete;
    PacketViolationHandler(class PacketViolationHandler const &) = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_PACKETVIOLATIONHANDLER
#endif
    MCAPI PacketViolationHandler();
    MCAPI enum PacketViolationResponse checkForViolation(enum MinecraftPacketIds, enum StreamReadResult, class NetworkIdentifier const &, bool *);

//private:
    MCAPI enum PacketViolationResponse _handleViolation(enum MinecraftPacketIds, enum StreamReadResult, class NetworkIdentifier const &, bool *);

private:

};