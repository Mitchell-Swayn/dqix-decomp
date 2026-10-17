#include <globaldefs.h>
ARM
extern "C" void _Z19ZeroInitializeMutexP5Mutex(void *);
extern "C" unsigned int data_ov031_02290fa4;
// Original: arm9/ov031 @ 0x0223F9F0; symbol: func_ov031_0223f9f0; size: 0x18.
extern "C" int func_ov031_0223f9f0(void) {
    _Z19ZeroInitializeMutexP5Mutex(&data_ov031_02290fa4);
    return 1;
}
