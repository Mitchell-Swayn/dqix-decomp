#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d00; symbol: data_ov031_02290d00.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WfcUtilityDestroySoundContextAndUpdateTask_UnknownRoleZeroInitializedStorage;
extern "C" void ResourceHandle_SetOptionalByte41(void *, unsigned int);
// Original: arm9/ov031 @ 0x0223689C; symbol: func_ov031_0223689c; size: 0x20.
extern "C" void WfcUtility_SetSequenceVolume(unsigned int value) {
    ResourceHandle_SetOptionalByte41((unsigned char *)(*(unsigned int *)&WfcUtilityDestroySoundContextAndUpdateTask_UnknownRoleZeroInitializedStorage) + 0x94, value);
}
