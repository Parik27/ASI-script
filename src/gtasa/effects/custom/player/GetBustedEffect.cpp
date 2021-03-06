#include "GetBustedEffect.h"

GetBustedEffect::GetBustedEffect()
	: EffectPlaceholder("effect_get_busted")
{
	if (Config::GetOrDefault("CrowdControl.Enabled", false)) {
		AddType("health");
	}
}

void GetBustedEffect::Enable() {
	EffectPlaceholder::Enable();

	CPlayerPed* player = FindPlayerPed();
	if (player) {
		player->SetPedState(ePedState::PEDSTATE_ARRESTED);

		CCutsceneMgr::SkipCutscene();
	}
}
