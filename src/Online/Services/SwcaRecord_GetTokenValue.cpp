#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0221170C; symbol: func_ov031_0221170c; size: 0x14.
extern "C" unsigned long long SwcaRecord_GetTokenValue(void *object) {
    return ((unsigned long long)*(unsigned *)object << 32) | *(unsigned *)((char *)object + 4);
}
