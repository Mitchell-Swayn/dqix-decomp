#include <globaldefs.h>
ARM
// Original: arm9/ov001 @ 0x02164194; symbol: func_ov001_02164194; size: 0x4C.
extern "C" int func_ov001_02164194(void *out, unsigned int type, unsigned int value, unsigned int valid) {
    if (valid == 0) return 0;
    *(unsigned int *)out = type;
    switch (type) {
    case 0: case 1: case 4: case 5:
        *(unsigned int *)((char *)out + 4) = value;
        *(unsigned int *)((char *)out + 0xc) = valid;
        return 1;
    default:
        return 0;
    }
}
