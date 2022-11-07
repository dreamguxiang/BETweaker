// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"
#include "Boat.hpp"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class ChestBoat : public Boat {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CHESTBOAT
public:
    class ChestBoat& operator=(class ChestBoat const &) = delete;
    ChestBoat(class ChestBoat const &) = delete;
    ChestBoat() = delete;
#endif

public:
    /*14*/ virtual ~ChestBoat();
    /*40*/ virtual void __unk_vfn_40();
    /*60*/ virtual void __unk_vfn_60();
    /*67*/ virtual void __unk_vfn_67();
    /*81*/ virtual void __unk_vfn_81();
    /*84*/ virtual void __unk_vfn_84();
    /*87*/ virtual void __unk_vfn_87();
    /*95*/ virtual void __unk_vfn_95();
    /*98*/ virtual void __unk_vfn_98();
    /*105*/ virtual void __unk_vfn_105();
    /*107*/ virtual void __unk_vfn_107();
    /*108*/ virtual void __unk_vfn_108();
    /*110*/ virtual void __unk_vfn_110();
    /*181*/ virtual void __unk_vfn_181();
    /*195*/ virtual void __unk_vfn_195();
    /*220*/ virtual void __unk_vfn_220();
    /*221*/ virtual void __unk_vfn_221();
    /*247*/ virtual void __unk_vfn_247();
    /*250*/ virtual void __unk_vfn_250();
    /*251*/ virtual void kill();
    /*268*/ virtual void __unk_vfn_268();
    /*276*/ virtual void __unk_vfn_276();
    /*283*/ virtual void __unk_vfn_283();
    /*284*/ virtual void destroy(class Actor *);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CHESTBOAT
#endif
    MCAPI ChestBoat(class ActorDefinitionGroup *, struct ActorDefinitionIdentifier const &, class EntityContext &);

//private:
    MCAPI void _dropChestContents(class Vec3 const &);

private:

};