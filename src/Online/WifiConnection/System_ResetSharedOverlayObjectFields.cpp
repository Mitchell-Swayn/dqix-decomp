#include <globaldefs.h>
// Original data: arm9/ov031 @ 0x2290d18; symbol: data_ov031_02290d18.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" volatile unsigned WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0223932C; symbol: func_ov031_0223932c; size: 0x3C.
extern "C" void System_ResetSharedOverlayObjectFields(void* object) {
    WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[1] = (unsigned)object;
    *(unsigned*)((char*)object + 0x40) = 0;
    *(unsigned*)((char*)(void*)WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[1] + 0x13a8) = 0;
    *(unsigned*)((char*)(void*)WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[1] + 0x13ac) = 0;
    *(unsigned*)((char*)(void*)WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[1] + 0x13b0) = 0;
}
