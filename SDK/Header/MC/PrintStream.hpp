// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PrintStream {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PRINTSTREAM
public:
    class PrintStream& operator=(class PrintStream const &) = delete;
    PrintStream(class PrintStream const &) = delete;
    PrintStream() = delete;
#endif

public:
    /*0*/ virtual ~PrintStream();
    /*1*/ virtual void print(std::string const &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_PRINTSTREAM
#endif

};