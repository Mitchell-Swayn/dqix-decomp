#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2250ba8; symbol: data_ov031_02250ba8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern volatile unsigned int WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage[];
extern "C" void WfcUtility_SetTaskCallback(void *, void *);
extern "C" void WfcUtility_SlideBottomButtonBarOut(void);
// Original: arm9/ov031 @ 0x02222DDC; symbol: System_SetReadyAndScheduleWordCallback; size: 0x30.
// Sets the shared object ready byte at +0x19 and schedules the callback with its word at +0xc.
extern "C" void System_SetReadyAndScheduleWordCallback(void) {
    *((volatile unsigned char *)WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage[0] + 0x19) = 1;
    WfcUtility_SetTaskCallback((void *)(*(unsigned int *)(*(volatile unsigned int *)WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage + 0x0c)), (void *)WfcUtility_SlideBottomButtonBarOut);
}
