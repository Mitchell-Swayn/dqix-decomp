#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned int TextContext_GetSharedInstance(void*);
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void*);
extern "C" void TextWindow_AdvanceTextForRequestedTicks(void*, int);
extern "C" void TextWindow_RenderAndTransferDisplayBuffers(void*, int);
extern "C" void TextLayout_FinalizePanelNoOp(void*);
// Original: arm9/ov017 @ 0x021A79AC; symbol: func_ov017_021a79ac; size: 0x44.
extern "C" ARM void Ov017_InitializeTimedTextRecord(void* object) {
    void* state = _ZN9GameState11GetInstanceEv();
    unsigned int record = TextContext_GetSharedInstance(state);
    unsigned tick = _ZNK9GameState12GetTickCountEv(state);
    TextWindow_AdvanceTextForRequestedTicks((void*)record, tick);
    TextWindow_RenderAndTransferDisplayBuffers((void*)record, 0);
    TextLayout_FinalizePanelNoOp((char*)object + 0x24);
}
