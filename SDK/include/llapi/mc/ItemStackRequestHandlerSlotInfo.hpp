/**
 * @file  ItemStackRequestHandlerSlotInfo.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC structure ItemStackRequestHandlerSlotInfo.
 *
 */
struct ItemStackRequestHandlerSlotInfo {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ITEMSTACKREQUESTHANDLERSLOTINFO
public:
    struct ItemStackRequestHandlerSlotInfo& operator=(struct ItemStackRequestHandlerSlotInfo const &) = delete;
    ItemStackRequestHandlerSlotInfo(struct ItemStackRequestHandlerSlotInfo const &) = delete;
#endif

public:
    /**
     * @symbol ??0ItemStackRequestHandlerSlotInfo@@QEAA@XZ
     * @hash   -677437736
     */
    MCAPI ItemStackRequestHandlerSlotInfo();
    /**
     * @symbol ??BItemStackRequestHandlerSlotInfo@@QEBA_NXZ
     * @hash   -863942484
     */
    MCAPI operator bool() const;
    /**
     * @symbol ??1ItemStackRequestHandlerSlotInfo@@QEAA@XZ
     * @hash   2116725272
     */
    MCAPI ~ItemStackRequestHandlerSlotInfo();

};