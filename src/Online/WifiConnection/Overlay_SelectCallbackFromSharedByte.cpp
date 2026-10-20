#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection();
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void System_SetSharedByte18AndRegisterContextLayerCallback(void);
// Original data: arm9/ov031 @ 0x2290ce0; symbol: data_ov031_02290ce0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" volatile unsigned char OverlaySelectCallbackFromSharedByte_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02234720; symbol: func_ov031_02234720; size: 0x50.
extern "C" void Overlay_SelectCallbackFromSharedByte(void) {
    int value = WfcUtility_GetBottomButtonSelection();
    if (value == 0) goto case_zero;
    if (value == 1) goto case_one;
    return;
case_zero:
    WfcUtility_PlaySequenceArchiveEntry(7);
    goto set_callback;
case_one:
    WfcUtility_PlaySequenceArchiveEntry(6);
    OverlaySelectCallbackFromSharedByte_UnknownRoleZeroInitializedStorage[0] = 1;
set_callback:
    WfcUtility_SetMainLoopCallback(System_SetSharedByte18AndRegisterContextLayerCallback);
}
