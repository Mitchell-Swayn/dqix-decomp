#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x0215E8F4; symbol: func_ov003_0215e8f4; size: 0x3C.
extern "C" void *func_ov003_0215e8f4(void *object) {
    char *sub = *(char **)((char *)object + 4);
    unsigned char mask = *((unsigned char *)object + 0x1e);
    unsigned char *record = *(unsigned char **)(sub + 8);
    int count = *(short *)(sub + 0xe);
    for (int i = 0; i < count; ++i, record += 8)
        if ((*record & mask) != 0) return record;
    return 0;
}
