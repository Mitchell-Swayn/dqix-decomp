#include "World/Zone3D.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" {
    Zone3D* func_02012fe4();
    int func_02046b24(void*);
}

void ZoneState2664::UpdateEntranceEffects()
{
    GameState* game = GameState::GetInstance();
    Zone3D* zone;
    void* state = func_ov017_0218b5b0()->unknown_ptr_array_36fc[0];
    zone = func_02012fe4();
    if (unknown_b5) UpdateEntranceObject();
    if (func_02046b24(state) == 10) return;
    GrottoStruct* grotto = game->GetGrottoStruct();
    unsigned short zoneID = zone->currentZoneID_;
    int discovery = (unsigned char)grotto->activeMapData.GetDiscoveryState();
    if (zoneID == game->GetGrottoStruct()->entranceZoneId) object.AdvanceEffects();
    if (grotto->unknown_0[0])
    {
        if (discovery == 2) return;
        if (discovery == 3) return;
    }
    object.MakeHidden();
}

