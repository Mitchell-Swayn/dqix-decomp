#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" unsigned int TextContext_GetSharedInstance(void);
extern "C" unsigned int _ZNK9GameState12GetTickCountEv(void *);
extern "C" void TextWindow_AdvanceTextForRequestedTicks(void *, unsigned int);
extern "C" void TextWindow_RenderAndTransferDisplayBuffers(void *, int);
extern "C" void TextLayout_FinalizePanelNoOp(void *);
// Original: arm9/ov017 @ 0x021A925C; symbol: func_ov017_021a925c; size: 0x44.
extern "C" void GameState_UpdateCurrentTextAndResetGlobalObject(void *owner) {
    void *state = _ZN9GameState11GetInstanceEv();
    void *object = (void *)TextContext_GetSharedInstance();
    unsigned int tick = _ZNK9GameState12GetTickCountEv(state);
    TextWindow_AdvanceTextForRequestedTicks(object, tick);
    TextWindow_RenderAndTransferDisplayBuffers(object, 0);
    TextLayout_FinalizePanelNoOp((unsigned char *)owner + 0x2c);
}
