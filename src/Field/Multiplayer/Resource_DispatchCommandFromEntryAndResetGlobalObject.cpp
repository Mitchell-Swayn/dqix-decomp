#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance(void);
extern "C" void FieldCommandQueue_TransferActiveCommandDisplayBuffers(void *, unsigned int);
extern "C" unsigned int TextContext_GetSharedInstance(void);
extern "C" void TextWindow_RenderAndTransferDisplayBuffers(unsigned int, int);
// Original: arm9/ov017 @ 0x021AFABC; symbol: Resource_DispatchCommandFromEntryAndResetGlobalObject; size: 0x2C.
// Loads the resource table at GameResources+0x3700, dispatches the input word at +4, then calls the global object handler with zero.
extern "C" void Resource_DispatchCommandFromEntryAndResetGlobalObject(void *object) {
    unsigned char *resources = (unsigned char *)GameResources_GetInstance() + 0x3000;
    FieldCommandQueue_TransferActiveCommandDisplayBuffers(*(void **)(resources + 0x700), *(unsigned int *)((unsigned char *)object + 4));
    TextWindow_RenderAndTransferDisplayBuffers(TextContext_GetSharedInstance(), 0);
}
