#include <globaldefs.h>
ARM
extern "C" void *memcpy(void *dst, const void *src, unsigned length);
// Original: arm9/ov001 @ 0x0215929C; symbol: func_ov001_0215929c; size: 0x20.
extern "C" unsigned func_ov001_0215929c(const void *source, void *destination) {
    memcpy((char *)destination + 0x74, (const char *)source + 4, 0xc);
    return 0;
}
