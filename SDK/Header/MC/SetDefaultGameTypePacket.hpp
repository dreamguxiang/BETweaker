// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Packet.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class SetDefaultGameTypePacket : public Packet {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SETDEFAULTGAMETYPEPACKET
public:
    class SetDefaultGameTypePacket& operator=(class SetDefaultGameTypePacket const &) = delete;
    SetDefaultGameTypePacket(class SetDefaultGameTypePacket const &) = delete;
#endif

public:
    /*0*/ virtual ~SetDefaultGameTypePacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream &) const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SETDEFAULTGAMETYPEPACKET
#endif
    MCAPI SetDefaultGameTypePacket(enum GameType);
    MCAPI SetDefaultGameTypePacket();

};