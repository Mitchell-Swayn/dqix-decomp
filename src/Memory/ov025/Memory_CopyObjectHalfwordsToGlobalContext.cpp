#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov025_021ef988[];

// Original: arm9/ov025 @ 0x021E6EF8; symbol: func_ov025_021e6ef8; size: 0x28.
extern "C" int Memory_CopyObjectHalfwordsToGlobalContext(void *object) {
    short second = *(short *)((unsigned char *)object + 0x0a);
    unsigned short first = *(unsigned short *)((unsigned char *)object + 8);
    *(unsigned short *)((unsigned char *)data_ov025_021ef988[3] + 0x57e) = first;
    *(short *)((unsigned char *)data_ov025_021ef988[3] + 0x580) = second;
    return 1;
}
