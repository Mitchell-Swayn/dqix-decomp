#include <globaldefs.h>
extern "C" void* Graphics_CreateBG0CanvasForScreen(unsigned, unsigned);
extern "C" int WfcUtility_GetMessageText(void*, int);
extern "C" unsigned WfcUtility_GetLanguageMessageLayoutParameter();
// Original data: arm9/ov031 @ 0x2290c4c; symbol: data_ov031_02290c4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityCreateSlidingDialog_UnknownRoleZeroInitializedStorage[];
extern "C" void WfcUtility_RenderCanvasAlignedText(void*, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern "C" void WfcUtility_MarkBackgroundTextCanvasDirty(void*);
// Original: arm9/ov031 @ 0x022235A0; symbol: func_ov031_022235a0; size: 0x74.
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(int index) {
    void* buffer = Graphics_CreateBG0CanvasForScreen(0, 0);
    int value = WfcUtility_GetMessageText(*(void**)WfcUtilityCreateSlidingDialog_UnknownRoleZeroInitializedStorage, index);
    unsigned metric = WfcUtility_GetLanguageMessageLayoutParameter();
    WfcUtility_RenderCanvasAlignedText(buffer, 0xd, 0x28, 0xe6, 0x70, 2, metric, (unsigned)value);
    WfcUtility_MarkBackgroundTextCanvasDirty(buffer);
}
