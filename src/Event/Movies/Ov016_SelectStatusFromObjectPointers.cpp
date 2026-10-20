#include <globaldefs.h>
ARM
// Original: arm9/ov016 @ 0x0218EF2C; symbol: func_ov016_0218ef2c; size: 0x24.
extern "C" unsigned int Ov016_SelectStatusFromObjectPointers(void *object) {
    if (!*(unsigned int *)((char *)object + 0x20))
        return 0;
    return *(unsigned int *)((char *)object + 0x28) ? 0x80 : 0x100;
}
