// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Packet.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class LabTablePacket : public Packet {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_LABTABLEPACKET
public:
    class LabTablePacket& operator=(class LabTablePacket const &) = delete;
    LabTablePacket(class LabTablePacket const &) = delete;
#endif

public:
    /*0*/ virtual ~LabTablePacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream &) const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_LABTABLEPACKET
#endif
    MCAPI LabTablePacket();
    MCAPI LabTablePacket(enum LabTablePacket::Type, class BlockPos const &);
    MCAPI LabTablePacket(class BlockPos const &, enum LabTableReactionType);

};