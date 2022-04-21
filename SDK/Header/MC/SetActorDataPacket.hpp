// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Packet.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here
#include "DataItem.hpp"
#undef BEFORE_EXTRA

class SetActorDataPacket : public Packet {

#define AFTER_EXTRA
    // Add Member There
public:
    ActorRuntimeID mrid;
    Tick mtick = { 0 };
    std::vector<std::unique_ptr<DataItem>> mitems;

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SETACTORDATAPACKET
public:
    class SetActorDataPacket& operator=(class SetActorDataPacket const &) = delete;
    SetActorDataPacket(class SetActorDataPacket const &) = delete;
#endif

public:
    /*0*/ virtual ~SetActorDataPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream &) const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream &);
    /*
    inline  ~SetActorDataPacket(){
         (SetActorDataPacket::*rv)();
        *((void**)&rv) = dlsym("??1SetActorDataPacket@@UEAA@XZ");
        return (this->*rv)();
    }
    */
    MCAPI SetActorDataPacket(class ActorRuntimeID, class SynchedActorData &, bool);
    MCAPI SetActorDataPacket();

protected:

private:

};