#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e6a0; symbol: data_ov031_0224e6a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityReadFourSettingsPages_UnknownRoleZeroInitializedStorage[];
extern "C" int Network_SendIpcCommandAndInvalidateResponse(void *, int, int);
// Original: arm9/ov031 @ 0x0221AFF8; symbol: func_ov031_0221aff8; size: 0x2C.
extern "C" unsigned int WfcUtility_ReadFourSettingsPages(int value) {
    return Network_SendIpcCommandAndInvalidateResponse(*(void **)(WfcUtilityReadFourSettingsPages_UnknownRoleZeroInitializedStorage + 8), 0x400, value) != 0;
}
