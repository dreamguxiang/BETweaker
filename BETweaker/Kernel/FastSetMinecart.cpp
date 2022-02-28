#include "../Global.h"
#include <MC/ActorFactory.hpp>
#include <MC/ActorDefinitionIdentifier.hpp>
#include <MC/Minecart.hpp>
#include <MC/Spawner.hpp>
#include <MC/Types.hpp>

namespace Module {
    std::unordered_set<string> minecartItem{
        "minecraft:chest",
        "minecraft:hopper",
        "minecraft:tnt"
    };

    ActorType getMinecartActorType(string a1) {
        switch (H(a1))
        {
        case(H("minecraft:chest")):
            return ActorType::ChestMinecart;
        case(H("minecraft:hopper")):
            return ActorType::HopperMinecart;
        case(H("minecraft:tnt")):
            return ActorType::TntMinecart;
        default:
            break;
        }
    }

    bool FastSetMinecart(Player* pl, Actor* ac) {
        auto item = pl->getHandSlot();
        if (minecartItem.count(item->getTypeName())) {
            item->remove(1);
            pl->sendInventory(1);
            auto& af = Global<Level>->getActorFactory();
            Global<Level>->addEntity(*pl->getBlockSource(), af.createTransformedActor(ActorDefinitionIdentifier(getMinecartActorType(item->getTypeName())), ac));
        }
    }
}