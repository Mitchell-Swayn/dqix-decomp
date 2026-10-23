#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d10; symbol: data_ov031_02290d10.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern void *WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage;
extern "C" void ColorEffect_ChangeBrightness(unsigned int control, int brightness);
extern "C" void WfcUtility_SetTaskCallback(void*,void (*)(void*,void*));
extern "C" void WfcUtility_AdvanceDialogSlideIn(void*,void*);
// Original: arm9/ov031 @ 0x02237ECC; symbol: func_ov031_02237ecc; size: 0x60.
extern "C" void GameState_DecrementGlobalBrightnessAndNotifyAtMinusTwelve(void* self,void*) {
    (*(signed char *)((unsigned char *)WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage + 0x1A))--;
    ColorEffect_ChangeBrightness(0x04000050, *(signed char *)((unsigned char *)WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage + 0x1A));
    if (*(signed char *)((unsigned char *)WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage + 0x1A) > -12) return;
    WfcUtility_SetTaskCallback(self, WfcUtility_AdvanceDialogSlideIn);
}
