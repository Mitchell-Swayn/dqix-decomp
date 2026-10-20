#include "GameState/GameState.h"

// The existing class layout is shared with the getter and reconstructed methods.
typedef char GameStateGlobalStorageSizeCheck[sizeof(GameState) == 0x7ff4 ? 1 : -1];

// Original BSS: arm9/main @ 0x020F33D8; symbol: data_020f33d8; size: 0x7FF4.
// The global GameState returned by GameState::GetInstance. Its members start
// zero-filled; the original __sinit_020e5920 at 0x020E5920 performs initialization
// through GameState_InitializeZoneRecordStorageAndDefaults at 0x02012200 and
// registers GameState_ResetDefaultsAndReleaseZoneRecordStorage at 0x02012224.
// That initializer, destructor registration and record at 0x020F33CC remain
// separately owned. This definition provides typed storage without adding a
// constructor, destructor, static initializer or another registration record.
// Original interior labels at 0x020F4600, 0x020F4618 and 0x020F83D8 remain
// linker aliases; they do not define independent objects inside GameState.
GameState GameStateGetInstance_UnknownRoleZeroInitializedStorage;
