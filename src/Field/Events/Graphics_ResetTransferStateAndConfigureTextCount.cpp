#include <globaldefs.h>
extern "C" void Graphics_ResetCountedTransferEntriesWithModeZero(void*);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void TextWindow_AdvanceTextForRequestedTicks(void*, int);
extern "C" void TextWindow_RenderAndTransferDisplayBuffers(void*, int);
// Original: arm9/ov017 @ 0x021AAEC8; symbol: func_ov017_021aaec8; size: 0x40.
extern "C" void Graphics_ResetTransferStateAndConfigureTextCount(void* object) {
    if (*(unsigned*)((char*)object + 0x14) == 5) {
        void* state = *(void**)((char*)object + 0x18);
        if (state) Graphics_ResetCountedTransferEntriesWithModeZero(state);
    }
    unsigned value = TextContext_GetSharedInstance();
    TextWindow_AdvanceTextForRequestedTicks((void*)value, 8);
    TextWindow_RenderAndTransferDisplayBuffers((void*)value, 0);
}
