/**
 * @file  BrewingStandBlockActor.hpp
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
 * @brief MC class BrewingStandBlockActor.
 *
 */
class BrewingStandBlockActor {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BREWINGSTANDBLOCKACTOR
public:
    class BrewingStandBlockActor& operator=(class BrewingStandBlockActor const &) = delete;
    BrewingStandBlockActor(class BrewingStandBlockActor const &) = delete;
    BrewingStandBlockActor() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_BREWINGSTANDBLOCKACTOR
    /**
     * @symbol ?canPullOutItem@BrewingStandBlockActor@@UEBA_NHHAEBVItemStack@@@Z
     * @hash   -2023531124
     */
    MCVAPI bool canPullOutItem(int, int, class ItemStack const &) const;
    /**
     * @symbol ?canPushInItem@BrewingStandBlockActor@@UEBA_NHHAEBVItemStack@@@Z
     * @hash   -106631690
     */
    MCVAPI bool canPushInItem(int, int, class ItemStack const &) const;
    /**
     * @symbol ?getContainer@BrewingStandBlockActor@@UEAAPEAVContainer@@XZ
     * @hash   -1986529231
     */
    MCVAPI class Container * getContainer();
    /**
     * @symbol ?getContainer@BrewingStandBlockActor@@UEBAPEBVContainer@@XZ
     * @hash   1880716205
     */
    MCVAPI class Container const * getContainer() const;
    /**
     * @symbol ?getContainerSize@BrewingStandBlockActor@@UEBAHXZ
     * @hash   1427957065
     */
    MCVAPI int getContainerSize() const;
    /**
     * @symbol ?getItem@BrewingStandBlockActor@@UEBAAEBVItemStack@@H@Z
     * @hash   -839324222
     */
    MCVAPI class ItemStack const & getItem(int) const;
    /**
     * @symbol ?getMaxStackSize@BrewingStandBlockActor@@UEBAHXZ
     * @hash   -461425464
     */
    MCVAPI int getMaxStackSize() const;
    /**
     * @symbol ?getName@BrewingStandBlockActor@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
     * @hash   -316791939
     */
    MCVAPI std::string getName() const;
    /**
     * @symbol ?load@BrewingStandBlockActor@@UEAAXAEAVLevel@@AEBVCompoundTag@@AEAVDataLoadHelper@@@Z
     * @hash   1884477509
     */
    MCVAPI void load(class Level &, class CompoundTag const &, class DataLoadHelper &);
    /**
     * @symbol ?onChanged@BrewingStandBlockActor@@UEAAXAEAVBlockSource@@@Z
     * @hash   993950886
     */
    MCVAPI void onChanged(class BlockSource &);
    /**
     * @symbol ?onMove@BrewingStandBlockActor@@UEAAXXZ
     * @hash   -1810656647
     */
    MCVAPI void onMove();
    /**
     * @symbol ?save@BrewingStandBlockActor@@UEBA_NAEAVCompoundTag@@@Z
     * @hash   -200896396
     */
    MCVAPI bool save(class CompoundTag &) const;
    /**
     * @symbol ?serverInitItemStackIds@BrewingStandBlockActor@@UEAAXHHV?$function@$$A6AXHAEBVItemStack@@@Z@std@@@Z
     * @hash   1973519719
     */
    MCVAPI void serverInitItemStackIds(int, int, class std::function<void (int, class ItemStack const &)>);
    /**
     * @symbol ?setContainerChanged@BrewingStandBlockActor@@UEAAXH@Z
     * @hash   882403441
     */
    MCVAPI void setContainerChanged(int);
    /**
     * @symbol ?setItem@BrewingStandBlockActor@@UEAAXHAEBVItemStack@@@Z
     * @hash   1817566387
     */
    MCVAPI void setItem(int, class ItemStack const &);
    /**
     * @symbol ?startOpen@BrewingStandBlockActor@@UEAAXAEAVPlayer@@@Z
     * @hash   -378491362
     */
    MCVAPI void startOpen(class Player &);
    /**
     * @symbol ?stopOpen@BrewingStandBlockActor@@UEAAXAEAVPlayer@@@Z
     * @hash   998811198
     */
    MCVAPI void stopOpen(class Player &);
    /**
     * @symbol ?tick@BrewingStandBlockActor@@UEAAXAEAVBlockSource@@@Z
     * @hash   -1777681314
     */
    MCVAPI void tick(class BlockSource &);
#endif
    /**
     * @symbol ??0BrewingStandBlockActor@@QEAA@AEBVBlockPos@@@Z
     * @hash   -1594264031
     */
    MCAPI BrewingStandBlockActor(class BlockPos const &);
    /**
     * @symbol ?brew@BrewingStandBlockActor@@QEAAXXZ
     * @hash   -1009152347
     */
    MCAPI void brew();
    /**
     * @symbol ?getBrewTime@BrewingStandBlockActor@@QEBAHXZ
     * @hash   -371641386
     */
    MCAPI int getBrewTime() const;
    /**
     * @symbol ?getFuelAmount@BrewingStandBlockActor@@QEBAHXZ
     * @hash   -1539395482
     */
    MCAPI int getFuelAmount() const;
    /**
     * @symbol ?getFuelTotal@BrewingStandBlockActor@@QEBAHXZ
     * @hash   -1265248056
     */
    MCAPI int getFuelTotal() const;
    /**
     * @symbol ?setBrewTime@BrewingStandBlockActor@@QEAAXH@Z
     * @hash   567208648
     */
    MCAPI void setBrewTime(int);
    /**
     * @symbol ?setFuelAmount@BrewingStandBlockActor@@QEAAXH@Z
     * @hash   -1705973224
     */
    MCAPI void setFuelAmount(int);
    /**
     * @symbol ?setFuelTotal@BrewingStandBlockActor@@QEAAXH@Z
     * @hash   1018972390
     */
    MCAPI void setFuelTotal(int);
    /**
     * @symbol ?isFuel@BrewingStandBlockActor@@SA_NAEBVItemDescriptor@@@Z
     * @hash   957536497
     */
    MCAPI static bool isFuel(class ItemDescriptor const &);

//private:
    /**
     * @symbol ?canBrew@BrewingStandBlockActor@@AEAA_NXZ
     * @hash   -1793189270
     */
    MCAPI bool canBrew();

private:

};