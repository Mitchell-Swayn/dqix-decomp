#include <globaldefs.h>
ARM
extern "C" unsigned TextContext_GetSharedInstance(void);
extern "C" void Graphics_ClearAndStageSharedBuffers(char *p);
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void *p);
// Original: arm9/ov001 @ 0x0215E398; symbol: func_ov001_0215e398; size: 0x20.
extern "C" unsigned Graphics_ClearAndStageBuffersAndResetSelectionState(void) {
    unsigned value = TextContext_GetSharedInstance();
    Graphics_ClearAndStageSharedBuffers((char *)value);
    TextWindow_ResetGlyphBuffersAndFrameContexts((void *)value);
    return 1;
}
