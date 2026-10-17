#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02290f8c[];
extern "C" unsigned int data_ov031_02290f88;
extern "C" void _Z19ZeroInitializeMutexP5Mutex(void *);
// Original: arm9/ov031 @ 0x0223FA34; symbol: func_ov031_0223fa34; size: 0x28.
extern "C" int InitializeOverlayMutexAndClearMetadata(void) {
    _Z19ZeroInitializeMutexP5Mutex(data_ov031_02290f8c);
    data_ov031_02290f88 = 0;
    return 1;
}
