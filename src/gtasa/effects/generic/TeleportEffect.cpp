#include "TeleportEffect.h"

TeleportEffect::TeleportEffect(CVector destination)
	: EffectBase("effect_teleport")
{
	this->destination = destination;
}

bool TeleportEffect::CanActivate() {
	return Teleportation::CanTeleport();
}

void TeleportEffect::HandleTick() {
	EffectBase::HandleTick();

	if (this->hasTeleported) {
		Disable();
		return;
	}

	if (!CanActivate()) return;

	Teleportation::Teleport(this->destination);
	this->hasTeleported = true;
}
