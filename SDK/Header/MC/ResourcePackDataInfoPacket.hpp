// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Packet.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ResourcePackDataInfoPacket : public Packet {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_RESOURCEPACKDATAINFOPACKET
public:
    class ResourcePackDataInfoPacket& operator=(class ResourcePackDataInfoPacket const &) = delete;
    ResourcePackDataInfoPacket(class ResourcePackDataInfoPacket const &) = delete;
#endif

public:
    /*0*/ virtual ~ResourcePackDataInfoPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream &) const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_RESOURCEPACKDATAINFOPACKET
#endif
    MCAPI ResourcePackDataInfoPacket(std::string const &, unsigned int, int, unsigned __int64, std::string const &, bool, enum PackType);
    MCAPI ResourcePackDataInfoPacket();

};