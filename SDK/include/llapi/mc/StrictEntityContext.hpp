// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class StrictEntityContext {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_STRICTENTITYCONTEXT
public:
    class StrictEntityContext& operator=(class StrictEntityContext const &) = delete;
    StrictEntityContext(class StrictEntityContext const &) = delete;
    StrictEntityContext() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_STRICTENTITYCONTEXT
#endif
    MCAPI StrictEntityContext(class EntityContextBase const &);
    MCAPI StrictEntityContext(class EntityRegistryBase &, class EntityId);
    MCAPI StrictEntityContext(class StrictEntityContext &&);
    MCAPI bool isNull() const;
    MCAPI bool operator!=(class StrictEntityContext const &) const;
    MCAPI class StrictEntityContext & operator=(class StrictEntityContext &&);
    MCAPI bool operator==(class StrictEntityContext const &) const;

//protected:
    MCAPI class EntityId _getEntityId() const;
    MCAPI unsigned int _getRegistryId() const;

protected:

};