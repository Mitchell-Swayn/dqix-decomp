#include <globaldefs.h>
ARM
extern "C" unsigned char *HasTypeSevenAtResolvedHandle(void *, void *);
// Original: arm9/ov023 @ 0x021F65B4; symbol: func_ov023_021f65b4; size: 0x20.
extern "C" void func_ov023_021f65b4(void *a, void *b, unsigned short first, unsigned short second) {
    unsigned char *result = HasTypeSevenAtResolvedHandle(a, b);
    if (result) {
        *(unsigned short *)(result + 0x5c) = first;
        *(unsigned short *)(result + 0x5e) = second;
    }
}
