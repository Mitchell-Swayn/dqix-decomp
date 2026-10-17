#include <globaldefs.h>
ARM
extern "C" void *data_ov016_0219d0c0[];
extern "C" void _ZN13SafeAllocator4FreeEPv(void *, void *);
// Original: arm9/ov016 @ 0x0218BCA8; symbol: func_ov016_0218bca8; size: 0x1C.
extern "C" void FreeWithGlobalSafeAllocator(void *allocation) {
    _ZN13SafeAllocator4FreeEPv(data_ov016_0219d0c0[2], allocation);
}
