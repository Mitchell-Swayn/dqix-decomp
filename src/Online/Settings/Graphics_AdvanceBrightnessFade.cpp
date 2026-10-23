#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d10; symbol: data_ov031_02290d10.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" signed char* WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage;
extern "C" void ColorEffect_ChangeBrightness(int control, int newBrightness);
extern "C" void WfcUtility_SetTaskCallback(void*,void (*)(void*,void*));
extern "C" void WfcUtility_DestroySlidingDialog(void*,void*);
// Original: arm9/ov031 @ 0x02238588; symbol: func_ov031_02238588; size: 0x5C.
extern "C" void Graphics_AdvanceBrightnessFade(void* object,void*) {
    WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage[0x1a]++;
    ColorEffect_ChangeBrightness(0x04000050, WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage[0x1a]);
    if (WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage[0x1a] >= 0)
        WfcUtility_SetTaskCallback(object, WfcUtility_DestroySlidingDialog);
}
