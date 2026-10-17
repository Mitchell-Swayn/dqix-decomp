#include <globaldefs.h>
ARM
extern "C" void _Z19ZeroInitializeMutexP5Mutex(void *mutex);
extern "C" unsigned char data_ov031_022918a4[];
// Original: arm9/ov031 @ 0x022402F4; symbol: func_ov031_022402f4; size: 0x18.
extern "C" int System_InitializeOverlayMutexAndReturnOne(void) {
    _Z19ZeroInitializeMutexP5Mutex(data_ov031_022918a4);
    return 1;
}
