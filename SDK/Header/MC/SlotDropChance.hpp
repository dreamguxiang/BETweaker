// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class SlotDropChance {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SLOTDROPCHANCE
public:
    class SlotDropChance& operator=(class SlotDropChance const &) = delete;
    SlotDropChance(class SlotDropChance const &) = delete;
    SlotDropChance() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SLOTDROPCHANCE
#endif
    MCAPI void setEquipmentSlot(std::string const &);

};