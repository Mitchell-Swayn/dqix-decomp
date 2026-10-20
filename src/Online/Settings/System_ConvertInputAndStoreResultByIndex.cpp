#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d2c; symbol: data_ov031_02290d2c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned int WfcUtilityExpandSpriteCellTemplate_UnknownRoleZeroInitializedStorage[];
extern "C" unsigned int WfcUtility_LoadArchiveResource(void *, unsigned char *, int);
// Original: arm9/ov031 @ 0x0223BD58; symbol: func_ov031_0223bd58; size: 0x30.
extern "C" void System_ConvertInputAndStoreResultByIndex(int index, void *input) {
    unsigned char byte;
    unsigned int result = WfcUtility_LoadArchiveResource(input, &byte, 4);
    WfcUtilityExpandSpriteCellTemplate_UnknownRoleZeroInitializedStorage[index] = result;
}
