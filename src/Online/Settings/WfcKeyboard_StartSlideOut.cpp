#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2250bfc; symbol: data_ov031_02250bfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char *WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage;
extern "C" void Network_UnlinkNodeAndReleaseRecords(void *object);
extern "C" void WfcUtility_SetTaskCallback(void *self, unsigned int value);
extern "C" void WfcKeyboard_SlideCommandButtonsOut(void);
// Original: arm9/ov031 @ 0x02223F6C; symbol: func_ov031_02223f6c; size: 0x34.
extern "C" void WfcKeyboard_StartSlideOut(void) {
    unsigned char *object = WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage;
    Network_UnlinkNodeAndReleaseRecords(*(void **)(object + 0x114));
    object = WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage;
    WfcUtility_SetTaskCallback(*(void **)(object + 0x118), (unsigned int)WfcKeyboard_SlideCommandButtonsOut);
}
