#include <globaldefs.h>
ARM

extern "C" void VectorizedMemset(void *dst, int value, unsigned int length);

// Original: arm9/ov031 @ 0x02204168; symbol: func_ov031_02204168; size: 0x34.
extern "C" void *Memory_FillRemainingBytes(int value, unsigned int total, void *dst, unsigned int current) {
    if (current < total) {
        unsigned int remaining = total - current;
        VectorizedMemset(dst, value, remaining);
        dst = (char *)dst + remaining;
    }
    return dst;
}
