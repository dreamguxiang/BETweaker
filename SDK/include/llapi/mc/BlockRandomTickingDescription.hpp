// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct BlockRandomTickingDescription {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLOCKRANDOMTICKINGDESCRIPTION
public:
    struct BlockRandomTickingDescription& operator=(struct BlockRandomTickingDescription const &) = delete;
    BlockRandomTickingDescription(struct BlockRandomTickingDescription const &) = delete;
    BlockRandomTickingDescription() = delete;
#endif
public:
    /*0*/ virtual ~BlockRandomTickingDescription();
    /*1*/ virtual std::string const & getName() const;
    /*2*/ virtual void initializeComponent(class EntityContext &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_BLOCKRANDOMTICKINGDESCRIPTION
#endif
    MCAPI static std::string const NameID;
    MCAPI static void bindType();

};