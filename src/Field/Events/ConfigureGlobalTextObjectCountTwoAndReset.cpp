#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void);
extern "C" void TextWindow_AdvanceTextForRequestedTicks(void *object, int count);
extern "C" void TextWindow_RenderAndTransferDisplayBuffers(void *object, int value);
// Original: arm9/ov017 @ 0x021ACD00; symbol: func_ov017_021acd00; size: 0x24.
extern "C" void ConfigureGlobalTextObjectCountTwoAndReset(void) {
    unsigned int object = TextContext_GetSharedInstance();
    TextWindow_AdvanceTextForRequestedTicks((void *)object, 2);
    TextWindow_RenderAndTransferDisplayBuffers((void *)object, 0);
}
