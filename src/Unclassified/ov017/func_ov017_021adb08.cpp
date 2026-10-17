#include <globaldefs.h>
ARM
extern "C" void Memory_DestroyAndFreeSafeAllocator(int, int);
// Original: arm9/ov017 @ 0x021ADB08; symbol: func_ov017_021adb08; size: 0x14.
extern "C" void func_ov017_021adb08(int a0) {
    *(unsigned char *)(a0 + 1) = 1;
    Memory_DestroyAndFreeSafeAllocator(a0, 1);
}
