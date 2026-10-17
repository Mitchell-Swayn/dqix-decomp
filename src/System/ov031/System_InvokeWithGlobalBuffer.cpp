#include <globaldefs.h>
THUMB
extern "C" unsigned char data_ov031_0224e9a0[];
extern "C" int func_ov031_0221e2e4(int a, void *first, int second, int fourth, void *extra);
// Original: arm9/ov031 @ 0x0221E2BC; symbol: func_ov031_0221e2bc; size: 0x28.
extern "C" unsigned char System_InvokeWithGlobalBuffer(void *first, int second) {
    int result = func_ov031_0221e2e4(-1, first, second, 0, data_ov031_0224e9a0);
    int mask = ~0;
    return (unsigned char)(result ^ mask);
}
