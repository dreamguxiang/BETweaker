// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

struct ReplaceRule {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_REPLACERULE
public:
    struct ReplaceRule& operator=(struct ReplaceRule const &) = delete;
    ReplaceRule(struct ReplaceRule const &) = delete;
    ReplaceRule() = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_REPLACERULE
#endif
    MCAPI ReplaceRule(class BlockDescriptor, std::vector<class BlockDescriptor>);
    MCAPI ~ReplaceRule();

};