// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "reflection.hpp"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

class CerealSchemaUpgrade {

#define AFTER_EXTRA

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CEREALSCHEMAUPGRADE
public:
    class CerealSchemaUpgrade& operator=(class CerealSchemaUpgrade const &) = delete;
    CerealSchemaUpgrade(class CerealSchemaUpgrade const &) = delete;
    CerealSchemaUpgrade() = delete;
#endif


public:
    /*0*/ virtual ~CerealSchemaUpgrade();
    /*1*/ virtual void __unk_vfn_1() = 0;
    /*2*/ virtual bool upgradeToNext(class rapidjson::GenericDocument<struct rapidjson::UTF8<char>, class rapidjson::MemoryPoolAllocator<class rapidjson::CrtAllocator>, class rapidjson::CrtAllocator> &) const;
    /*3*/ virtual void __unk_vfn_3();
    /*4*/ virtual void __unk_vfn_4();
    /*5*/ virtual void __unk_vfn_5();
    /*6*/ virtual void __unk_vfn_6();
    /*7*/ virtual void __unk_vfn_7();
    /*8*/ MCAPI class SemVersion const & getPreviousVersion() const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CEREALSCHEMAUPGRADE
#endif
    MCAPI CerealSchemaUpgrade(class SemVersion, std::string const &, std::string const &);
    MCAPI void bindLegacySchema(class reflection::SchemaFactory &);
    MCAPI class SemVersion const & getPreviousVersion() const;
    MCAPI std::string const & getPreviousVersionString() const;
    MCAPI std::string const & getSchemaKey() const;
    MCAPI class SemVersion const & getTargetVersion() const;
    MCAPI void registerLegacySchema();
    MCAPI void setPreviousVersion(class SemVersion const &);



};