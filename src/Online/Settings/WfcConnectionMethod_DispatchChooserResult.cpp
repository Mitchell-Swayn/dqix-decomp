#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int mode);
extern "C" void ConfigureTransformFromSharedSignedSelector(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void SetSharedByteAndScheduleCallback33720(void);
// Original data: arm9/ov031 @ 0x2290cc8; symbol: data_ov031_02290cc8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemConfigureSecondaryDisplayMode_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x022336AC; symbol: func_ov031_022336ac; size: 0x54.
extern "C" void WfcConnectionMethod_DispatchChooserResult(void) {
    switch (WfcUtility_GetBottomButtonSelection()) {
    case 0:
        WfcUtility_PlaySequenceArchiveEntry(7);
        break;
    case 1:
        WfcUtility_PlaySequenceArchiveEntry(6);
        ConfigureTransformFromSharedSignedSelector();
        SystemConfigureSecondaryDisplayMode_UnknownRoleZeroInitializedStorage[2] = 1;
        break;
    default:
        return;
    }
    WfcUtility_SetMainLoopCallback(SetSharedByteAndScheduleCallback33720);
}
