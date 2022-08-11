// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"
#include "MapItemSavedData.hpp"
#include "Item.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class MapItem : public Item {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MAPITEM
public:
    class MapItem& operator=(class MapItem const &) = delete;
    MapItem(class MapItem const &) = delete;
    MapItem() = delete;
#endif

public:
    /*0*/ virtual ~MapItem();
    /*7*/ virtual void __unk_vfn_7();
    /*11*/ virtual void __unk_vfn_11();
    /*14*/ virtual void __unk_vfn_14();
    /*16*/ virtual void __unk_vfn_16();
    /*52*/ virtual void __unk_vfn_52();
    /*54*/ virtual void __unk_vfn_54();
    /*61*/ virtual void appendFormattedHovertext(class ItemStackBase const &, class Level &, std::string &, bool) const;
    /*67*/ virtual void __unk_vfn_67();
    /*71*/ virtual void __unk_vfn_71();
    /*72*/ virtual void __unk_vfn_72();
    /*73*/ virtual void __unk_vfn_73();
    /*76*/ virtual void __unk_vfn_76();
    /*80*/ virtual void __unk_vfn_80();
    /*81*/ virtual void __unk_vfn_81();
    /*96*/ virtual std::string buildDescriptionId(class ItemDescriptor const &, class CompoundTag const *) const;
    /*102*/ virtual bool inventoryTick(class ItemStack &, class Level &, class Actor &, int, bool) const;
    /*103*/ virtual void refreshedInContainer(class ItemStackBase const &, class Level &) const;
    /*107*/ virtual void fixupCommon(class ItemStackBase &, class Level &) const;
    /*117*/ virtual bool isSameItem(class ItemStackBase const &, class ItemStackBase const &) const;
    /*123*/ virtual struct TextureUVCoordinateSet const & getIcon(class ItemStackBase const &, int, bool) const;
    /*125*/ virtual class Item & setIcon(std::string const &, int);
    /*130*/ virtual void __unk_vfn_130();
    /*137*/ virtual std::unique_ptr<class Packet> getUpdatePacket(class ItemStack const &, class Level &, class Actor &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_MAPITEM
#endif
    MCAPI MapItem(std::string const &, short);
    MCAPI void blockTick(class ItemStack &, class BlockSource &, class BlockPos const &) const;
    MCAPI void update(class Level &, class Actor &, class MapItemSavedData &) const;
    MCAPI static std::string const TAG_MAP_INIT;
    MCAPI static std::string const TAG_MAP_NAME_INDEX;
    MCAPI static std::string const TAG_MAP_PLAYER_DISPLAY;
    MCAPI static std::string const TAG_MAP_REGENERATE;
    MCAPI static std::string const TAG_MAP_SCALE;
    MCAPI static std::string const TAG_MAP_SCALING;
    MCAPI static std::string const TAG_MAP_UUID;
    MCAPI static bool doesDisplayPlayerMarkers(class ItemStack const &);
    MCAPI static struct ActorUniqueID getMapId(class CompoundTag const *);
    MCAPI static void markForRegeneration(class ItemInstance &);
    MCAPI static void renderBiomePreviewMap(class Dimension &, class MapItemSavedData &);
    MCAPI static void sampleMapData(class BlockSource &, int, class BlockPos const &, class BlockPos const &, int, int, std::vector<struct MapSample> *, class MapItemSavedData *, class MapItemTrackedActor *, std::vector<struct ClientTerrainPixel> *);
    MCAPI static void serializeMapData(std::vector<struct MapSample> const &, std::string &);
    MCAPI static void setItemInstanceInfo(class ItemInstance &, class MapItemSavedData &);
    MCAPI static void setItemInstanceInfo(class ItemStack &, class MapItemSavedData &);
    MCAPI static void setMapNameIndex(class ItemStack &, int);

//private:
    MCAPI void _makeNewExplorationMap(class ItemStack &, class Level &, class Actor *, std::string &) const;
    MCAPI static void _scheduleMapChunkRendering(class Dimension &, class MapItemSavedData const &, struct MapItemSavedData::ChunkBounds, class std::shared_ptr<bool>);

private:

};