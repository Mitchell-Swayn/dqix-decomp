#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned TextContext_GetSharedInstance(void*);
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void*);
extern "C" void TextWindow_AdvanceTextForRequestedTicks(void*, int);
extern "C" void TextWindow_RenderAndTransferDisplayBuffers(void*, int);
// Original: arm9/ov017 @ 0x021C1DFC; symbol: func_ov017_021c1dfc; size: 0x38.
extern "C" void UpdateObjectTextCountFromTick() {
    void* gameState = _ZN9GameState11GetInstanceEv();
    unsigned* object = (unsigned*)TextContext_GetSharedInstance(gameState);
    unsigned tick = _ZNK9GameState12GetTickCountEv(gameState);
    TextWindow_AdvanceTextForRequestedTicks(object, tick);
    TextWindow_RenderAndTransferDisplayBuffers(object, 0);
}
