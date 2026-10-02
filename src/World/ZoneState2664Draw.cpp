#include "World/Zone3D.h"
#include "GameState/GameState.h"

extern "C" Zone3D* func_02012fe4();

void ZoneState2664::DrawAtGrottoEntrance()
{
    if (!unknown_b4 || !unknown_b6) return;
    if (!object.IsVisible()) return;
    GrottoStruct* grotto = GameState::GetInstance()->GetGrottoStruct();
    unsigned int entrance;
    unsigned short zone = func_02012fe4()->currentZoneID_;
    entrance = grotto->entranceZoneId;
    if (zone != entrance) return;
    object.Draw(true);
}


