#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e6a0; symbol: data_ov031_0224e6a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char WfcUtilityReadFourSettingsPages_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0221B8B4; symbol: func_ov031_0221b8b4; size: 0x30.
extern "C" unsigned short System_SetGlobalControlByteAndReturnHalfword(int, unsigned int value, int overrideValue) {
    *(volatile unsigned short *)WfcUtilityReadFourSettingsPages_UnknownRoleZeroInitializedStorage = (unsigned short)(value & 0xff);
    *(volatile unsigned int *)(WfcUtilityReadFourSettingsPages_UnknownRoleZeroInitializedStorage + 4) = 1;
    if (overrideValue)
        *(volatile unsigned short *)WfcUtilityReadFourSettingsPages_UnknownRoleZeroInitializedStorage = 0xff;
    return *(volatile unsigned short *)WfcUtilityReadFourSettingsPages_UnknownRoleZeroInitializedStorage;
}
