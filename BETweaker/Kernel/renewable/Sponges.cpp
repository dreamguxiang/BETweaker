#include "../../Global.h"
#include <MC/ActorFactory.hpp>
#include <MC/ActorDefinitionIdentifier.hpp>

THook2("renewableSponges", void, "?onLightningHit@Actor@@UEAAXXZ",
    Actor* self)
{
	if (Settings::RenewableSponges) {
		if (self->getEntityTypeId() == ActorType::Guardian) {
			auto& af = Global<Level>->getActorFactory();
			Global<Level>->addEntity(*self->getBlockSource(), af.createTransformedActor(ActorDefinitionIdentifier(ActorType::ElderGuardian), self));
			return;
		}
	}
    original(self);
}
