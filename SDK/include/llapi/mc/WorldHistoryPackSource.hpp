// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Bedrock.hpp"
#include "Core.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class WorldHistoryPackSource {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_WORLDHISTORYPACKSOURCE
public:
    class WorldHistoryPackSource& operator=(class WorldHistoryPackSource const &) = delete;
    WorldHistoryPackSource(class WorldHistoryPackSource const &) = delete;
    WorldHistoryPackSource() = delete;
#endif

public:
    /*0*/ virtual ~WorldHistoryPackSource();
    /*1*/ virtual void __unk_vfn_1();
    /*2*/ virtual void __unk_vfn_2();
    /*3*/ virtual enum PackOrigin getPackOrigin() const;
    /*4*/ virtual enum PackType getPackType() const;
    /*5*/ virtual class PackSourceReport load(class IPackManifestFactory &, class gsl::not_null<class Bedrock::NonOwnerPointer<class IContentKeyProvider const>> const &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_WORLDHISTORYPACKSOURCE
    MCVAPI void forEachPack(class std::function<void (class Pack &)>);
    MCVAPI void forEachPackConst(class std::function<void (class Pack const &)>) const;
#endif
    MCAPI WorldHistoryPackSource(class Core::Path const &, enum PackType);
    MCAPI class Core::PathBuffer<std::string> const & getPathToWorld() const;
    MCAPI static class Core::PathBuffer<std::string> generateHistoryFilePath(class Core::Path const &, enum PackType);

//private:
    MCAPI void _addPackFromHistoryPack(class WorldPackHistory const &);
    MCAPI std::unique_ptr<class Pack> _createPackFromHistoryPack(class WorldPackHistory const &);
    MCAPI bool _readWorldHistoryFile();

private:

};