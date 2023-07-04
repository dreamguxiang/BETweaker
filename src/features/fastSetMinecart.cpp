#include <global.h>

namespace FastSetMinecart {
    std::unordered_set<string> minecartItemTypes{
        "minecraft:chest",
        "minecraft:hopper",
        "minecraft:tnt"
    };

    std::unordered_map<string, ActorType> itemTypeToActorType{
        {"minecraft:chest", ActorType::MinecartChest},
        {"minecraft:hopper", ActorType::MinecartHopper},
        {"minecraft:tnt", ActorType::MinecartTNT}
    };

    ActorType getActorTypeFromItem(const string& itemType) {
        auto it = itemTypeToActorType.find(itemType);
        if (it != itemTypeToActorType.end()) {
            return it->second;
        }
        return ActorType::Minecart;
    }

    void setMinecartForPlayer(Player* player, Actor* actor) {
        auto itemInHand = player->getHandSlot();
        if (minecartItemTypes.count(itemInHand->getTypeName())) {
            itemInHand->remove(1);
            player->sendInventory(1);
            auto& actorFactory = Global<Level>->getActorFactory();
            Global<Level>->addEntity(*player->getBlockSource(), actorFactory.createTransformedActor(ActorDefinitionIdentifier(getActorTypeFromItem(itemInHand->getTypeName())), actor));
        }
    }
}

LL_AUTO_TYPED_INSTANCE_HOOK(
    FastSetMinecartHook,
    Player,
    HookPriority::Normal,
    "?interact@Player@@QEAA_NAEAVActor@@AEBVVec3@@@Z",
    __int64,
    Actor* interactedEntity, Vec3* playerPosition)
{
    if (settings::FastSetMinecart && this->isSneaking() && interactedEntity->getTypeName() == "minecraft:minecart") {
        try {
            FastSetMinecart::setMinecartForPlayer(this, interactedEntity);
        }
        catch (...) {
            return origin(interactedEntity, playerPosition);
        }
    }
    return origin(interactedEntity, playerPosition);
}