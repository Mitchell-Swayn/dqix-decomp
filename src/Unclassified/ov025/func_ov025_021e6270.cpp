#include <globaldefs.h>
ARM
extern "C" unsigned data_ov025_021ef988[];
// Original: arm9/ov025 @ 0x021E6270; symbol: func_ov025_021e6270; size: 0x1C.
extern "C" unsigned func_ov025_021e6270(void *object) {
    unsigned value = *(unsigned *)((char *)object + 8);
    char *target = *(char **)((char *)data_ov025_021ef988 + 0xc);
    *(unsigned *)(target + 0x548) = value;
    return 1;
}
