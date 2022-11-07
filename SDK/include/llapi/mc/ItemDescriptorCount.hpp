// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"
#include "ItemDescriptor.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here
#include "ItemDescriptor.hpp"

#undef BEFORE_EXTRA

class ItemDescriptorCount : public ItemDescriptor {

#define AFTER_EXTRA
// Add Member There
public:
    unsigned short mCount; //72
    char filler[6];

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ITEMDESCRIPTORCOUNT
public:
    class ItemDescriptorCount& operator=(class ItemDescriptorCount const &) = delete;
    ItemDescriptorCount(class ItemDescriptorCount const &) = delete;
#endif

public:
    /*0*/ virtual ~ItemDescriptorCount();
    /*2*/ virtual void serialize(class BinaryStream &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ITEMDESCRIPTORCOUNT
#endif
    MCAPI ItemDescriptorCount();
    MCAPI ItemDescriptorCount(class gsl::basic_string_span<char const, -1>, int, unsigned short);
    MCAPI ItemDescriptorCount(class ItemDescriptor const &, unsigned short);
    MCAPI ItemDescriptorCount(class Item const &, int, unsigned short);
    MCAPI ItemDescriptorCount(class BlockLegacy const &, unsigned short);
    MCAPI ItemDescriptorCount(class Block const &, unsigned short);
    MCAPI ItemDescriptorCount(struct ItemTag const &, unsigned short);
    MCAPI ItemDescriptorCount(class ReadOnlyBinaryStream &);
    MCAPI short getStackSize() const;
    MCAPI void setStackSize(short);

};