#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d18; symbol: data_ov031_02290d18.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[2];
extern "C" void DisableInterruptsAndHaltForever(void);
extern "C" void WirelessHost_SetSystemState(int);
extern "C" int WM_End(unsigned);
extern "C" void System_SetState10Or0FromHalfword2(void);
// Original: arm9/ov031 @ 0x0223A47C; symbol: func_ov031_0223a47c; size: 0x50.
extern "C" int Overlay_RunOperationAndUpdateState(void) {
    if (*(unsigned int *)((char *)WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[1] + 0x40) != 1)
        DisableInterruptsAndHaltForever();
    WirelessHost_SetSystemState(3);
    if (WM_End((unsigned)System_SetState10Or0FromHalfword2) == 2) return 1;
    WirelessHost_SetSystemState(9);
    return 0;
}
