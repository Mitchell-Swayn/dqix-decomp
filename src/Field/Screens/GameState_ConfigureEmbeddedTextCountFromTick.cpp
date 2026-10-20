#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned TextContext_GetSharedInstance(void*);
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void*);
extern "C" void TextWindow_AdvanceTextForRequestedTicks(void*, int);
extern "C" void TextWindow_RenderAndTransferDisplayBuffers(void*, int);
// Original: arm9/ov017 @ 0x021A9638; symbol: func_ov017_021a9638; size: 0x38.
extern "C" void GameState_ConfigureEmbeddedTextCountFromTick() {
    void* game = _ZN9GameState11GetInstanceEv();
    unsigned count = TextContext_GetSharedInstance(game);
    unsigned tick = _ZNK9GameState12GetTickCountEv(game);
    TextWindow_AdvanceTextForRequestedTicks((void*)count, (int)tick);
    TextWindow_RenderAndTransferDisplayBuffers((void*)count, 0);
}
