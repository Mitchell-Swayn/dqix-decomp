#include <globaldefs.h>
ARM
extern "C" void LinkedQueue_InitializeNodeStatus(signed char *);
extern "C" void TextLayout_InitializeSelectionPanel(unsigned char *);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *);
extern "C" void ResourceStringLoader_Reset(char *);
// Original: arm9/ov017 @ 0x021A7328; symbol: func_ov017_021a7328; size: 0x50.
extern "C" void Field_InitializeTravelConfirmation(signed char *obj) {
    LinkedQueue_InitializeNodeStatus(obj);
    *(unsigned char *)obj = 0x3f;
    int zero = 0;
    *(unsigned int *)(obj + 8) = zero;
    *(unsigned int *)(obj + 0xc) = zero;
    *(unsigned int *)(obj + 0x10) = zero;
    *(unsigned int *)(obj + 0x20) = zero - 1;
    *(unsigned int *)(obj + 0x14) = zero;
    *(unsigned int *)(obj + 0x18) = zero;
    TextLayout_InitializeSelectionPanel((unsigned char *)obj + 0x24);
    _ZN13SafeAllocator21ResetAllocatorPointerEv(obj + 0x25c);
    ResourceStringLoader_Reset((char *)obj + 0x270);
}
