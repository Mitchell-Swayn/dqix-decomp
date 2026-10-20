#include <globaldefs.h>
extern "C" void GameState_ResetRuntimeDefaults(void);
extern "C" void AllocatorUnion_FreeStoredPointer(int);

// Original: arm9/main @ 0x02012224; symbol: func_02012224; size: 0x20.
extern "C" int GameState_ResetDefaultsAndReleaseZoneRecordStorage(int object) {
    GameState_ResetRuntimeDefaults();
    AllocatorUnion_FreeStoredPointer(object + 0x468);
    return object;
}
