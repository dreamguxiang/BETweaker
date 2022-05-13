#pragma once

#include "HookAPI.h"
#include "../Global.h"
#include "Vec2.hpp"
#include "Vec3.hpp"
#include "BlockPos.hpp"
#include "AABB.hpp"
#include "ChunkPos.hpp"
#include "ChunkBlockPos.hpp"
#include "combaseapi.h"
typedef std::string xuid_t;
typedef unsigned long long QWORD;

namespace mce
{
class UUID
{
    uint64_t a, b;

public:
    MCAPI std::string asString() const;
    MCAPI static UUID fromString(std::string const&);
    MCAPI bool isEmpty() const;
    MCAPI static UUID seedFromString(std::string const&);
    MCAPI static class mce::UUID EMPTY;

    inline operator bool() const
    {
        return !isEmpty();
    }

     static UUID getUUID() {
        GUID guid;
        HRESULT h = CoCreateGuid(&guid);
        if (h == S_OK) {
            char buf[64] = { 0 };
            sprintf_s(buf, sizeof(buf),
                "%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X",
                guid.Data1, guid.Data2, guid.Data3,
                guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3],
                guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);		
            return seedFromString(std::string(buf));
        }
        else
        {
            return  mce::UUID::EMPTY;
        }
    }
};
class Color
{
public:
    float r;
    float g;
    float b;
    float a;
    Color(float r, float g, float b, float a = 1)
        : r(r)
        , g(g)
        , b(b)
        , a(a){};

    inline operator bool() const
    {
        return !(*this == NIL);
    }

    LIAPI double distanceTo(mce::Color const dst) const;
    LIAPI std::string toConsoleCode(bool foreground = true) const;
    LIAPI std::string toNearestColorCode() const;
    LIAPI static class mce::Color fromConsoleCode(std::string const&);
    LIAPI static class mce::Color fromColorCode(std::string const&);

    MCAPI static mce::Color const NIL;
    MCAPI static class mce::Color fromHexString(std::string const&);
    MCAPI bool operator==(class mce::Color const&) const;
    MCAPI int toABGR(void) const;
    MCAPI int toARGB(void) const;
    MCAPI std::string toHexString(void) const;

};

class Blob {
public:
    void* unk0;
    std::unique_ptr<unsigned char[]> buffer;
    size_t length = 0;
	

    inline Blob() {}
    inline Blob(Blob&& rhs) : buffer(std::move(rhs.buffer)), length(rhs.length) { rhs.length = 0; }
    inline Blob(size_t input_length) : buffer(std::make_unique<unsigned char[]>(input_length)), length(input_length) {}
    inline Blob(unsigned char const* input, size_t input_length) : Blob(input_length) {
        memcpy(buffer.get(), input, input_length);
    }

    inline Blob& operator=(Blob&& rhs) {
        if (&rhs != this) {
            buffer = std::move(rhs.buffer);
            length = rhs.length;
            rhs.length = 0;
        }
        return *this;
    }

    inline Blob clone() const { return { data(), size() }; }

    inline unsigned char* begin() { return buffer.get(); }
    inline unsigned char* end() { return buffer.get() + length; }
    inline unsigned char const* cbegin() const { return buffer.get(); }
    inline unsigned char const* cend() const { return buffer.get() + length; }

    inline unsigned char* data() { return buffer.get(); }
    inline unsigned char const* data() const { return buffer.get(); }

    inline bool empty() const { return length == 0; }
    inline size_t size() const { return length; }

    inline auto getSpan() const { return gsl::make_span(data(), size()); }

};

static_assert(sizeof(Blob) == 24);

enum class ImageFormat {
    NONE = 0,
    RGB = 1,
    RGBA = 2
};

enum class ImageUsage : int8_t {
    unknown = 0,
    sRGB = 1,
    data = 2
};

inline unsigned numChannels(ImageFormat format) {
    switch (format) {
    case ImageFormat::RGB:  return 3;
    case ImageFormat::RGBA: return 4;
    default:                return 0;
    }
}

class Image {
    inline Image(ImageFormat format, unsigned width, unsigned height, ImageUsage usage, Blob&& data)
        : format(format), width(width), height(height), usage(usage), data(std::move(data)) {}

public:
    ImageFormat format{}; // 0x0
    unsigned width{}, height{}; // 0x4, 0x8
    ImageUsage usage{}; // 0xC
    Blob data; // 0x10
	
    inline Image(Blob&& data) : data(std::move(data)) {}
    inline Image(unsigned width, unsigned height, ImageFormat format, ImageUsage usage)
        : format(format), width(width), height(height), usage(usage) {}
    inline Image() {}

    inline Image& operator=(Image&& rhs) {
        format = rhs.format;
        width = rhs.width;
        height = rhs.height;
        usage = rhs.usage;
        data = std::move(rhs.data);
        return *this;
    }

    inline Image clone() const { return { format, width, height, usage, data.clone() }; }

    inline void copyRawImage(Blob const& blob) { data = blob.clone(); }

    inline bool isEmpty() const { return data.empty(); }

    inline void resizeImageBytesToFitImageDescription() { data = Blob{ width * height * numChannels(format) }; }

    inline void setImageDescription(unsigned width, unsigned height, ImageFormat format, ImageUsage usage) {
        this->width = width;
        this->height = height;
        this->format = format;
        this->usage = usage;
    }

    inline void setRawImage(Blob&& buffer) { data = std::move(buffer); }
};

static_assert(offsetof(Image, data) == 0x10);
static_assert(offsetof(Image, format) == 0x0);
static_assert(offsetof(Image, usage) == 0xC);
static_assert(sizeof(Image) == 40);


}; // namespace mce

class BoundingBox
{
public:
    BlockPos bpos1;
    BlockPos bpos2;

    inline BlockPos getCenter() const
    {
        return {(bpos1.x + bpos2.x) / 2, (bpos1.y + bpos2.y) / 2, (bpos1.z + bpos2.z) / 2};
    }

    LIAPI AABB toAABB() const;
};

template <typename A, typename T>
class AutomaticID
{
    T id;

public:
    AutomaticID()
    {
        id = 0;
    }

    AutomaticID(T x)
    {
        id = x;
    }

    inline operator T() const
    {
        return id;
    }
};

#include "ActorUniqueID.hpp"

//static_assert(!std::is_pod_v<ActorUniqueID>);


class ActorRuntimeID
{
public:
    unsigned long long id;

    inline unsigned long long get() const
    {
        return id;
    }

    inline operator unsigned long long() const
    {
        return id;
    }
};
//static_assert(std::is_pod_v<ActorRuntimeID>);

#include "RelativeFloat.hpp"

//namespace Core {
//
//class PathPart {
//public:
//    std::string data;
//};
//
//class Path : public PathPart {
//public:
//};
//
//template <typename T>
//class PathBuffer {
//    T value;
//    operator T&() noexcept {
//        return value;
//    }
//    operator T const &() const noexcept {
//        return value;
//    }
//};
//
//}; // namespace Core

class NetherNet
{
public:
    struct NetworkID;
};

namespace gametest
{
class BaseGameTestBatchRunner;

class BaseGameTestFunction;

class BaseGameTestHelper;

class BaseGameTestInstance;

class GameTestBatch;

struct GameTestError;

class GameTestRegistry;

class GameTestTicker;

class IGameTestFunctionContext;

class IGameTestHelperProvider;

struct TestParameters;
}; // namespace gametest

namespace DBHelpers
{
enum Category;
}; // namespace DBHelpers

class AgentCommands
{
public:
    class Command;
};

#include "../MC/Automation.hpp"

class ClientBlobCache
{
public:
    struct Server
    {
        class TransferBuilder;

        class ActiveTransfersManager;
    };
};

class ClientBlockPipeline
{
public:
    template <typename T>
    class VolumeOf;

    struct BlockSchematic;
};

struct ISurfaceBuilder
{
    struct BuildParameters;
};

struct FeatureLoading
{
    template <typename T>
    struct ConcreteFeatureHolder;
    struct FeatureRootParseContext;
    template <typename T>
    struct ConcreteFeatureHolder;
};

template <typename T1, typename T2>
class OperationNode;

struct OperationNodeDetails
{
    template <typename T1, typename T2>
    class WorkingData;
};

struct PositionTrackingDB
{
    class TrackingRecord;
};


struct SubChunkBrightnessStorage
{
    struct LightPair;
};

struct BlockGeometry
{
    struct Model;

    class TessellatedModel;
};

struct CanyonFeatureUtils
{
    struct CanyonConfiguration;
};

class IInPackagePacks
{
public:
    struct MetaData;
};

struct GameEventConfig
{
    enum GameEvents;
};

#include "IMinecraftEventing.hpp"

struct OperationNodeValues
{
    enum Terrain;
};

struct SubChunkStorageUnit
{
    enum PruneType;
};

//Templates
template <typename T, typename T2, int unk>
class TypedServerNetId
{
public:
    T2 netId;
    inline operator T2()
    {
        return netId;
    }
};

template <typename T, typename T2, int unk>
class TypedClientNetId
{
public:
    T2 netId;
};

template <typename T, typename T2, int unk>
class TypedRuntimeId
{
public:
    T2 netId;
};

template <typename T, typename T2>
class AutomaticID;

template<typename T, typename T2>
class BidirectionalUnorderedMap {
public:
    std::unordered_map<T, T2> mMap1;
    std::unordered_map<T2, T> mMap2;
};

template <typename T>
class BlockDataFetchResult;

template <typename T>
class CommandSelectorResults;

template <typename... T>
class Factory;

template <typename T>
class InheritanceTree;

//enum class ItemStackRequestActionType : char;
//template <typename T, ItemStackRequestActionType actionType>
//class ItemStackRequestActionCraft;

template <typename T>
class ItemStateVariant;

template <typename T>
class LevelChunkGridAreaElement;

template <typename T>
class GridArea;

template <typename T>
class OwnerPtrT;

template <typename T>
class ServiceReference;

template <typename T>
class SharedPtr;

template <typename T>
class StackRefResultT;

template <>
class OwnerPtrT<struct EntityRefTraits>
{
    char filler[24];

public:
    inline ~OwnerPtrT()
    {
        void (OwnerPtrT:: * rv)() const;
        *((void**)&rv) = dlsym("??1?$OwnerPtrT@UEntityRefTraits@@@@QEAA@XZ");
        (this->*rv)();
    }

    inline OwnerPtrT(OwnerPtrT&& right) noexcept
    {
        void (OwnerPtrT:: * rv)(OwnerPtrT && right);
        *((void**)&rv) = dlsym("??0OwnerStorageEntity@@IEAA@$$QEAV0@@Z");
        (this->*rv)(std::move(right));
    }

    inline OwnerPtrT& operator=(OwnerPtrT&& right) noexcept
    {
        void (OwnerPtrT:: * rv)(OwnerPtrT && right);
        *((void**)&rv) = dlsym("??4OwnerStorageEntity@@IEAAAEAV0@$$QEAV0@@Z");
        (this->*rv)(std::move(right));
    }
};


template<typename T>
class WeakPtr {
    T** value;
public:
    inline T* get()
    {
        if (value)
            return *value;
        return nullptr;
    }
    inline T const* get() const
    {
        if (value)
            return *value;
        return nullptr;
    }
    inline T& operator*()
    {
        return *get();
    }
    inline T const& operator*() const
    {
        return *get();
    }
    inline operator bool() const
    {
        return get() != nullptr;
    }
};

template <typename T>
class WeakRefT;

template <typename T>
struct SharePtrRefTraits;

template <typename T>
class SubChunkStorage;

template <typename T, typename T2>
class TagRegistry;

template <typename T>
struct IDType;

template <typename T>
class ToFloatFunction;

template <typename T>
class TypedScreenCapabilities
{
};

template <typename T, typename T2, typename T3, typename T4 = class UNK>
class ViewedEntityContextT;

template <typename T>
class FlagComponent;

template <typename T>
class WeightedChoices;

template <typename T>
class buffer_span;

template <typename T>
class buffer_span_mut;

template <typename T>
class optional_ref
{
    T** value;

public:
    inline T* get() const
    {
        if (value && *value)
            return *value;
        return nullptr;
    }
    //inline T* set(T const& val)
    //{
    //    *value = &val;
    //}
    inline T& operator*() const
    {
        return **value;
    }
    inline T* operator->() const
    {
        return *value;
    }
};

template <int a>
class DividedPos2d;

//template <typename T>
//struct GameplayHandlerResult;

template <typename T>
struct GameplayHandlerResult;

template <int T>
class ItemStackRequestActionDataless;

template <typename T>
class OperationGraphResult;

template <typename T1>
class SmallSet;

template <typename T1>
struct TaskStartInfoEx;

template <typename T1>
class WildcardCommandSelector;

//enum
enum class ContainerType : char
{
    INVENTORY              = -1,
    NONE                   = -9,
    CONTAINER              = 0,
    WORKBENCH              = 1,
    FURNACE                = 2,
    ENCHANTMENT            = 3,
    BREWING_STAND          = 4,
    ANVIL                  = 5,
    DISPENSER              = 6,
    DROPPER                = 7,
    HOPPER                 = 8,
    CAULDRON               = 9,
    MINECART_CHEST         = 10,
    MINECART_HOPPER        = 11,
    HORSE                  = 12,
    TRADE                  = 15,//NotGenerated
    MINECART_COMMAND_BLOCK = 16,
    JUKEBOX                = 17,
    COMPOUND_CREATOR       = 20,
    ELEMENT_CONSTRUCTOR    = 21,
    MATERIAL_REDUCER       = 22,
    LAB_TABLE              = 23,
    BLAST_FURNACE          = 27,
    SMOKER                 = 28,
    STONECUTTER            = 29,
    HUD                    = 31,
    SMITHING_TABLE         = 33,
};

enum class UpdateBlockLayer : int
{
    UpdateBlockDefault,
    UpdateBlockLiquid
};

enum class UpdateBlockFlags : int
{
    UpdateBlockNone = 0,
    BlockUpdateNeighbors = 1,
    BlockUpdateNetwork = 2,
    BlockUpdateAll = 3,//default value in BDS
    BlockUpdateNoGraphic = 4,
    BlockUpdatePriority = 8,
    BlockUpdateAllPriority = 11
    //old one not correctly ? 
    //BlockUpdateNeighbours = 1,
    //BlockUpdateNetwork = 2,
    //BlockUpdateNoGraphics = 3,
    //BlockUpdatePriority = 4,
};

enum class TextType : char
{
    RAW = 0,
    CHAT = 1,
    TRANSLATION = 2,
    POPUP = 3,
    JUKEBOX_POPUP = 4,
    TIP = 5,
    SYSTEM = 6,
    WHISPER = 7,
    ANNOUNCEMENT = 8,
    JSON_WHISPER = 9,
    JSON = 10
};

enum class TitleType : int
{
    Clear = 0,
    Reset = 1,
    SetTitle = 2,
    SetSubtitle = 3,
    SetActionBar = 4,
    SetDurations = 5,
    TitleTextObject = 6,
    SubtitleTextObject = 7,
    ActionbarTextObject = 8
};
enum class BossEvent : int
{
    Show = 0,
    RegisterPlayer = 1,
    Hide = 2,
    UnregisterPlayer = 3,
    HealthPercentage = 4,
    Title = 5,
    AppearanceProperties = 6,
    Texture = 7,
    ResendRaidBossEventData = 8,
};

enum class BossEventColour : int
{
    Grey = 0,
    Blue = 1,
    Red = 2,
    Green = 3,
    Yellow = 4,
    Purple = 5,
    White = 6
};

enum class ContainerEnumName : int8_t
{
    AnvilInputContainer = 0,
    AnvilMaterialContainer = 1,
    AnvilResultPreviewContainer = 2,
    SmithingTableInputContainer = 3,
    SmithingTableMaterialContainer = 4,
    SmithingTableResultPreviewContainer = 5,
    ArmorContainer = 6,
    LevelEntityContainer = 7,
    BeaconPaymentContainer = 8,
    BrewingStandInputContainer = 9,
    BrewingStandResultContainer = 10,
    BrewingStandFuelContainer = 11,
    CombinedHotbarAndInventoryContainer = 12,
    CraftingInputContainer = 13,
    CraftingOutputPreviewContainer = 14,
    RecipeConstructionContainer = 15,
    RecipeNatureContainer = 16,
    RecipeItemsContainer = 17,
    RecipeSearchContainer = 18,
    RecipeSearchBarContainer = 19,
    RecipeEquipmentContainer = 20,
    EnchantingInputContainer = 21,
    EnchantingMaterialContainer = 22,
    FurnaceFuelContainer = 23,
    FurnaceIngredientContainer = 24,
    FurnaceResultContainer = 25,
    HorseEquipContainer = 26,
    HotbarContainer = 27,
    InventoryContainer = 28,
    ShulkerBoxContainer = 29,
    TradeIngredient1Container = 30,
    TradeIngredient2Container = 31,
    TradeResultPreviewContainer = 32,
    OffhandContainer = 33,
    CompoundCreatorInput = 34,
    CompoundCreatorOutputPreview = 35,
    ElementConstructorOutputPreview = 36,
    MaterialReducerInput = 37,
    MaterialReducerOutput = 38,
    LabTableInput = 39,
    LoomInputContainer = 40,
    LoomDyeContainer = 41,
    LoomMaterialContainer = 42,
    LoomResultPreviewContainer = 43,
    BlastFurnaceIngredientContainer = 44,
    SmokerIngredientContainer = 45,
    Trade2Ingredient1Container = 46,
    Trade2Ingredient2Container = 47,
    Trade2ResultPreviewContainer = 48,
    GrindstoneInputContainer = 49,
    GrindstoneAdditionalContainer = 50,
    GrindstoneResultPreviewContainer = 51,
    StonecutterInputContainer = 52,
    StonecutterResultPreviewContainer = 53,
    CartographyInputContainer = 54,
    CartographyAdditionalContainer = 55,
    CartographyResultPreviewContainer = 56,
    BarrelContainer = 57,
    CursorContainer = 58,
    CreatedOutputContainer = 59
};

enum class ParticleType
{
    dragondestroyblock = 0x40,
    none = 0x00,
    bubble = 0x01,
    bubblemanual = 0x02,
    crit = 0x03,
    blockforcefield = 0x04,
    smoke = 0x05,
    explode = 0x06,
    evaporation = 0x07,
    flame = 0x08,
    candleflame = 0x09,
    lava = 0x0a,
    largesmoke = 0x0b,
    reddust = 0x0c,
    risingborderdust = 0x0d,
    iconcrack = 0x0e,
    snowballpoof = 0x0f,
    largeexplode = 0x10,
    hugeexplosion = 0x11,
    mobflame = 0x12,
    heart = 0x13,
    terrain = 0x14,
    townaura = 0x15,
    portal = 0x16,
    watersplash = 0x18,
    watersplashmanual = 0x19,
    waterwake = 0x1a,
    dripwater = 0x1b,
    driplava = 0x1c,
    driphoney = 0x1d,
    stalactitedripwater = 0x1e,
    stalactitedriplava = 0x1f,
    fallingdust = 0x20,
    mobspell = 0x21,
    mobspellambient = 0x22,
    mobspellinstantaneous = 0x23,
    ink = 0x24,
    slime = 0x25,
    rainsplash = 0x26,
    villagerangry = 0x27,
    villagerhappy = 0x28,
    enchantingtable = 0x29,
    trackingemitter = 0x2a,
    note = 0x2b,
    witchspell = 0x2c,
    carrotboost = 0x2d,
    mobappearance = 0x2e,
    endrod = 0x2f,
    dragonbreath = 0x30,
    spit = 0x31,
    totem = 0x32,
    food = 0x33,
    fireworksstarter = 0x34,
    fireworks = 0x35,
    fireworksoverlay = 0x36,
    balloongas = 0x37,
    coloredflame = 0x38,
    sparkler = 0x39,
    conduit = 0x3a,
    bubblecolumnup = 0x3b,
    bubblecolumndown = 0x3c,
    sneeze = 0x3d,
    shulkerbullet = 0x3e,
    bleach = 0x3f,
    myceliumdust = 0x41,
    fallingborderdust = 0x42,
    campfiresmoke = 0x43,
    campfiresmoketall = 0x44,
    dragonbreathfire = 0x45,
    dragonbreathtrail = 0x46,
    soul = 0x48,
    obsidiantear = 0x49,
    portalreverse = 0x4a,
    snowflake = 0x4b,
    wax = 0x50,
    electricspark = 0x51,
    shriek = 0x52,
    sculksoul = 0x53
};

enum class transactionType
{
    NormalTransaction = 0x00,
    InventoryMismatch = 0x01,
    ItemUseTransaction = 0x02,
    ItemUseOnEntityTransaction = 0x03,
    ItemReleaseTransaction = 0x04
};

enum class ItemStackRequestActionType: char
{
    Take = 0x00,
    Place = 0x01,
    Swap = 0x02,
    Drop = 0x03,
    Destroy = 0x04,
    Consume = 0x05,
    Create = 0x06,
    PlaceInItemContainer = 0x07,
    TakeFromItemContainer = 0x08,
    ScreenLabTableCombine = 0x09,
    ScreenBeaconPayment = 0x0a,
    ScreenHUDMineBlock = 0x0b,
    CraftRecipe = 0x0c,
    CraftRecipeAuto = 0x0d,
    CraftCreative = 0x0e,
    CraftRecipeOptional = 0x0f,
    CraftRepairAndDisenchant = 0x10,
    CraftLoom = 0x11,
    CraftNonImplemented_DEPRECATEDASKTYLAING = 0x12,
    CraftResults_DEPRECATEDASKTYLAING = 0x13,
};

enum class ActorDamageCause : int
{
    Override = 0x0,
    Contact = 0x1,
    EntityAttack = 0x2,
    Projectile = 0x3,
    Suffocation = 0x4,
    Fall = 0x5,
    Fire = 0x6,
    FireTick = 0x7,
    Lava = 0x8,
    Drowning = 0x9,
    BlockExplosion = 0x0A,
    EntityExplosion = 0x0B,
    Void = 0x0C,
    Suicide = 0x0D,
    Magic = 0x0E,
    Wither = 0x0F,
    Starve = 0x10,
    Anvil = 0x11,
    Thorns = 0x12,
    FallingBlock = 0x13,
    Piston = 0x14,
    FlyIntoWall = 0x15,
    Magma = 0x16,
    Fireworks = 0x17,
    Lightning = 0x18,
    Charging = 0x19,
    Temperature = 0x1A,
    All = 0x1F,
    None = -0x01,
};

enum class ObjectiveSortOrder : char
{
    Ascending = 0,
    Descending = 1
};

enum class PlayerScoreSetFunction : char
{
    Set = 0,
    Add = 1,
    Remove = 2
};

enum class ContainerID : uint8_t
{
    Invalid = 0xff,
    Inventory = 0,
    First = 1,
    Last = 100,
    Offhand = 119,
    Armor = 120,
    SelectionSlots = 122,
    PlayerUIOnly = 124
};

enum class FaceID : char
{
    Unknown = -1,
    Down = 0,
    Up = 1,
    North = 2,
    South = 3,
    West = 4,
    East = 5,
};

enum class BlockActorType {
    Undefined = 0x0,
    Furnace = 0x1,
    Chest = 0x2,
    NetherReactor = 0x3,
    Sign = 0x4,
    MobSpawner = 0x5,
    Skull = 0x6,
    FlowerPot = 0x7,
    BrewingStand = 0x8,
    EnchantTable = 0x9,
    DaylightDetector = 0xa,
    Music = 0xb,
    Comparator = 0xc,
    Dispenser = 0xd,
    Dropper = 0xe,
    Hopper = 0xf,
    Cauldron = 0x10,
    ItemFrame = 0x11,
    PistonArm = 0x12,
    MovingBlock = 0x13,
    ChalkboardBlock = 0x14,
    Beacon = 0x15,
    EndPortal = 0x16,
    EnderChest = 0x17,
    EndGateway = 0x18,
    ShulkerBox = 0x19,
    CommandBlock = 0x1a,
    Bed = 0x1b,
    Banner = 0x1c,
    StructureBlock = 0x20,
    Jukebox = 0x21,
    ChemistryTable = 0x22,
    Conduit = 0x23,
    JigsawBlock = 0x24,
    Lectern = 0x25,
    BlastFurnace = 0x26,
    Smoker = 0x27,
    Bell = 0x28,
    Campfire = 0x29,
    Barrel = 0x2a,
    Beehive = 0x2b,
    Lodestone = 0x2c,
    SculkSensor = 0x2d,
	SporeBlossom = 0x2e,
	GlowItemFrame = 0x2f,
	SculkCatalyst = 0x30,
	SculkShrieker = 0x31
};

enum class MinecraftPacketIds : int
{
    Login = 0x01,
    PlayStatus = 0x02,
    ServerToClientHandshake = 0x03,
    ClientToServerHandshake = 0x04,
    Disconnect = 0x05,
    ResourcePacksInfo = 0x06,
    ResourcePackStack = 0x07,
    ResourcePackClientResponse = 0x08,
    Text = 0x09,
    SetTime = 0x0A,
    StartGame = 0x0B,
    AddPlayer = 0x0C,
    AddActor = 0x0D,
    RemoveActor = 0x0E,
    AddItemActor = 0x0F,
    TakeItemActor = 0x11,
    MoveActorAbsolute = 0x12,
    MovePlayer = 0x13,
    PassengerJump = 0x14,
    UpdateBlock = 0x15,
    AddPainting = 0x16,
    TickSync = 0x17,
    LevelSoundEventV1 = 0x18,
    LevelEvent = 0x19,
    BlockEvent = 0x1A,
    ActorEvent = 0x1B,
    MobEffect = 0x1C,
    UpdateAttributes = 0x1D,
    InventoryTransaction = 0x1E,
    MobEquipment = 0x1F,
    MobArmorEquipment = 0x20,
    Interact = 0x21,
    BlockPickRequest = 0x22,
    ActorPickRequest = 0x23,
    PlayerAction = 0x24,
    HurtArmor = 0x26,
    SetActorData = 0x27,
    SetActorMotion = 0x28,
    SetActorLink = 0x29,
    SetHealth = 0x2A,
    SetSpawnPosition = 0x2B,
    Animate = 0x2C,
    Respawn = 0x2D,
    ContainerOpen = 0x2E,
    ContainerClose = 0x2F,
    PlayerHotbar = 0x30,
    InventoryContent = 0x31,
    InventorySlot = 0x32,
    ContainerSetData = 0x33,
    CraftingData = 0x34,
    CraftingEvent = 0x35,
    GuiDataPickItem = 0x36,
    AdventureSettings = 0x37,
    BlockActorData = 0x38,
    PlayerInput = 0x39,
    LevelChunk = 0x3A,
    SetCommandsEnabled = 0x3B,
    SetDifficulty = 0x3C,
    ChangeDimension = 0x3D,
    SetPlayerGameType = 0x3E,
    PlayerList = 0x3F,
    SimpleEvent = 0x40,
    Event = 0x41,
    SpawnExperienceOrb = 0x42,
    ClientboundMapItemData = 0x43,
    MapInfoRequest = 0x44,
    RequestChunkRadius = 0x45,
    ChunkRadiusUpdated = 0x46,
    ItemFrameDropItem = 0x47,
    GameRulesChanged = 0x48,
    Camera = 0x49,
    BossEvent = 0x4A,
    ShowCredits = 0x4B,
    AvailableCommands = 0x4C,
    CommandRequest = 0x4D,
    CommandBlockUpdate = 0x4E,
    CommandOutput = 0x4F,
    UpdateTrade = 0x50,
    UpdateEquip = 0x51,
    ResourcePackDataInfo = 0x52,
    ResourcePackChunkData = 0x53,
    ResourcePackChunkRequest = 0x54,
    Transfer = 0x55,
    PlaySound = 0x56,
    StopSound = 0x57,
    SetTitle = 0x58,
    AddBehaviorTree = 0x59,
    StructureBlockUpdate = 0x5A,
    ShowStoreOffer = 0x5B,
    PurchaseReceipt = 0x5C,
    PlayerSkin = 0x5D,
    SubClientLogin = 0x5E,
    AutomationClientConnect = 0x5F,
    SetLastHurtBy = 0x60,
    BookEdit = 0x61,
    NpcRequest = 0x62,
    PhotoTransfer = 0x63,
    ModalFormRequest = 0x64,
    ModalFormResponse = 0x65,
    ServerSettingsRequest = 0x66,
    ServerSettingsResponse = 0x67,
    ShowProfile = 0x68,
    SetDefaultGameType = 0x69,
    RemoveObjective = 0x6A,
    SetDisplayObjective = 0x6B,
    SetScore = 0x6C,
    LabTable = 0x6D,
    UpdateBlockSynced = 0x6E,
    MoveActorDelta = 0x6F,
    SetScoreboardIdentity = 0x70,
    SetLocalPlayerAsInitialized = 0x71,
    UpdateSoftEnum = 0x72,
    NetworkStackLatency = 0x73,
    ScriptCustomEvent = 0x75,
    SpawnParticleEffect = 0x76,
    AvailableActorIdentifiers = 0x77,
    LevelSoundEventV2 = 0x78,
    NetworkChunkPublisherUpdate = 0x79,
    BiomeDefinitionList = 0x7A,
    LevelSoundEvent = 0x7B,
    LevelEventGeneric = 0x7C,
    LecternUpdate = 0x7D,
    AddEntity = 0x7F,
    RemoveEntity = 0x80,
    ClientCacheStatus = 0x81,
    OnScreenTextureAnimation = 0x82,
    MapCreateLockedCopy = 0x83,
    StructureTemplateDataRequest = 0x84,
    StructureTemplateDataResponse = 0x85,
    ClientCacheBlobStatus = 0x87,
    ClientCacheMissResponse = 0x88,
    EducationSettings = 0x89,
    Emote = 0x8A,
    MultiplayerSettings = 0x8B,
    SettingsCommand = 0x8C,
    AnvilDamage = 0x8D,
    CompletedUsingItem = 0x8E,
    NetworkSettings = 0x8F,
    PlayerAuthInput = 0x90,
    CreativeContent = 0x91,
    PlayerEnchantOptions = 0x92,
    ItemStackRequest = 0x93,
    ItemStackResponse = 0x94,
    PlayerArmorDamage = 0x95,
    CodeBuilder = 0x96,
    UpdatePlayerGameType = 0x97,
    EmoteList = 0x98,
    PositionTrackingDBServerBroadcast = 0x99,
    PositionTrackingDBClientRequest = 0x9A,
    DebugInfo = 0x9B,
    PacketViolationWarning = 0x9C,
    MotionPredictionHints = 0x9D,
    AnimateEntity = 0x9E,
    CameraShake = 0x9F,
    PlayerFog = 0xA0,
    CorrectPlayerMovePrediction = 0xA1,
    ItemComponent = 0xA2,
    FilterText = 0xA3,
    ClientboundDebugRenderer = 0xA4,
    SyncActorProperty = 0xA5,
    AddVolumeEntity = 0xA6,
    RemoveVolumeEntity = 0xA7,
    SimulationType = 0xA8,
    NpcDialogue = 0xA9,
    EduUriResource = 0xAA,
    CreatePhoto = 0xAB,
    UpdateSubChunkBlocks = 0xAC,
    PhotoInfoRequest = 0xAD,//removed
    SubChunk = 0xAE,
    SubChunkRequest = 0xAF,
    PlayerStartItemCooldown = 0xB0,
    ScriptMessage = 0xB1,
    CodeBuilderSource = 0xB2,
    TickingAreasLoadStatus = 0xB3,
    DimensionData = 0xB4,
    AgentActionEvent = 0xB5,
    ChangeMobProperty = 0xB6
};


enum ItemStackNetResult :unsigned char {
    Success                                          = 0,
    Error                                            = 1,
    InvalidRequestActionType                         = 2,
    ActionRequestNotAllowed                          = 3,
    ScreenHandlerEndRequestFailed                    = 4,
    ItemRequestActionHandlerCommitFailed             = 5,
    InvalidRequestCraftActionType                    = 6,
    InvalidCraftRequest                              = 7,
    InvalidCraftRequestScreen                        = 8,
    InvalidCraftResult                               = 9,
    InvalidCraftResultIndex                          = 10,
    InvalidCraftResultItem                           = 11,
    InvalidItemNetId                                 = 12,
    MissingCreatedOutputContainer                    = 13,
    FailedToSetCreatedItemOutputSlot                 = 14,
    RequestAlreadyInProgress                         = 15,
    FailedToInitSparseContainer                      = 16,
    ResultTransferFailed                             = 17,
    ExpectedItemSlotNotFullyConsumed                 = 18,
    ExpectedAnywhereItemNotFullyConsumed             = 19,
    ItemAlreadyConsumedFromSlot                      = 20,
    ConsumedTooMuchFromSlot                          = 21,
    MismatchSlotExpectedConsumedItem                 = 22,
    MismatchSlotExpectedConsumedItemNetIdVariant     = 23,
    FailedToMatchExpectedSlotConsumedItem            = 24,
    FailedToMatchExpectedAllowedAnywhereConsumedItem = 25,
    ConsumedItemOutOfAllowedSlotRange                = 26,
    ConsumedItemNotAllowed                           = 27,
    PlayerNotInCreativeMode                          = 28,
    InvalidExperimentalRecipeRequest                 = 29,
    FailedToCraftCreative                            = 30,
    FailedToGetLevelRecipe                           = 31,
    FailedToFindRecipeByNetId                        = 32,
    MismatchedCraftingSize                           = 33,
    MissingInputSparseContainer                      = 34,
    MismatchedRecipeForInputGridItems                = 35,
    EmptyCraftResults                                = 36,
    FailedToEnchant                                  = 37,
    MissingInputItem                                 = 38,
    InsufficientPlayerLevelToEnchant                 = 39,
    MissingMaterialItem                              = 40,
    MissingActor                                     = 41,
    UnknownPrimaryEffect                             = 42,
    PrimaryEffectOutOfRange                          = 43,
    PrimaryEffectUnavailable                         = 44,
    SecondaryEffectOutOfRange                        = 45,
    SecondaryEffectUnavailable                       = 46,
    DstContainerEqualToCreatedOutputContainer        = 47,
    DstContainerAndSlotEqualToSrcContainerAndSlot    = 48,
    FailedToValidateSrcSlot                          = 49,
    FailedToValidateDstSlot                          = 50,
    InvalidAdjustedAmount                            = 51,
    InvalidItemSetType                               = 52,
    InvalidTransferAmount                            = 53,
    CannotSwapItem                                   = 54,
    CannotPlaceItem                                  = 55,
    UnhandledItemSetType                             = 56,
    InvalidRemovedAmount                             = 57,
    InvalidRegion                                    = 58,
    CannotDropItem                                   = 59,
    CannotDestroyItem                                = 60,
    InvalidSourceContainer                           = 61,
    ItemNotConsumed                                  = 62,
    InvalidNumCrafts                                 = 63,
    InvalidCraftResultStackSize                      = 64,
    CannotConsumeItem                                = 66,
    ScreenStackError                                 = 67,
};

//class CommandVersion {
//public:
//    int Min = 1, Max = 0x7FFFFFFF;
//};

enum class ActorType : int
{
    Item = 0x40,                     // minecraft:item,                   ·­Òë: ÎïÆ·
    Tnt = 0x41,                      // minecraft:tnt,                    ·­Òë: TNT ·½¿é
    FallingBlock = 0x42,             // minecraft:falling_block,          ·­Òë: ÏÂÂäµÄ·½¿é
    MovingBlock = 0x43,              // minecraft:moving_block,           ·­Òë: ÒÆ¶¯ÖÐµÄ·½¿é
    XpOrb = 0x45,                    // minecraft:xp_orb,                 ·­Òë: ¾­ÑéÇò
    EyeOfEnderSignal = 0x46,         // minecraft:eye_of_ender_signal,    ·­Òë: Ä©Ó°Ö®ÑÛ
    EnderCrystal = 0x47,             // minecraft:ender_crystal,          ·­Òë: Ä©Ó°Ë®¾§
    FireworksRocket = 0x48,          // minecraft:fireworks_rocket,       ·­Òë: Ñæ»ð»ð¼ý
    FishingHook = 0x4D,              // minecraft:fishing_hook,           ·­Òë: Óã¹³
    Chalkboard = 0x4E,               // minecraft:chalkboard,             ·­Òë: entity.chalkboard.name
    Painting = 0x53,                 // minecraft:painting,               ·­Òë: »­
    LeashKnot = 0x58,                // minecraft:leash_knot,             ·­Òë: Ë©Éþ½á
    Boat = 0x5A,                     // minecraft:boat,                   ·­Òë: ´¬
    LightningBolt = 0x5D,            // minecraft:lightning_bolt,         ·­Òë: ÉÁµç
    AreaEffectCloud = 0x5F,          // minecraft:area_effect_cloud,      ·­Òë: ÇøÓòÐ§¹ûÔÆÎí
    Balloon = 0x6B,                  // minecraft:balloon,                ·­Òë: entity.balloon.name
    Shield = 0x75,                   // minecraft:shield,                 ·­Òë: entity.shield.name
    Npc = 0x0133,                    // minecraft:npc,                    ·­Òë: entity.npc.name
    Agent = 0x0138,                  // minecraft:agent,                  ·­Òë: entity.agent.name
    ArmorStand = 0x013D,             // minecraft:armor_stand,            ·­Òë: ¿ø¼×¼Ü
    TripodCamera = 0x013E,           // minecraft:tripod_camera,          ·­Òë: Èý½Å¼ÜÉãÏñ»ú
    Player = 0x013F,                 // minecraft:player,                 ·­Òë: entity.player.name
    Bee = 0x017A,                    // minecraft:bee,                    ·­Òë: ÃÛ·ä
    Piglin = 0x017B,                 // minecraft:piglin,                 ·­Òë: ÖíÁé
    PiglinBrute = 0x017F,            // minecraft:piglin_brute,           ·­Òë: ²Ð±©ÖíÁé
    IronGolem = 0x0314,              // minecraft:iron_golem,             ·­Òë: Ìú¿þÀÜ
    SnowGolem = 0x0315,              // minecraft:snow_golem,             ·­Òë: Ñ©¿þÀÜ
    WanderingTrader = 0x0376,        // minecraft:wandering_trader,       ·­Òë: Á÷ÀËÉÌÈË
    Creeper = 0x0B21,                // minecraft:creeper,                ·­Òë: ÅÀÐÐÕß
    Slime = 0x0B25,                  // minecraft:slime,                  ·­Òë: Ê·À³Ä·
    Enderman = 0x0B26,               // minecraft:enderman,               ·­Òë: Ä©Ó°ÈË
    Ghast = 0x0B29,                  // minecraft:ghast,                  ·­Òë: ¶ñ»ê
    MagmaCube = 0x0B2A,              // minecraft:magma_cube,             ·­Òë: ÑÒ½¬¹Ö
    Blaze = 0x0B2B,                  // minecraft:blaze,                  ·­Òë: ÁÒÑæÈË
    Witch = 0x0B2D,                  // minecraft:witch,                  ·­Òë: Å®Î×
    Guardian = 0x0B31,               // minecraft:guardian,               ·­Òë: ÊØÎÀÕß
    ElderGuardian = 0x0B32,          // minecraft:elder_guardian,         ·­Òë: Ô¶¹ÅÊØÎÀÕß
    EnderDragon = 0x0B35,            // minecraft:ender_dragon,           ·­Òë: Ä©Ó°Áú
    Shulker = 0x0B36,                // minecraft:shulker,                ·­Òë: Ç±Ó°±´
    Vindicator = 0x0B39,             // minecraft:vindicator,             ·­Òë: ÎÀµÀÊ¿
    Ravager = 0x0B3B,                // minecraft:ravager,                ·­Òë: ½ÙÂÓÊÞ
    EvocationIllager = 0x0B68,       // minecraft:evocation_illager,      ·­Òë: »½Ä§Õß
    Vex = 0x0B69,                    // minecraft:vex,                    ·­Òë: ÄÕ¹í
    Pillager = 0x0B72,               // minecraft:pillager,               ·­Òë: ÂÓ¶áÕß
    ElderGuardianGhost = 0x0B78,     // minecraft:elder_guardian_ghost,   ·­Òë: entity.elder_guardian_ghost.name
    Chicken = 0x130A,                // minecraft:chicken,                ·­Òë: ¼¦
    Cow = 0x130B,                    // minecraft:cow,                    ·­Òë: Å£
    Pig = 0x130C,                    // minecraft:pig,                    ·­Òë: Öí
    Sheep = 0x130D,                  // minecraft:sheep,                  ·­Òë: Ñò
    Mooshroom = 0x1310,              // minecraft:mooshroom,              ·­Òë: ßè¹½
    Rabbit = 0x1312,                 // minecraft:rabbit,                 ·­Òë: ÍÃ×Ó
    PolarBear = 0x131C,              // minecraft:polar_bear,             ·­Òë: ±±¼«ÐÜ
    Llama = 0x131D,                  // minecraft:llama,                  ·­Òë: ÑòÍÕ
    Turtle = 0x134A,                 // minecraft:turtle,                 ·­Òë: º£¹ê
    Panda = 0x1371,                  // minecraft:panda,                  ·­Òë: ÐÜÃ¨
    Fox = 0x1379,                    // minecraft:fox,                    ·­Òë: ºüÀê
    Hoglin = 0x137C,                 // minecraft:hoglin,                 ·­Òë: ðàÖíÊÞ
    Strider = 0x137D,                // minecraft:strider,                ·­Òë: ³ã×ãÊÞ
    Goat = 0x1380,                   // minecraft:goat,                   ·­Òë: É½Ñò
    Axolotl = 0x1382,                // minecraft:axolotl,                ·­Òë: ÃÀÎ÷ó¢
    Squid = 0x2311,                  // minecraft:squid,                  ·­Òë: öÏÓã
    Dolphin = 0x231F,                // minecraft:dolphin,                ·­Òë: º£ëà
    Pufferfish = 0x236C,             // minecraft:pufferfish,             ·­Òë: ºÓëà
    Salmon = 0x236D,                 // minecraft:salmon,                 ·­Òë: öÙÓã
    Tropicalfish = 0x236F,           // minecraft:tropicalfish,           ·­Òë: ÈÈ´øÓã
    Cod = 0x2370,                    // minecraft:cod,                    ·­Òë: ÷¨Óã
    GlowSquid = 0x2381,              // minecraft:glow_squid,             ·­Òë: ·¢¹âöÏÓã
    Wolf = 0x530E,                   // minecraft:wolf,                   ·­Òë: ÀÇ
    Ocelot = 0x5316,                 // minecraft:ocelot,                 ·­Òë: ±ªÃ¨
    Parrot = 0x531E,                 // minecraft:parrot,                 ·­Òë: ðÐðÄ
    Cat = 0x534B,                    // minecraft:cat,                    ·­Òë: Ã¨
    Bat = 0x8113,                    // minecraft:bat,                    ·­Òë: òùòð
    ZombiePigman = 0x010B24,         // minecraft:zombie_pigman,          ·­Òë: ½©Ê¬ÖíÁé
    Wither = 0x010B34,               // minecraft:wither,                 ·­Òë: µòÁé
    Phantom = 0x010B3A,              // minecraft:phantom,                ·­Òë: »ÃÒí
    Zoglin = 0x010B7E,               // minecraft:zoglin,                 ·­Òë: ½©Ê¬ðàÖíÊÞ
    Zombie = 0x030B20,               // minecraft:zombie,                 ·­Òë: ½©Ê¬
    ZombieVillager = 0x030B2C,       // minecraft:zombie_villager,        ·­Òë: ½©Ê¬´åÃñ
    Husk = 0x030B2F,                 // minecraft:husk,                   ·­Òë: Ê¬¿Ç
    Drowned = 0x030B6E,              // minecraft:drowned,                ·­Òë: ÄçÊ¬
    ZombieVillagerV2 = 0x030B74,     // minecraft:zombie_villager_v2,     ·­Òë: ¹ÖÈË´åÃñ
    Spider = 0x040B23,               // minecraft:spider,                 ·­Òë: Ö©Öë
    Silverfish = 0x040B27,           // minecraft:silverfish,             ·­Òë: ó¼³æ
    CaveSpider = 0x040B28,           // minecraft:cave_spider,            ·­Òë: ¶´Ñ¨Ö©Öë
    Endermite = 0x040B37,            // minecraft:endermite,              ·­Òë: Ä©Ó°òý
    Minecart = 0x080054,             // minecraft:minecart,               ·­Òë: ¿ó³µ
    HopperMinecart = 0x080060,       // minecraft:hopper_minecart,        ·­Òë: Â©¶·¿ó³µ
    TntMinecart = 0x080061,          // minecraft:tnt_minecart,           ·­Òë: TNT ¿ó³µ
    ChestMinecart = 0x080062,        // minecraft:chest_minecart,         ·­Òë: ÔËÊä¿ó³µ
    CommandBlockMinecart = 0x080064, // minecraft:command_block_minecart, ·­Òë: ÃüÁî·½¿é¿ó³µ
    Skeleton = 0x110B22,             // minecraft:skeleton,               ·­Òë: ÷¼÷Ã
    Stray = 0x110B2E,                // minecraft:stray,                  ·­Òë: Á÷ÀËÕß
    WitherSkeleton = 0x110B30,       // minecraft:wither_skeleton,        ·­Òë: µòÁé÷¼÷Ã
    Horse = 0x205317,                // minecraft:horse,                  ·­Òë: Âí
    Donkey = 0x205318,               // minecraft:donkey,                 ·­Òë: Â¿
    Mule = 0x205319,                 // minecraft:mule,                   ·­Òë: Ââ×Ó
    SkeletonHorse = 0x215B1A,        // minecraft:skeleton_horse,         ·­Òë: ÷¼÷ÃÂí
    ZombieHorse = 0x215B1B,          // minecraft:zombie_horse,           ·­Òë: ½©Ê¬Âí
    XpBottle = 0x400044,             // minecraft:xp_bottle,              ·­Òë: ¸½Ä§Ö®Æ¿
    ShulkerBullet = 0x40004C,        // minecraft:shulker_bullet,         ·­Òë: Ç±Ó°±´×Óµ¯
    DragonFireball = 0x40004F,       // minecraft:dragon_fireball,        ·­Òë: Ä©Ó°Áú»ðÇò
    Snowball = 0x400051,             // minecraft:snowball,               ·­Òë: Ñ©Çò
    Egg = 0x400052,                  // minecraft:egg,                    ·­Òë: ¼¦µ°
    Fireball = 0x400055,             // minecraft:fireball,               ·­Òë: »ðÇò
    SplashPotion = 0x400056,         // minecraft:splash_potion,          ·­Òë: Ò©Ë®
    EnderPearl = 0x400057,           // minecraft:ender_pearl,            ·­Òë: Ä©Ó°ÕäÖé
    WitherSkull = 0x400059,          // minecraft:wither_skull,           ·­Òë: µòÁéÍ·Â­
    WitherSkullDangerous = 0x40005B, // minecraft:wither_skull_dangerous, ·­Òë: µòÁéÍ·Â­
    SmallFireball = 0x40005E,        // minecraft:small_fireball,         ·­Òë: Ð¡»ðÇò
    LingeringPotion = 0x400065,      // minecraft:lingering_potion,       ·­Òë: ÖÍÁôÒ©Ë®
    LlamaSpit = 0x400066,            // minecraft:llama_spit,             ·­Òë: ÑòÍÕ¿ÚË®
    EvocationFang = 0x400067,        // minecraft:evocation_fang,         ·­Òë: »½Ä§Õß¼âÑÀ
    IceBomb = 0x40006A,              // minecraft:ice_bomb,               ·­Òë: entity.ice_bomb.name
    ThrownTrident = 0xC00049,        // minecraft:thrown_trident,         ·­Òë: Èý²æêª
    Arrow = 0xC00050,                // minecraft:arrow,                  ·­Òë: ¼ý
    Villager = 0x0100030F,           // minecraft:villager,               ·­Òë: ´åÃñ
    VillagerV2 = 0x01000373,         // minecraft:villager_v2,            ·­Òë: ´åÃñ
};


enum class InventoryTransactionError
{
    Unknown = 0,
    NoError = 1,
    BalanceMismatch = 2,
    SourceItemMismatch = 3,
    InventoryMismatch = 4,
    SizeMismatch = 5,
    AuthorityMismatch = 6,
    StateMismatch = 7,
    ApiDenied = 8
};

enum class InventorySourceType
{
    Invalid = -1,
    Container = 0,
    Global = 1,
    World = 2,
    Creative = 3,
    UntrackedInteractionUI = 100,
    NONIMPLEMENTEDTODO = 99999
};

template <typename T>
struct InvertableFilter
{
    T value;
    bool inverted;
};

template <typename T>
class CommandSelectorResults
{
public:
    std::shared_ptr<std::vector<T*>> data;

    auto begin()
    {
        return data->begin();
    }

    auto end()
    {
        return data->end();
    }

    auto count() const
    {
        return data->size();
    }

    auto empty() const
    {
        return data->empty();
    }
};
