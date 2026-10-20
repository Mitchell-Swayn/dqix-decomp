#include <globaldefs.h>
ARM

extern "C" void LinkedQueue_InitializeNodeStatus(signed char *p);
extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" void TextLayout_InitializeSelectionPanel(unsigned char *p);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *);
extern "C" void ResourceStringLoader_Reset(char *p);

// Original: arm9/ov017 @ 0x021A8670; symbol: func_ov017_021a8670; size: 0x60.
extern "C" void Field_InitializeTravelDestinationMenu(unsigned char *record) {
    LinkedQueue_InitializeNodeStatus((signed char *)record);
    record[0] = 0x38;
    int zero = 0;
    *(unsigned int *)(record + 8) = zero;
    int invalid = zero - 1;
    *(int *)(record + 0x28) = invalid;
    *(unsigned int *)(record + 0xc) = zero;
    *(unsigned int *)(record + 0x10) = zero;
    *(unsigned int *)(record + 0x14) = zero;
    memset(record + 0x18, 0, 5);
    *(unsigned int *)(record + 0x20) = zero;
    TextLayout_InitializeSelectionPanel(record + 0x2c);
    _ZN13SafeAllocator21ResetAllocatorPointerEv(record + 0x264);
    ResourceStringLoader_Reset((char *)record + 0x278);
}
