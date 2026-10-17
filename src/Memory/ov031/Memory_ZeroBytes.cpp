#include <globaldefs.h>
ARM
extern "C" void VectorizedMemset(void *dst, int value, unsigned int length);
// Original: arm9/ov031 @ 0x0223FB60; symbol: func_ov031_0223fb60; size: 0x14.
extern "C" void Memory_ZeroBytes(void *dst, unsigned int length) {
    VectorizedMemset(dst, 0, length);
}
