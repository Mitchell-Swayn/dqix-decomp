#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov016_0219d0c0[];
extern "C" void *_ZN13SafeAllocator8AllocateEj(void *, unsigned int);
// Original: arm9/ov016 @ 0x0218BC8C; symbol: func_ov016_0218bc8c; size: 0x1C.
extern "C" void *Memory_AllocateSafe(unsigned int size) {
    return _ZN13SafeAllocator8AllocateEj(*(void **)(data_ov016_0219d0c0 + 8), size);
}
