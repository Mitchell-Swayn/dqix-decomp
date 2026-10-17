#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02171698; symbol: func_ov000_02171698; size: 0x38.
extern "C" int func_ov000_02171698(void *entries) {
    signed char count = 0;
    for (int i = 0; i < 0x42; ++i) {
        if (*(unsigned int *)((char *)entries + i * 4 + 0x9c) != 0) count++;
    }
    return count;
}
