// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct BlockRotationComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLOCKROTATIONCOMPONENT
public:
    struct BlockRotationComponent& operator=(struct BlockRotationComponent const &) = delete;
    BlockRotationComponent(struct BlockRotationComponent const &) = delete;
    BlockRotationComponent() = delete;
#endif

public:
    MCAPI BlockRotationComponent(class Vec3 const &);
    MCAPI void setRotationDegrees(class Vec3 const &);

protected:

private:

};