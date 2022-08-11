// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Tag.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ShortTag : public Tag {

#define AFTER_EXTRA
// Add Member There
short val;

public:
    LIAPI short& value();
    LIAPI ShortTag& operator=(short val);
    LIAPI static std::unique_ptr<ShortTag> create(short val = 0);
    LIAPI bool set(short val);
    LIAPI short get();
    LIAPI operator short() const;

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SHORTTAG
public:
    class ShortTag& operator=(class ShortTag const &) = delete;
    ShortTag(class ShortTag const &) = delete;
#endif

public:
    /*0*/ virtual ~ShortTag();
    /*2*/ virtual void write(class IDataOutput &) const;
    /*3*/ virtual void load(class IDataInput &);
    /*4*/ virtual std::string toString() const;
    /*5*/ virtual enum Tag::Type getId() const;
    /*6*/ virtual bool equals(class Tag const &) const;
    /*9*/ virtual std::unique_ptr<class Tag> copy() const;
    /*10*/ virtual unsigned __int64 hash() const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SHORTTAG
#endif
    MCAPI ShortTag(short);
    MCAPI ShortTag();

};