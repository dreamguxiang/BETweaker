// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct FeedItem {

#define AFTER_EXTRA
// Add Member There
struct Effect {
    Effect() = delete;
    Effect(Effect const&) = delete;
    Effect(Effect const&&) = delete;
};

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_FEEDITEM
public:
    struct FeedItem& operator=(struct FeedItem const &) = delete;
    FeedItem() = delete;
#endif
public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_FEEDITEM
#endif
    MCAPI FeedItem(struct FeedItem const &);
    MCAPI void addEffect(struct FeedItem::Effect const &);
    MCAPI struct FeedItem & operator=(struct FeedItem &&);
    MCAPI ~FeedItem();

};