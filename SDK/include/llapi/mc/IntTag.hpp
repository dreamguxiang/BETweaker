// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Tag.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class IntTag : public Tag {

#define AFTER_EXTRA
// Add Member There
int val;

public:
    LIAPI int& value();
    LIAPI IntTag& operator=(int val);
    LIAPI static std::unique_ptr<IntTag> create(int val = 0);
    LIAPI bool set(int val);
    LIAPI int get();
    LIAPI operator int() const;

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_INTTAG
public:
    class IntTag& operator=(class IntTag const &) = delete;
    IntTag(class IntTag const &) = delete;
#endif

public:
    /*0*/ virtual ~IntTag();
    /*2*/ virtual void write(class IDataOutput &) const;
    /*3*/ virtual void load(class IDataInput &);
    /*4*/ virtual std::string toString() const;
    /*5*/ virtual enum Tag::Type getId() const;
    /*6*/ virtual bool equals(class Tag const &) const;
    /*9*/ virtual std::unique_ptr<class Tag> copy() const;
    /*10*/ virtual unsigned __int64 hash() const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_INTTAG
#endif
    MCAPI IntTag();
    MCAPI IntTag(int);

};