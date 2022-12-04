/**
 * @file mc/Types.hpp
 *
 * @brief This file contains the definitions of types.
 *
 */

#pragma once

// enum
#include "inc/enums.inc"
#include "../HookAPI.h"
#include "../utils/RNG.h"
class Vec2;
class Vec3;
class BlockPos;
class AABB;
class BoundingBox;
class ChunkPos;
class ChunkBlockPos;

typedef std::string xuid_t;
typedef unsigned long long QWORD;

namespace mce {

LL_CONSTEXPR int static hexToNum(char s) {
    if ('A' <= s && s <= 'F') {
        return 10 + (s - 'A');
    }
    if ('a' <= s && s <= 'f') {
        return 10 + (s - 'a');
    }
    if ('0' <= s && s <= '9') {
        return (s - '0');
    }
    return 0;
}

LL_CONSTEXPR double static hexToNum(std::string_view s) {
    if (s.length() == 2) {
        return (16 * hexToNum(s[0]) + hexToNum(s[1])) / 255.0;
    }
    return 0;
}

class UUID {
    uint64_t a, b;

public:
    UUID()
    : a(RNG::rand<uint64_t>()), b(RNG::rand<uint64_t>()) {
    }
    UUID(uint64_t a, uint64_t b)
    : a(a), b(b) {
    }
    MCAPI std::string asString() const;
    MCAPI static UUID fromString(std::string const&);
    MCAPI bool isEmpty() const;
    MCAPI static UUID seedFromString(std::string const&);
    MCAPI static class mce::UUID EMPTY;

    inline operator bool() const {
        return !isEmpty();
    }
};

enum class ColorPalette {
    BLACK,
    INDIGO,
    LAVENDER,
    TEAL,
    COCOA,
    DARK,
    OATMEAL,
    WHITE,
    RED,
    APRICOT,
    YELLOW,
    GREEN,
    VATBLUE,
    SLATE,
    PINK,
    FAWN,
};

class Color {
public:
    float r;
    float g;
    float b;
    float a;
    Color()
    : r(0.0f), g(0.0f), b(0.0f), a(0.0f){};
    Color(float r, float g, float b, float a = 1)
    : r(r), g(g), b(b), a(a){};
    Color(double r, double g, double b, double a = 1)
    : r((float)r), g((float)g), b((float)b), a((float)a){};
    Color(int ir, int ig, int ib, int ia = 255)
    : r(ir / 255.0f), g(ig / 255.0f), b(ib / 255.0f), a(ia / 255.0f){};

    LL_CONSTEXPR Color(std::string_view hex) {
        r = 0, g = 0, b = 0, a = 1;
        if (hex[0] == '#') {
            hex = hex.substr(1);
        }
        if (hex.length() == 3) {
            r = (float)((hexToNum(hex[0]) * 17) / 255.0);
            g = (float)((hexToNum(hex[1]) * 17) / 255.0);
            b = (float)((hexToNum(hex[2]) * 17) / 255.0);
            return;
        }
        if (hex.length() == 4) {
            a = (float)((hexToNum(hex[0]) * 17) / 255.0);
            r = (float)((hexToNum(hex[1]) * 17) / 255.0);
            g = (float)((hexToNum(hex[2]) * 17) / 255.0);
            b = (float)((hexToNum(hex[3]) * 17) / 255.0);
            return;
        }
        if (hex.length() == 6) {
            r = (float)hexToNum(hex.substr(0, 2));
            g = (float)hexToNum(hex.substr(2, 2));
            b = (float)hexToNum(hex.substr(4, 2));
            return;
        }
        if (hex.length() == 8) {
            a = (float)hexToNum(hex.substr(0, 2));
            r = (float)hexToNum(hex.substr(2, 2));
            g = (float)hexToNum(hex.substr(4, 2));
            b = (float)hexToNum(hex.substr(6, 2));
            return;
        }
        return;
    };

    inline operator bool() const {
        return !(*this == NIL);
    }

    LIAPI double distanceTo(mce::Color const& dst) const;
    LIAPI std::string toConsoleCode(bool foreground = true) const;
    LIAPI std::string toNearestColorCode() const;
    LIAPI char toNearestParticleColorCode() const;
    LIAPI ColorPalette toNearestParticleColorType() const;
    LIAPI static class mce::Color fromConsoleCode(std::string const&);
    LIAPI static class mce::Color fromColorCode(std::string const&);
    LIAPI class mce::Color sRGBToLinear() const;
    LIAPI class mce::Color LinearTosRGB() const;
    LIAPI class mce::Color LinearToXYZ() const;
    LIAPI class mce::Color XYZToLinear() const;
    LIAPI class mce::Color XYZToLab() const;
    LIAPI class mce::Color LabToXYZ() const;
    LIAPI double deltaE76(mce::Color const& dst) const; // 2.3 for JND
    LIAPI double deltaE94(mce::Color const& dst) const; // 1.0 for JND
    LIAPI double deltaE00(mce::Color const& dst) const; // 1.0 for JND

    MCAPI static mce::Color const NIL;
    MCAPI static class mce::Color fromHexString(std::string const&);
    MCAPI bool operator==(class mce::Color const&) const;
    MCAPI int toABGR(void) const;
    MCAPI int toARGB(void) const;
    MCAPI std::string toHexString(void) const;

    inline bool operator!=(const Color& c) const {
        return !(c == *this);
    }

    inline Color operator*(float c) const {
        return {r * c, g * c, b * c, a * c};
    }

    inline Color operator/(float c) const {
        return {r / c, g / c, b / c, a / c};
    }

    inline Color operator+(float c) const {
        return {r + c, g + c, b + c, a + c};
    }

    inline Color operator-(float c) const {
        return {r - c, g - c, b - c, a - c};
    }

    constexpr Color& operator+=(float c) {
        r += c;
        g += c;
        b += c;
        a += c;
        return *this;
    }

    constexpr Color& operator-=(float c) {
        r -= c;
        g -= c;
        b -= c;
        a -= c;
        return *this;
    }

    constexpr Color& operator*=(float c) {
        r *= c;
        g *= c;
        b *= c;
        a *= c;
        return *this;
    }

    constexpr Color& operator/=(float c) {
        r /= c;
        g /= c;
        b /= c;
        a /= c;
        return *this;
    }

    constexpr Color& operator+=(Color const& c) {
        r += c.r;
        g += c.g;
        b += c.b;
        a += c.a;
        return *this;
    }

    constexpr Color& operator-=(Color const& c) {
        r -= c.r;
        g -= c.g;
        b -= c.b;
        a -= c.a;
        return *this;
    }

    constexpr Color& operator*=(Color const& c) {
        r *= c.r;
        g *= c.g;
        b *= c.b;
        a *= c.a;
        return *this;
    }

    constexpr Color& operator/=(Color const& c) {
        r /= c.r;
        g /= c.g;
        b /= c.b;
        a /= c.a;
        return *this;
    }

    inline Color operator+(Color const& c) const {
        return {r + c.r, g + c.g, b + c.b, a + c.a};
    }

    inline Color operator*(Color const& c) const {
        return {r * c.r, g * c.g, b * c.b, a * c.a};
    }

    inline Color operator/(Color const& c) const {
        return {r / c.r, g / c.g, b / c.b, a / c.a};
    }

    inline Color operator-(Color const& c) const {
        return {r - c.r, g - c.g, b - c.b, a - c.a};
    }

    inline static Color max(const Color& k, const Color& l) {
        return {std::max(k.r, l.r), std::max(k.g, l.g), std::max(k.b, l.b), std::max(k.a, l.a)};
    }

    inline static Color min(const Color& k, const Color& l) {
        return {std::min(k.r, l.r), std::min(k.g, l.g), std::min(k.b, l.b), std::min(k.a, l.a)};
    }

    inline static Color lerp(const Color& k, const Color& l, float m) {
        return k * (1.0f - m) + l * m;
    }

    inline static Color mix(const Color& k, const Color& l, float m) {
        return lerp(k, l, m);
    }
};

static std::unordered_map<ColorPalette, std::pair<char, Color>> const particleColors = {
    // clang-format off
        {mce::ColorPalette::BLACK,    {'B', Color("#000000")}},
        {mce::ColorPalette::INDIGO,   {'I', Color("#144A74")}},
        {mce::ColorPalette::LAVENDER, {'L', Color("#8E65F3")}},
        {mce::ColorPalette::TEAL,     {'T', Color("#07946E")}},
        {mce::ColorPalette::COCOA,    {'C', Color("#AB5236")}},
        {mce::ColorPalette::DARK,     {'D', Color("#56575F")}},
        {mce::ColorPalette::OATMEAL,  {'O', Color("#A2A3A7")}},
        {mce::ColorPalette::WHITE,    {'W', Color("#FFFFFF")}},
        {mce::ColorPalette::RED,      {'R', Color("#FF3040")}},
        {mce::ColorPalette::APRICOT,  {'A', Color("#FF7300")}},
        {mce::ColorPalette::YELLOW,   {'Y', Color("#FFEC27")}},
        {mce::ColorPalette::GREEN,    {'G', Color("#10E436")}},
        {mce::ColorPalette::VATBLUE,  {'V', Color("#29ADFF")}},
        {mce::ColorPalette::SLATE,    {'S', Color("#83769C")}},
        {mce::ColorPalette::PINK,     {'P', Color("#FF77A8")}},
        {mce::ColorPalette::FAWN,     {'E', Color("#FFCCAA")}},
    // clang-format on
};

inline static const char getParticleColorType(ColorPalette const& p) {
    return particleColors.at(p).first;
}

}; // namespace mce

namespace std {

template <>
struct hash<mce::Color> {
    std::size_t operator()(mce::Color const& c) const noexcept {
        return (std::hash<float>()(c.r) ^ std::hash<float>()(c.g) ^ std::hash<float>()(c.b) ^ std::hash<float>()(c.a));
    }
};

} // namespace std

template <typename A, typename T>
class AutomaticID {
    T id;

public:
    AutomaticID() {
        id = 0;
    }

    AutomaticID(T x) {
        id = x;
    }

    inline operator T() const {
        return id;
    }
};

#include "ActorUniqueID.hpp"

// static_assert(!std::is_pod_v<ActorUniqueID>);
class NetherNet {
public:
    struct NetworkID;
};

class ActorRuntimeID {
public:
    unsigned long long id;

    inline unsigned long long get() const {
        return id;
    }

    inline operator unsigned long long() const {
        return id;
    }
};
// static_assert(std::is_pod_v<ActorRuntimeID>);

#include "RelativeFloat.hpp"

// namespace Core {
//
// class PathPart {
// public:
//     std::string data;
// };
//
// class Path : public PathPart {
// public:
// };
//
// template <typename T>
// class PathBuffer {
//     T value;
//     operator T&() noexcept {
//         return value;
//     }
//     operator T const &() const noexcept {
//         return value;
//     }
// };
//
// }; // namespace Core
template <typename T>
class OwnerPtrT;

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

namespace gametest {
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

namespace DBHelpers {
enum class Category;
}; // namespace DBHelpers

class AgentCommands {
public:
    class Command;
};

#include "../mc/Automation.hpp"

class ClientBlobCache {
public:
    struct Server {
        class TransferBuilder;

        class ActiveTransfersManager;
    };
};

template <typename T1, typename T2, typename T3>
class OwnerPtrFactory {};

class ClientBlockPipeline {
public:
    template <typename T>
    class VolumeOf;

    struct BlockSchematic;
};

template <typename T>
class WeakStorageSharePtr {
public:
    std::weak_ptr<T> mHandle;
};

template <typename T>
class WeakRefT : public WeakStorageSharePtr<T> {};

struct ISurfaceBuilder {
    struct BuildParameters;
};

struct FeatureLoading {
    template <typename T>
    struct ConcreteFeatureHolder;
    struct FeatureRootParseContext;
    template <typename T>
    struct ConcreteFeatureHolder;
};

template <typename T1, typename T2>
class OperationNode;

struct OperationNodeDetails {
    template <typename T1, typename T2>
    class WorkingData;
};

struct PositionTrackingDB {
    class TrackingRecord;
    class PositionTrackingDBClient;
    class PositionTrackingDBServer;
};

struct BlockGeometry {
    struct Model;

    class TessellatedModel;
};

struct CanyonFeatureUtils {
    struct CanyonConfiguration;
};

class IInPackagePacks {
public:
    struct MetaData;
};

struct GameEventConfig {
    enum class GameEvents;
};

#include "IMinecraftEventing.hpp"

struct OperationNodeValues {
    enum class Terrain;
};
class Editor {
public:
    class IEditorManager;
    class IEditorPlayer;
};

struct SubChunkStorageUnit {
    enum class PruneType;
};

// Templates
template <typename T, typename T2, int unk>
class TypedServerNetId {
public:
    T2 netId;
    inline operator T2() {
        return netId;
    }
};

template <typename T, typename T2, int unk>
class TypedClientNetId {
public:
    T2 netId;

    virtual void clientInit(TypedClientNetId<T, T2, unk>);
    virtual void clientInit();
};

template <typename T, typename T2, int unk>
class TypedRuntimeId {
public:
    T2 netId;
};

template <typename T, typename T2>
class AutomaticID;

template <typename T, typename T2>
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

// enum class ItemStackRequestActionType : char;
// template <typename T, ItemStackRequestActionType actionType>
// class ItemStackRequestActionCraft;

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

template <typename T>
class WeakPtr {
    T** value;

public:
    inline T* get() {
        if (value)
            return *value;
        return nullptr;
    }
    inline T const* get() const {
        if (value)
            return *value;
        return nullptr;
    }
    inline T& operator*() {
        return *get();
    }
    inline T const& operator*() const {
        return *get();
    }
    inline operator bool() const {
        return get() != nullptr;
    }
};

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
class TypedScreenCapabilities {};

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
class optional_ref {
    T* value;

public:
    inline T* get() const {
        if (*this)
            return value;
        return nullptr;
    }
    // inline T* set(T const& val)
    //{
    //     *value = &val;
    // }
    inline T& operator*() const {
        return *value;
    }
    inline T* operator->() const {
        return value;
    }
    inline operator bool() const {
        return value != nullptr;
    }
};

namespace cg {
class ImageBuffer;
};

template <int a>
class DividedPos2d;

// template <typename T>
// struct GameplayHandlerResult;

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

template <typename T>
struct InvertableFilter {
    T value;
    bool inverted;
};

template <typename T>
class CommandSelectorResults {
public:
    std::shared_ptr<std::vector<T*>> data;

    auto begin() {
        return data->begin();
    }

    auto end() {
        return data->end();
    }

    auto count() const {
        return data->size();
    }

    auto empty() const {
        return data->empty();
    }
};

/*

enum class BlockActorType : int
{
    Furnace = 0x01,
    Chest = 0x02,
    NetherReactor = 0x03,
    Sign = 0x04,
    MobSpawner = 0x05,
    Skull = 0x06,
    FlowerPot = 0x07,
    BrewingStand = 0x08,
    EnchantTable = 0x09,
    DaylightDetector = 0x0A,
    Music = 0x0B,
    Comparator = 0x0C,
    Dispenser = 0x0D,
    Dropper = 0x0E,
    Hopper = 0x0F,
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
    CommandBlock = 0x1A,
    Bed = 0x1B,
    Banner = 0x1C,
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
    Barrel = 0x2A,
    Beehive = 0x2B,
    Lodestone = 0x2C,
    SculkSensor = 0x2D,
    SporeBlossom = 0x2E,
    GlowItemFrame = 0x2F,
    SculkCatalyst = 0x30,
    SculkShrieker = 0x31,
};

enum class ActorType;

*/


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