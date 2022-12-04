/**
 * @file  WardenVibrationConfig.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

/**
 * @brief MC class WardenVibrationConfig.
 *
 */
class WardenVibrationConfig {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_WARDENVIBRATIONCONFIG
public:
    class WardenVibrationConfig& operator=(class WardenVibrationConfig const &) = delete;
    WardenVibrationConfig(class WardenVibrationConfig const &) = delete;
    WardenVibrationConfig() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   1048175837
     */
    virtual ~WardenVibrationConfig();
    /**
     * @vftbl  1
     * @symbol ?onSignalReceive@WardenVibrationConfig@@UEAAXAEAVBlockSource@@VBlockPos@@AEBVGameEvent@@PEAVActor@@M3@Z
     * @hash   -1982159793
     */
    virtual void onSignalReceive(class BlockSource &, class BlockPos, class GameEvent const &, class Actor *, float, class Actor *);
    /**
     * @vftbl  2
     * @symbol ?isValidVibration@WardenVibrationConfig@@UEAA_NAEBVGameEvent@@@Z
     * @hash   -1090569769
     */
    virtual bool isValidVibration(class GameEvent const &);
    /**
     * @vftbl  3
     * @symbol ?shouldListen@WardenVibrationConfig@@UEAA_NAEAVBlockSource@@AEBVGameEvent@@AEBUGameEventContext@@@Z
     * @hash   -1056965466
     */
    virtual bool shouldListen(class BlockSource &, class GameEvent const &, struct GameEventContext const &);
    /**
     * @symbol ??0WardenVibrationConfig@@QEAA@AEAVActor@@G@Z
     * @hash   -1363690370
     */
    MCAPI WardenVibrationConfig(class Actor &, unsigned short);

};