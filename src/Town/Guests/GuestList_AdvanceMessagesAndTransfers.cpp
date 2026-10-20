#include <globaldefs.h>
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void *);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void TextWindow_AdvanceTextForRequestedTicks(void *, int);
extern "C" void TextWindow_RenderAndTransferDisplayBuffers(void *, int);
extern "C" void Window_ResetResourceTransfers(void *);
// Original: arm9/ov003 @ 0x02170280; symbol: func_ov003_02170280; size: 0x64.
extern "C" void GuestList_AdvanceMessagesAndTransfers(void *owner) {
    if (!*(void **)((char *)owner + 0x3c)) return;
    if (*(signed char *)((char *)owner + 1) <= 1) return;
    void *game = _ZN9GameState11GetInstanceEv();
    void *shared = (void *)TextContext_GetSharedInstance();
    TextWindow_AdvanceTextForRequestedTicks(shared, _ZNK9GameState12GetTickCountEv(game));
    TextWindow_RenderAndTransferDisplayBuffers(shared, 0);
    if (*(void **)((char *)owner + 0x3c)) Window_ResetResourceTransfers(*(void **)((char *)owner + 0x3c));
}
