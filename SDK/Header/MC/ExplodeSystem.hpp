// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ExplodeSystem {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_EXPLODESYSTEM
public:
    class ExplodeSystem& operator=(class ExplodeSystem const &) = delete;
    ExplodeSystem(class ExplodeSystem const &) = delete;
    ExplodeSystem() = delete;
#endif

public:
    /*0*/ virtual ~ExplodeSystem();
    /*1*/ virtual void __unk_vfn_1();
    /*2*/ virtual void tick(class EntityRegistry &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_EXPLODESYSTEM
#endif

};