#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void*);
extern "C" void TextWindow_AdvanceTextForRequestedTicks(void*, int);
extern "C" void TextWindow_RenderAndTransferDisplayBuffers(void*, unsigned);
// Original: arm9/ov017 @ 0x021BF360; symbol: func_ov017_021bf360; size: 0x38.
extern "C" void GameState_UpdateTextHandlerFromTick(void) {
    void* state = _ZN9GameState11GetInstanceEv();
    void* object = (void*)TextContext_GetSharedInstance();
    TextWindow_AdvanceTextForRequestedTicks(object, _ZNK9GameState12GetTickCountEv(state));
    TextWindow_RenderAndTransferDisplayBuffers(object, 0);
}
