#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290c5c; symbol: data_ov031_02290c5c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x2248dc4; symbol: data_ov031_02248dc4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01020300e0008400.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityScheduleOptionsSelectionPalette_UnknownRoleInitializedBytes[];
extern "C" void WfcUtility_QueueBackgroundPaletteBankCopy(void *, unsigned int, unsigned int);

// Original: arm9/ov031 @ 0x02229748; symbol: func_ov031_02229748; size: 0x2C.
extern "C" void WfcUtility_ScheduleOptionsSelectionPalette(void) {
    unsigned int index = WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage[0];
    unsigned int value = WfcUtilityScheduleOptionsSelectionPalette_UnknownRoleInitializedBytes[index];
    WfcUtility_QueueBackgroundPaletteBankCopy(*(void **)(WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage + 4), value, value);
}
