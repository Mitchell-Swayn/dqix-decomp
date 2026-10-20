#include <globaldefs.h>
ARM
extern "C" unsigned WirelessHost_GetSystemState(void);
extern "C" void Overlay_RunOperationAndUpdateState(void);
// Original data: arm9/ov031 @ 0x2290d20; symbol: data_ov031_02290d20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0223B010; symbol: func_ov031_0223b010; size: 0x30.
extern "C" int System_ActivateGlobalObjectIfReady(void) {
    if (WirelessHost_GetSystemState() != 1) return 0;
    Overlay_RunOperationAndUpdateState();
    *(unsigned char *)(*(unsigned **)Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage + 0x2a4) = 1;
    return 1;
}
