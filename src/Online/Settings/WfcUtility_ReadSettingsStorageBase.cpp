#include <globaldefs.h>
ARM
extern "C" int Network_SendIpcCommandAndInvalidateResponse(unsigned int, unsigned int, unsigned int);
// Original data: arm9/ov031 @ 0x224e6a0; symbol: data_ov031_0224e6a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WfcUtilityReadFourSettingsPages_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0221AFB4; symbol: func_ov031_0221afb4; size: 0x44.
extern "C" int WfcUtility_ReadSettingsStorageBase(void *context) {
    if (Network_SendIpcCommandAndInvalidateResponse(0x20, 0x20, (unsigned int)context) == 0) return 0;
    WfcUtilityReadFourSettingsPages_UnknownRoleZeroInitializedStorage[2] = (*(unsigned short *)context << 3) - 0x400;
    return 1;
}
