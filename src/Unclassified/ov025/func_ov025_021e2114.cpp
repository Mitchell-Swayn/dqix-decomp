#include <globaldefs.h>
ARM

extern "C" void *memcpy(void *, const void *, int);
extern "C" void DisableInterruptsAndHaltForever(void);

// Original: arm9/ov025 @ 0x021E2114; symbol: func_ov025_021e2114; size: 0x34.
extern "C" void func_ov025_021e2114(void *dst, const void *src, int length) {
    if (length > 12) {
        DisableInterruptsAndHaltForever();
    }
    memcpy((char *)dst + 8, src, length);
    ((unsigned char *)dst)[0x14] = (unsigned char)length;
}
