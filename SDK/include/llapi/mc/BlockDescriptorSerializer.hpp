// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

namespace BlockDescriptorSerializer {

#define AFTER_EXTRA

#undef AFTER_EXTRA
    MCAPI class BlockDescriptor _validateAndCreateFromString(std::string const &);
    MCAPI void fromProxy(class BlockDescriptor &, struct BlockDescriptorSerializer::BlockDescriptorProxy &);
    MCAPI void fromString(class BlockDescriptor &, std::string const &);
    MCAPI struct BlockDescriptorSerializer::BlockDescriptorProxy toProxy(class BlockDescriptor const &);

};