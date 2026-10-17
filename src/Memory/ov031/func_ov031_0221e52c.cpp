#include <globaldefs.h>
THUMB
extern "C" void VectorizedMemset(void*, int, unsigned int);
// Original: arm9/ov031 @ 0x0221E52C; symbol: func_ov031_0221e52c; size: 0xC.
extern "C" void func_ov031_0221e52c(void *arg0, unsigned int arg1, unsigned int arg2) {
    VectorizedMemset(arg0, (arg1 << 24) >> 24, arg2);
}
