// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ContentLogEndPoint {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CONTENTLOGENDPOINT
public:
    class ContentLogEndPoint& operator=(class ContentLogEndPoint const &) = delete;
    ContentLogEndPoint(class ContentLogEndPoint const &) = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CONTENTLOGENDPOINT
    MCVAPI void log(char const *);
    MCVAPI ~ContentLogEndPoint();
#endif
    MCAPI ContentLogEndPoint();

};