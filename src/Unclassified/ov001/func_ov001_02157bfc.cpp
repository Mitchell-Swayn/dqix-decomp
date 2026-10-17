#include <globaldefs.h>
ARM
extern "C" void *memcpy(void *dst, const void *src, unsigned length);
// Original: arm9/ov001 @ 0x02157BFC; symbol: func_ov001_02157bfc; size: 0x20.
extern "C" unsigned func_ov001_02157bfc(const void *source, void *destination) {
    memcpy((char *)destination + 0x4c, (const char *)source + 4, 0xc);
    return 0;
}
