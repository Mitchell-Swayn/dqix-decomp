#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d2c; symbol: data_ov031_02290d2c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WfcUtilityExpandSpriteCellTemplate_UnknownRoleZeroInitializedStorage[];
extern "C" void WfcUtility_FreeArchiveResourceAndReturnPoolEntry(void *);

// Original: arm9/ov031 @ 0x0223BD88; symbol: func_ov031_0223bd88; size: 0x28.
extern "C" void Memory_FreeIndexedGlobalPointerAndClear(unsigned int index) {
    WfcUtility_FreeArchiveResourceAndReturnPoolEntry((void *)WfcUtilityExpandSpriteCellTemplate_UnknownRoleZeroInitializedStorage[index]);
    WfcUtilityExpandSpriteCellTemplate_UnknownRoleZeroInitializedStorage[index] = 0;
}
