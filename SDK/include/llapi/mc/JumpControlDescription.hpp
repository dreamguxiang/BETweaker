/**
 * @file  JumpControlDescription.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC structure JumpControlDescription.
 *
 */
struct JumpControlDescription {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_JUMPCONTROLDESCRIPTION
public:
    struct JumpControlDescription& operator=(struct JumpControlDescription const &) = delete;
    JumpControlDescription(struct JumpControlDescription const &) = delete;
    JumpControlDescription() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @symbol ?getJsonName@JumpControlDescription@@UEBAPEBDXZ
     * @hash   954376855
     */
    virtual char const * getJsonName() const;
    /**
     * @vftbl  1
     * @hash   -1796870793
     */
    virtual ~JumpControlDescription();
    /**
     * @vftbl  2
     * @symbol ?deserializeData@JumpControlDescription@@UEAAXUDeserializeDataParams@@@Z
     * @hash   -452591588
     */
    virtual void deserializeData(struct DeserializeDataParams);
    /**
     * @vftbl  3
     * @symbol ?serializeData@JumpControlDescription@@UEBAXAEAVValue@Json@@@Z
     * @hash   -2101199978
     */
    virtual void serializeData(class Json::Value &) const;

};