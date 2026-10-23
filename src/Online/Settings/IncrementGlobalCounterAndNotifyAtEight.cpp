#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d10; symbol: data_ov031_02290d10.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_SetTaskCallback(void*,void (*)(void*,void*));
extern "C" void WfcUtility_AdvanceDialogSlideOut(void*,void*);
// Original: arm9/ov031 @ 0x022384BC; symbol: func_ov031_022384bc; size: 0x3C.
extern "C" void IncrementGlobalCounterAndNotifyAtEight(void* self,void*) {
    (*(unsigned char *)((unsigned char *)WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage + 0x1d))++;
    if (*(unsigned char *)((unsigned char *)WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage + 0x1d) >= 8) {
        WfcUtility_SetTaskCallback(self, WfcUtility_AdvanceDialogSlideOut);
    }
}
