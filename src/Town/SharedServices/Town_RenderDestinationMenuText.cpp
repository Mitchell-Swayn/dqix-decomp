#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void*);
extern "C" void TextWindow_AdvanceTextForRequestedTicks(void*, int);
extern "C" void TextWindow_RenderAndTransferDisplayBuffers(void*, int);
extern "C" void Window_ResetResourceTransfers(void*);
// Original: arm9/ov003 @ 0x0217DAA4; symbol: Unclassified_ConfigureTextHandlerAndResetResourceConditionally; size: 0x4C.
// Configures the embedded text handler for two entries and runs its reset helper; resets self+0x90 resource if present and the +4/+5 byte condition permits.
extern "C" void Town_RenderDestinationMenuText(unsigned char* self) {
    unsigned int handler = TextContext_GetSharedInstance(self);
    TextWindow_AdvanceTextForRequestedTicks((void*)handler, 2);
    TextWindow_RenderAndTransferDisplayBuffers((void*)handler, 0);
    void* resource = *(void**)(self + 0x90);
    if (!resource) return;
    if (*(signed char*)(self + 4) != 2 && *(signed char*)(self + 5) != 0) return;
    Window_ResetResourceTransfers(resource);
}
