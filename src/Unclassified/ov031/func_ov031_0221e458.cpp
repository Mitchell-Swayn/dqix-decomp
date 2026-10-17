#include <globaldefs.h>
THUMB
extern "C" unsigned int data_ov031_0224f4c0[];
// Original: arm9/ov031 @ 0x0221E458; symbol: func_ov031_0221e458; size: 0x18.
extern "C" int func_ov031_0221e458(void* unused, int count) { return count > 0 ? ((int (*)(int))data_ov031_0224f4c0[0])(count) : 0; }
