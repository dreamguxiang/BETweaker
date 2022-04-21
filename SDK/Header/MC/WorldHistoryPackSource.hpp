// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

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
    /*3*/ virtual void __unk_vfn_3();
    /*4*/ virtual void __unk_vfn_4();
    /*5*/ virtual class PackSourceReport load(class IPackManifestFactory &, class IContentKeyProvider const &);
    /*
    inline enum PackOrigin getPackOrigin() const{
        enum PackOrigin (WorldHistoryPackSource::*rv)() const;
        *((void**)&rv) = dlsym("?getPackOrigin@WorldHistoryPackSource@@UEBA?AW4PackOrigin@@XZ");
        return (this->*rv)();
    }
    inline void forEachPack(class std::function<void (class Pack &)> a0){
        void (WorldHistoryPackSource::*rv)(class std::function<void (class Pack &)>);
        *((void**)&rv) = dlsym("?forEachPack@WorldHistoryPackSource@@UEAAXV?$function@$$A6AXAEAVPack@@@Z@std@@@Z");
        return (this->*rv)(std::forward<class std::function<void (class Pack &)>>(a0));
    }
    inline void forEachPackConst(class std::function<void (class Pack const &)> a0) const{
        void (WorldHistoryPackSource::*rv)(class std::function<void (class Pack const &)>) const;
        *((void**)&rv) = dlsym("?forEachPackConst@WorldHistoryPackSource@@UEBAXV?$function@$$A6AXAEBVPack@@@Z@std@@@Z");
        return (this->*rv)(std::forward<class std::function<void (class Pack const &)>>(a0));
    }
    inline enum PackType getPackType() const{
        enum PackType (WorldHistoryPackSource::*rv)() const;
        *((void**)&rv) = dlsym("?getPackType@WorldHistoryPackSource@@UEBA?AW4PackType@@XZ");
        return (this->*rv)();
    }
    */

protected:

private:
    MCAPI void _addPackFromHistoryPack(class WorldPackHistory const &);
    MCAPI std::unique_ptr<class Pack> _createPackFromHistoryPack(class WorldPackHistory const &);
    MCAPI bool _readWorldHistoryFile();

};