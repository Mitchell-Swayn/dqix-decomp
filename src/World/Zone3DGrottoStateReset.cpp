#include "World/Zone3D.h"
#include "World/ZonePredicates.h"
#include "GameState/GameState.h"

// Original data: arm9/main @ 0x20fb3f0; symbol: data_020fb3f0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 10276 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Zone3D Zone3DGetMainInstance_UnknownRoleZeroInitializedStorage;

// Original: arm9/main @ 0x0201BFD4; symbol: _ZN6Zone3D29ResetGrottoStateOutsideGrottoEv; size: 0x40.
void Zone3D::ResetGrottoStateOutsideGrotto()
{
    GrottoStruct* state = GameState::GetInstance()->GetGrottoStruct();
    if (IsGrottoZone(Zone3DGetMainInstance_UnknownRoleZeroInitializedStorage.currentZoneID_)) return;
    // The paired bytes are not yet identified beyond this reset relationship.
    if (state->unknown_0[4])
    {
        state->unknown_0[3] = 0;
        state->unknown_0[4] = 0;
    }
}
