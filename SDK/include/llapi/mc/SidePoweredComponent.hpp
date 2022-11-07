// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "CircuitComponentList.hpp"
#include "CapacitorComponent.hpp"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class SidePoweredComponent : public CapacitorComponent {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SIDEPOWEREDCOMPONENT
public:
    class SidePoweredComponent& operator=(class SidePoweredComponent const &) = delete;
    SidePoweredComponent(class SidePoweredComponent const &) = delete;
    SidePoweredComponent() = delete;
#endif

public:
    /*0*/ virtual ~SidePoweredComponent();
    /*10*/ virtual bool removeSource(class BlockPos const &, class BaseCircuitComponent const *);
    /*17*/ virtual void __unk_vfn_17();
    /*20*/ virtual void __unk_vfn_20();
    /*22*/ virtual bool removeFromAnySourceList(class BaseCircuitComponent const *);
    /*25*/ virtual unsigned char getPoweroutDirection() const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SIDEPOWEREDCOMPONENT
#endif
    MCAPI void addToSideComponents(class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class CircuitComponentList::Item>>> &, class BaseCircuitComponent *);

};