#include "World/Zone3D.h"
#include "World/ZonePredicates.h"
#include "GameState/GameState.h"

extern "C" Zone3D data_020fb3f0;

void Zone3D::ResetGrottoStateOutsideGrotto()
{
    GrottoStruct* state = GameState::GetInstance()->GetGrottoStruct();
    if (IsGrottoZone(data_020fb3f0.currentZoneID_)) return;
    // The paired bytes are not yet identified beyond this reset relationship.
    if (state->unknown_0[4])
    {
        state->unknown_0[3] = 0;
        state->unknown_0[4] = 0;
    }
}
