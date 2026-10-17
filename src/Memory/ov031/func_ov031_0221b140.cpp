#include <globaldefs.h>
ARM
extern "C" void MI_CpuCopy8(void *, const void *, unsigned int);
extern "C" unsigned int data_ov031_0224e6ac[];
// Original: arm9/ov031 @ 0x0221B140; symbol: func_ov031_0221b140; size: 0x18.
extern "C" void func_ov031_0221b140(void *dst) { MI_CpuCopy8(dst, data_ov031_0224e6ac, 0xe); }
