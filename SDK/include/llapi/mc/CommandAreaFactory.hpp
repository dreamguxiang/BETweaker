// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class CommandAreaFactory {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_COMMANDAREAFACTORY
public:
    class CommandAreaFactory& operator=(class CommandAreaFactory const &) = delete;
    CommandAreaFactory(class CommandAreaFactory const &) = delete;
    CommandAreaFactory() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_COMMANDAREAFACTORY
#endif
    MCAPI CommandAreaFactory(class Dimension &);
    MCAPI std::unique_ptr<class CommandArea> findArea(class BlockPos const &, class BlockPos const &, int, bool, bool) const;
    MCAPI std::unique_ptr<class CommandArea> findArea(class BlockPos const &, class BlockPos const &, bool, bool, bool) const;
    MCAPI std::unique_ptr<class CommandArea> findArea(class BlockPos const &, int, bool, bool) const;
    MCAPI std::unique_ptr<class CommandArea> findAreaWithBuffer(class BlockPos const &, class BlockPos const &, int, bool, bool) const;
    MCAPI std::unique_ptr<class CommandArea> findAreaWithBuffer(class BlockPos const &, int, bool, bool) const;
    MCAPI static bool shouldAllowNonTickingPlayerAndTickingAreaChunks(int);

//private:
    MCAPI std::unique_ptr<class CommandArea> _getArea(struct Bounds const &, bool, bool, bool) const;

private:

};