#include <globaldefs.h>
extern "C" int func_ov027_021d8aec(int);
extern "C" unsigned char data_ov031_02290d14[];
// Original: arm9/ov031 @ 0x02238C40; symbol: func_ov031_02238c40; size: 0x68.
extern "C" int OV031_ValidateEnabledResourceBits(void) {
    volatile unsigned char * volatile *global = (volatile unsigned char * volatile *)data_ov031_02290d14;
    if (*(unsigned short *)(*global + 2) == 0) return 0;
    unsigned short index = 1;
    do {
        unsigned short flags = *(unsigned short *)(*global + 2);
        if ((flags & (1u << index)) && !func_ov027_021d8aec(index)) return 0;
        ++index;
    } while (index < 0x10);
    return 1;
}
