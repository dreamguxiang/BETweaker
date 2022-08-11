// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "persona.hpp"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class SerializedPersonaPieceHandle {

#define AFTER_EXTRA
public:	
	  std::string name;
	  persona::PieceType type;
	  mce::UUID uuid;
	  bool flag;
	  std::string data;
#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SERIALIZEDPERSONAPIECEHANDLE
public:
    class SerializedPersonaPieceHandle& operator=(class SerializedPersonaPieceHandle const &) = delete;
    SerializedPersonaPieceHandle(class SerializedPersonaPieceHandle const &) = delete;
    SerializedPersonaPieceHandle() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SERIALIZEDPERSONAPIECEHANDLE
#endif
    MCAPI SerializedPersonaPieceHandle(std::string const &, enum persona::PieceType, class mce::UUID, bool, std::string const &);

};