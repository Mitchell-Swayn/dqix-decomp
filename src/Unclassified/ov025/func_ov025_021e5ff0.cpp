#include <globaldefs.h>
ARM
extern "C" unsigned data_ov025_021ef988[];
// Original: arm9/ov025 @ 0x021E5FF0; symbol: func_ov025_021e5ff0; size: 0x20.
extern "C" unsigned func_ov025_021e5ff0(void *object) {
    unsigned short value = *(unsigned short *)((char *)object + 8);
    char *target = *(char **)((char *)data_ov025_021ef988 + 0xc);
    *(unsigned short *)(target + 0x21c) = value;
    return 1;
}
