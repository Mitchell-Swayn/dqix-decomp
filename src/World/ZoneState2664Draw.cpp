#include "World/Zone3D.h"
#include "GameState/GameState.h"

extern "C" Zone3D* Zone3D_GetMainInstance();

// Original: arm9/main @ 0x0208F820; symbol: _ZN13ZoneState266420DrawAtGrottoEntranceEv; size: 0x5C.
void ZoneState2664::DrawAtGrottoEntrance()
{
    if (!unknown_b4 || !unknown_b6) return;
    if (!object.IsVisible()) return;
    GrottoStruct* grotto = GameState::GetInstance()->GetGrottoStruct();
    unsigned int entrance;
    unsigned short zone = Zone3D_GetMainInstance()->currentZoneID_;
    entrance = grotto->entranceZoneId;
    if (zone != entrance) return;
    object.Draw(true);
}


