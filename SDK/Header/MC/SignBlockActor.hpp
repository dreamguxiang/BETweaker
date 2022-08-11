// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "BlockActor.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class SignBlockActor : public BlockActor {

#define AFTER_EXTRA
// Add Member There
public:
enum SignType;

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SIGNBLOCKACTOR
public:
    class SignBlockActor& operator=(class SignBlockActor const &) = delete;
    SignBlockActor(class SignBlockActor const &) = delete;
    SignBlockActor() = delete;
#endif

public:
    /*0*/ virtual ~SignBlockActor();
    /*1*/ virtual void load(class Level &, class CompoundTag const &, class DataLoadHelper &);
    /*2*/ virtual bool save(class CompoundTag &) const;
    /*8*/ virtual void onChanged(class BlockSource &);
    /*12*/ virtual void __unk_vfn_12();
    /*16*/ virtual void __unk_vfn_16();
    /*17*/ virtual float getShadowRadius(class BlockSource &) const;
    /*25*/ virtual std::string getImmersiveReaderText(class BlockSource &);
    /*28*/ virtual void __unk_vfn_28();
    /*29*/ virtual void __unk_vfn_29();
    /*30*/ virtual void __unk_vfn_30();
    /*32*/ virtual void __unk_vfn_32();
    /*33*/ virtual void __unk_vfn_33();
    /*34*/ virtual void __unk_vfn_34();
    /*35*/ virtual std::unique_ptr<class BlockActorDataPacket> _getUpdatePacket(class BlockSource &);
    /*36*/ virtual void _onUpdatePacket(class CompoundTag const &, class BlockSource &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_SIGNBLOCKACTOR
#endif
    MCAPI SignBlockActor(class BlockPos const &);
    MCAPI std::string const & getMessage();
    MCAPI class mce::Color const & getSignTextColor() const;
    MCAPI bool isBug471852Resolved() const;
    MCAPI void resolveBug471852();
    MCAPI void setMessage(std::string, std::string);
    MCAPI void setMessage(class TextObjectRoot, std::string);
    MCAPI void setSignTextColor(class mce::Color const &);
    MCAPI void setType(enum SignBlockActor::SignType);

};