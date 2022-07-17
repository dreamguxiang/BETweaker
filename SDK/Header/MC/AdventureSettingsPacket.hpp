// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Packet.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here


#undef BEFORE_EXTRA

class AdventureSettingsPacket : public Packet {

#define AFTER_EXTRA
// Add Member There
public:
    unsigned int mFlag;                             // 48
    CommandPermissionLevel mCommandPermissionLevel; // 52
    unsigned int mActionPermissions;                // 56
    unsigned char mPermissionLevel;                 // 60
    ActorUniqueID mUniqueId;                        // 64
    int unk72;                                      // 72
    unsigned int mCustomStoredPermissions;          // 76
#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ADVENTURESETTINGSPACKET
public:
    class AdventureSettingsPacket& operator=(class AdventureSettingsPacket const &) = delete;
    AdventureSettingsPacket(class AdventureSettingsPacket const &) = delete;
#endif


public:
    /*0*/ virtual ~AdventureSettingsPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream &) const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ADVENTURESETTINGSPACKET
#endif
    MCAPI AdventureSettingsPacket(struct AdventureSettings const &, class LayeredAbilities const &, struct ActorUniqueID);
    MCAPI AdventureSettingsPacket();

//private:
    MCAPI void _initAbilitiesData(class Abilities const &);
    MCAPI void _initCustomCacheData(class Abilities const &);


private:


};