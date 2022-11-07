// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "FilterTest.hpp"
#include "Json.hpp"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class ActorBoolPropertyTest {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ACTORBOOLPROPERTYTEST
public:
    class ActorBoolPropertyTest& operator=(class ActorBoolPropertyTest const &) = delete;
    ActorBoolPropertyTest(class ActorBoolPropertyTest const &) = delete;
    ActorBoolPropertyTest() = delete;
#endif

public:
    /*0*/ virtual ~ActorBoolPropertyTest();
    /*1*/ virtual bool setup(struct FilterTest::Definition const &, struct FilterInputs const &);
    /*2*/ virtual bool evaluate(struct FilterContext const &) const;
    /*3*/ virtual void __unk_vfn_3();
    /*4*/ virtual class gsl::basic_string_span<char const, -1> getName() const;
    /*5*/ virtual class Json::Value _serializeDomain() const;
    /*6*/ virtual class Json::Value _serializeValue() const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_ACTORBOOLPROPERTYTEST
#endif

};