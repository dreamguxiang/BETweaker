// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class StringByteOutput {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_STRINGBYTEOUTPUT
public:
    class StringByteOutput& operator=(class StringByteOutput const &) = delete;
    StringByteOutput(class StringByteOutput const &) = delete;
    StringByteOutput() = delete;
#endif

public:
    /*0*/ virtual ~StringByteOutput();
    /*1*/ virtual void writeString(class gsl::basic_string_span<char const, -1>);
    /*2*/ virtual void writeLongString(class gsl::basic_string_span<char const, -1>);
    /*3*/ virtual void writeFloat(float);
    /*4*/ virtual void writeDouble(double);
    /*5*/ virtual void writeByte(char);
    /*6*/ virtual void writeShort(short);
    /*7*/ virtual void writeInt(int);
    /*8*/ virtual void writeLongLong(__int64);
    /*9*/ virtual void writeBytes(void const *, unsigned __int64);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_STRINGBYTEOUTPUT
#endif

};