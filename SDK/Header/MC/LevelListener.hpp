// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "BlockSourceListener.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class LevelListener : public BlockSourceListener {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_LEVELLISTENER
public:
    class LevelListener& operator=(class LevelListener const &) = delete;
    LevelListener(class LevelListener const &) = delete;
    LevelListener() = delete;
#endif


public:
    /*0*/ virtual ~LevelListener();
    /*1*/ virtual void __unk_vfn_1();
    /*3*/ virtual void __unk_vfn_3();
    /*4*/ virtual void __unk_vfn_4();
    /*6*/ virtual void __unk_vfn_6();
    /*8*/ virtual void __unk_vfn_8();
    /*9*/ virtual void __unk_vfn_9();
    /*10*/ virtual void __unk_vfn_10();
    /*11*/ virtual class Particle * addParticle(enum ParticleType, class Vec3 const &, class Vec3 const &, int, class CompoundTag const *, bool);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_LEVELLISTENER
    MCVAPI void addBreakingItemParticleEffect(class Vec3 const &, enum ParticleType, struct TextureUVCoordinateSet const &, bool);
    MCVAPI void addParticleEffect(class HashedString const &, class Actor const &, class HashedString const &, class Vec3 const &, class MolangVariableMap const &);
    MCVAPI void addParticleEffect(class HashedString const &, class Vec3 const &, class MolangVariableMap const &);
    MCVAPI void addTerrainParticleEffect(class BlockPos const &, class Block const &, class Vec3 const &, float, float, float);
    MCVAPI void addTerrainSlideEffect(class BlockPos const &, class Block const &, class Vec3 const &, float, float, float);
    MCVAPI void allChanged();
    MCVAPI void levelEvent(enum LevelEvent, class Vec3 const &, int);
    MCVAPI void levelEvent(enum LevelEvent, class CompoundTag const &);
    MCVAPI void levelSoundEvent(enum LevelSoundEvent, class Vec3 const &, int, struct ActorDefinitionIdentifier const &, bool, bool);
    MCVAPI void levelSoundEvent(std::string const &, class Vec3 const &, float, float);
    MCVAPI void onChunkLoaded(class ChunkSource &, class LevelChunk &);
    MCVAPI void onChunkReloaded(class ChunkSource &, class LevelChunk &);
    MCVAPI void onChunkUnloaded(class LevelChunk &);
    MCVAPI void onEntityAdded(class Actor &);
    MCVAPI void onEntityRemoved(class Actor &);
    MCVAPI void onLevelDestruction(std::string const &);
    MCVAPI void onSubChunkLoaded(class ChunkSource &, class LevelChunk &, short);
    MCVAPI void playMusic(std::string const &, class Vec3 const &, float, float);
    MCVAPI void playStreamingMusic(std::string const &, int, int, int);
    MCVAPI void playerListChanged();
    MCVAPI void sendServerLegacyParticle(enum ParticleType, class Vec3 const &, class Vec3 const &, int);
    MCVAPI void stopAllSounds();
    MCVAPI void stopSoundEvent(std::string const &);
    MCVAPI void takePicture(class cg::ImageBuffer &, class Actor *, class Actor *, struct ScreenshotOptions &);
#endif



};