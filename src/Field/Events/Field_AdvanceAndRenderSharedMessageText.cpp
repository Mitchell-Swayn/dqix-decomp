#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *TextContext_GetSharedInstance(void);
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void *state);
extern "C" void TextWindow_AdvanceTextForRequestedTicks(void *object, unsigned count);
extern "C" void TextWindow_RenderAndTransferDisplayBuffers(void *object, int value);
// Original: arm9/ov017 @ 0x021BE3B4; symbol: func_ov017_021be3b4; size: 0x38.
extern "C" void Field_AdvanceAndRenderSharedMessageText(void) {
    void *state = _ZN9GameState11GetInstanceEv();
    void *object = TextContext_GetSharedInstance();
    TextWindow_AdvanceTextForRequestedTicks(object, _ZNK9GameState12GetTickCountEv(state));
    TextWindow_RenderAndTransferDisplayBuffers(object, 0);
}
