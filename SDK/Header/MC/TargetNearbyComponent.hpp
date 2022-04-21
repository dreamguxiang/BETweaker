// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class TargetNearbyComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_TARGETNEARBYCOMPONENT
public:
    class TargetNearbyComponent& operator=(class TargetNearbyComponent const &) = delete;
    TargetNearbyComponent(class TargetNearbyComponent const &) = delete;
    TargetNearbyComponent() = delete;
#endif

public:
    MCAPI bool getWasInsideRange() const;
    MCAPI bool getWasOutsideRange() const;
    MCAPI bool getWasSeenLastTick() const;
    MCAPI void setPreviousDistance(float);
    MCAPI void setWasInsideRange(bool);
    MCAPI void setWasOutsideRange(bool);
    MCAPI void setWasSeenLastTick(bool);

protected:

private:

};