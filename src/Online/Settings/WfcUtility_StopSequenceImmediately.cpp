#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d00; symbol: data_ov031_02290d00.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *WfcUtilityDestroySoundContextAndUpdateTask_UnknownRoleZeroInitializedStorage;
extern "C" void ResourceHandle_StopOrFadeSequence(void **, int);
// Original: arm9/ov031 @ 0x022368E0; symbol: func_ov031_022368e0; size: 0x20.
extern "C" void WfcUtility_StopSequenceImmediately(void) {
    ResourceHandle_StopOrFadeSequence((void **)((char *)WfcUtilityDestroySoundContextAndUpdateTask_UnknownRoleZeroInitializedStorage + 0x94), 0);
}
