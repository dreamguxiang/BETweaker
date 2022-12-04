/**
 * @file  GetChunksCommand.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Command.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class GetChunksCommand.
 *
 */
class GetChunksCommand : public Command {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_GETCHUNKSCOMMAND
public:
    class GetChunksCommand& operator=(class GetChunksCommand const &) = delete;
    GetChunksCommand(class GetChunksCommand const &) = delete;
    GetChunksCommand() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   1373315289
     */
    virtual ~GetChunksCommand();
    /**
     * @vftbl  1
     * @symbol ?execute@GetChunksCommand@@UEBAXAEBVCommandOrigin@@AEAVCommandOutput@@@Z
     * @hash   2051258244
     */
    virtual void execute(class CommandOrigin const &, class CommandOutput &) const;
    /**
     * @symbol ?setup@GetChunksCommand@@SAXAEAVCommandRegistry@@@Z
     * @hash   769800572
     */
    MCAPI static void setup(class CommandRegistry &);

};