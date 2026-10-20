#include "World/Zone3D.h"
#include "GameState/GameState.h"

extern "C" {
    Zone3D* Zone3D_GetMainInstance();
    void Network_GetConnectionManager(void*);
    extern const Vector3i gGrottoEntranceUpdateScale;
    extern const Vector3i gGrottoEntranceShowScale;
}

// Original: arm9/main @ 0x0208F68C; symbol: _ZN13ZoneState266420UpdateEntranceObjectEv; size: 0xBC.
void ZoneState2664::UpdateEntranceObject()
{
    if (unknown_b4)
    {
        GameState* game = GameState::GetInstance();
        unsigned short zone = Zone3D_GetMainInstance()->currentZoneID_;
        GrottoStruct* grotto = game->GetGrottoStruct();
        Vector3i scale = gGrottoEntranceUpdateScale;
        Vector3i position = grotto->entrancePosition;
        if (grotto->entranceZoneId && grotto->unknown_0[0])
        {
            if (grotto->entranceZoneId == zone)
            {
                object.position_ = position;
                object.SetScale(&scale);
                object.SetBCFGAnimationByIndex(0, 0);
                object.MakeVisible();
                unknown_b6 = 1;
            }
            unknown_b5 = 0;
        }
    }
}

// Original: arm9/main @ 0x0208F748; symbol: _ZN13ZoneState266418ShowEntranceObjectEv; size: 0xA4.
bool ZoneState2664::ShowEntranceObject()
{
    if (Zone3D_GetMainInstance()->pUnknownStruct_8_->unknown_c_low_) return false;
    GameState* game = GameState::GetInstance();
    game->GetProtagonist();
    Network_GetConnectionManager(GameResources_GetInstance());
    GrottoStruct* grotto = game->GetGrottoStruct();
    Vector3i position;
    position = grotto->entrancePosition;
    Vector3i scale = gGrottoEntranceShowScale;
    object.position_ = position;
    object.SetScale(&scale);
    object.SetBCFGAnimationByIndex(0, 0);
    object.MakeVisible();
    unknown_b6 = 1;
    return true;
}

