#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_0224e540[];
extern "C" void _Z19ZeroInitializeMutexP5Mutex(void *);
// Original: arm9/ov031 @ 0x0220EF5C; symbol: func_ov031_0220ef5c; size: 0x40.
extern "C" void func_ov031_0220ef5c(void) {
    if (data_ov031_0224e540[0] != 0) return;
    data_ov031_0224e540[0] = 1;
    *(unsigned int *)(data_ov031_0224e540 + 0x24) = 0;
    *(unsigned int *)(data_ov031_0224e540 + 8) = 0;
    *(unsigned int *)(data_ov031_0224e540 + 4) = 0;
    _Z19ZeroInitializeMutexP5Mutex(data_ov031_0224e540 + 0xc);
}
