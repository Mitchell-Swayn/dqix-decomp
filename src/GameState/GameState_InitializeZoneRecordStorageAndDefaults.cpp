#include <globaldefs.h>
#pragma optimization_level 4
extern "C" void ZoneTable_Reset(void*);
extern "C" void GameState_ResetRuntimeDefaults(void*);
// Original: arm9/main @ 0x02012200; symbol: func_02012200; size: 0x24.
extern "C" int GameState_InitializeZoneRecordStorageAndDefaults(int object) {
    ZoneTable_Reset((char*)object + 0x468);
    GameState_ResetRuntimeDefaults((void*)object);
    return object;
}
