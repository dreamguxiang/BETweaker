// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Social.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PlayerRespawnTelemetryData {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PLAYERRESPAWNTELEMETRYDATA
public:
    class PlayerRespawnTelemetryData& operator=(class PlayerRespawnTelemetryData const &) = delete;
    PlayerRespawnTelemetryData(class PlayerRespawnTelemetryData const &) = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_PLAYERRESPAWNTELEMETRYDATA
#endif
    MCAPI PlayerRespawnTelemetryData();
    MCAPI void WriteEventData(class Social::Events::Event &) const;
    MCAPI void setChangedDimension(bool);
    MCAPI void setJumpDistance(double);
    MCAPI void setLongJumpCount(unsigned int);
    MCAPI void setPositionSourceType(unsigned int);
    MCAPI void setSearchTime(double);
    MCAPI void setShortJumpCount(unsigned int);

//private:

private:
    MCAPI static std::string const mEventName;

};