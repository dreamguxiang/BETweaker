/**
 * @file  ActorDefinitionIdentifier.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here
#include "HashedString.hpp"

#undef BEFORE_EXTRA

/**
 * @brief MC structure ActorDefinitionIdentifier.
 *
 */
struct ActorDefinitionIdentifier {

#define AFTER_EXTRA
    // Add Member There
    std::string mNamespace;      // 0
    std::string mIdentifier;     // 32
    std::string mInitEvent;      // 64
    std::string mFullName;       // 96
    HashedString mCanonicalName; // 128

#undef AFTER_EXTRA
public:
    /**
     * @symbol ??0ActorDefinitionIdentifier@@QEAA@XZ
     * @hash   1797423741
     */
    MCAPI ActorDefinitionIdentifier();
    /**
     * @symbol ??0ActorDefinitionIdentifier@@QEAA@W4ActorType@@@Z
     * @hash   -1021302832
     */
    MCAPI ActorDefinitionIdentifier(enum class ActorType);
    /**
     * @symbol ??0ActorDefinitionIdentifier@@QEAA@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00@Z
     * @hash   1940382438
     */
    MCAPI ActorDefinitionIdentifier(std::string, std::string, std::string);
    /**
     * @symbol ??0ActorDefinitionIdentifier@@QEAA@PEBD@Z
     * @hash   1225015889
     */
    MCAPI ActorDefinitionIdentifier(char const *);
    /**
     * @symbol ??0ActorDefinitionIdentifier@@QEAA@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
     * @hash   1570420516
     */
    MCAPI ActorDefinitionIdentifier(std::string const &);
    /**
     * @symbol ??0ActorDefinitionIdentifier@@QEAA@AEBU0@@Z
     * @hash   405035717
     */
    MCAPI ActorDefinitionIdentifier(struct ActorDefinitionIdentifier const &);
    /**
     * @symbol ??0ActorDefinitionIdentifier@@QEAA@$$QEAU0@@Z
     * @hash   143052761
     */
    MCAPI ActorDefinitionIdentifier(struct ActorDefinitionIdentifier &&);
    /**
     * @symbol ?_getLegacyActorType@ActorDefinitionIdentifier@@QEBA?AW4ActorType@@XZ
     * @hash   2140616698
     */
    MCAPI enum class ActorType _getLegacyActorType() const;
    /**
     * @symbol ?clear@ActorDefinitionIdentifier@@QEAAXXZ
     * @hash   -987660449
     */
    MCAPI void clear();
    /**
     * @symbol ?getCanonicalHash@ActorDefinitionIdentifier@@QEBAAEBVHashedString@@XZ
     * @hash   189126974
     */
    MCAPI class HashedString const & getCanonicalHash() const;
    /**
     * @symbol ?getCanonicalName@ActorDefinitionIdentifier@@QEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
     * @hash   1564952222
     */
    MCAPI std::string const & getCanonicalName() const;
    /**
     * @symbol ?getFullName@ActorDefinitionIdentifier@@QEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
     * @hash   1831447342
     */
    MCAPI std::string const & getFullName() const;
    /**
     * @symbol ?getIdentifier@ActorDefinitionIdentifier@@QEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
     * @hash   -1966791060
     */
    MCAPI std::string const & getIdentifier() const;
    /**
     * @symbol ?getInitEvent@ActorDefinitionIdentifier@@QEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
     * @hash   -340443580
     */
    MCAPI std::string const & getInitEvent() const;
    /**
     * @symbol ?getNamespace@ActorDefinitionIdentifier@@QEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
     * @hash   926569350
     */
    MCAPI std::string const & getNamespace() const;
    /**
     * @symbol ?initialize@ActorDefinitionIdentifier@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00@Z
     * @hash   1798730510
     */
    MCAPI void initialize(std::string const &, std::string const &, std::string const &);
    /**
     * @symbol ?initialize@ActorDefinitionIdentifier@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
     * @hash   1887958574
     */
    MCAPI void initialize(std::string const &);
    /**
     * @symbol ?isEmpty@ActorDefinitionIdentifier@@QEBA_NXZ
     * @hash   45704444
     */
    MCAPI bool isEmpty() const;
    /**
     * @symbol ?isVanilla@ActorDefinitionIdentifier@@QEBA_NXZ
     * @hash   1410455324
     */
    MCAPI bool isVanilla() const;
    /**
     * @symbol ??4ActorDefinitionIdentifier@@QEAAAEAU0@AEBU0@@Z
     * @hash   700381246
     */
    MCAPI struct ActorDefinitionIdentifier & operator=(struct ActorDefinitionIdentifier const &);
    /**
     * @symbol ??8ActorDefinitionIdentifier@@QEBA_NAEBU0@@Z
     * @hash   -957112790
     */
    MCAPI bool operator==(struct ActorDefinitionIdentifier const &) const;
    /**
     * @symbol ?setIdentifier@ActorDefinitionIdentifier@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
     * @hash   16140006
     */
    MCAPI void setIdentifier(std::string const &);
    /**
     * @symbol ?setInitEvent@ActorDefinitionIdentifier@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
     * @hash   -320777842
     */
    MCAPI void setInitEvent(std::string const &);
    /**
     * @symbol ??1ActorDefinitionIdentifier@@QEAA@XZ
     * @hash   -1367561299
     */
    MCAPI ~ActorDefinitionIdentifier();
    /**
     * @symbol ?EVENT_BEGIN@ActorDefinitionIdentifier@@2V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@B
     * @hash   1469546769
     */
    MCAPI static std::string const EVENT_BEGIN;
    /**
     * @symbol ?EVENT_END@ActorDefinitionIdentifier@@2V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@B
     * @hash   -1088224975
     */
    MCAPI static std::string const EVENT_END;
    /**
     * @symbol ?NAMESPACE_SEPARATOR@ActorDefinitionIdentifier@@2V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@B
     * @hash   -226721647
     */
    MCAPI static std::string const NAMESPACE_SEPARATOR;

//private:
    /**
     * @symbol ?_initialize@ActorDefinitionIdentifier@@AEAAXXZ
     * @hash   1761659978
     */
    MCAPI void _initialize();
    /**
     * @symbol ?_extractIdentifier@ActorDefinitionIdentifier@@CAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAU1@@Z
     * @hash   -1490454100
     */
    MCAPI static void _extractIdentifier(std::string const &, struct ActorDefinitionIdentifier &);

};