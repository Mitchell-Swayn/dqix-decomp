#include <globaldefs.h>
ARM
extern "C" void WirelessHost_SetSystemState(int value);
extern "C" int WM_EndKeySharing(void* p);
extern "C" void WirelessHost_StoreErrorUnlessTerminal(unsigned value);
// Original data: arm9/ov031 @ 0x2290d18; symbol: data_ov031_02290d18.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02239A24; symbol: func_ov031_02239a24; size: 0x50.
extern "C" int GameState_RefreshSharedObjectOnModeSix(void) {
    void* object = *(void**)(WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage + 4);
    if (*(unsigned*)((char*)object + 0x40) != 6)
        return 0;
    WirelessHost_SetSystemState(3);
    int result = WM_EndKeySharing((char*)*(void**)(WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage + 4) + 0x1e00);
    if (result == 2)
        return 1;
    WirelessHost_StoreErrorUnlessTerminal(result);
    return 0;
}
