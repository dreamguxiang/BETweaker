// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class MockUnknownBlockTypeRegistry {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MOCKUNKNOWNBLOCKTYPEREGISTRY
public:
    class MockUnknownBlockTypeRegistry& operator=(class MockUnknownBlockTypeRegistry const &) = delete;
    MockUnknownBlockTypeRegistry(class MockUnknownBlockTypeRegistry const &) = delete;
    MockUnknownBlockTypeRegistry() = delete;
#endif

public:
    /*0*/ virtual ~MockUnknownBlockTypeRegistry();
    /*1*/ virtual class Block const & getUnknownBlock(class CompoundTag const &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_MOCKUNKNOWNBLOCKTYPEREGISTRY
#endif

};