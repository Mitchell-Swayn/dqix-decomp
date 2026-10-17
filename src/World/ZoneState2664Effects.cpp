#include "World/Zone3D.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" {
    Zone3D* ReadGlobalValueAt020FB3F0();
    int ReadIndirectByteOrMinusOne(void*);
}

// Original: arm9/main @ 0x0208F4E4; symbol: _ZN13ZoneState266421UpdateEntranceEffectsEv; size: 0xA4.
void ZoneState2664::UpdateEntranceEffects()
{
    GameState* game = GameState::GetInstance();
    Zone3D* zone;
    void* state = GameResources_GetInstance()->unknown_ptr_array_36fc[0];
    zone = ReadGlobalValueAt020FB3F0();
    if (unknown_b5) UpdateEntranceObject();
    if (ReadIndirectByteOrMinusOne(state) == 10) return;
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

