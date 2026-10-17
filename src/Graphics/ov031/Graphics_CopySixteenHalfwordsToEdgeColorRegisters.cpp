#include <globaldefs.h>
ARM
extern "C" void MIi_CpuCopy16(const void*, volatile void*, int);
extern "C" void func_ov031_0223e2c0(unsigned int, void*);
extern "C" unsigned int data_ov031_02290ce8[];
// Original: arm9/ov031 @ 0x02235034; symbol: func_ov031_02235034; size: 0x2C.
extern "C" void Graphics_CopySixteenHalfwordsToEdgeColorRegisters(const void* p) { MIi_CpuCopy16((void*)data_ov031_02290ce8[1], (volatile void*)data_ov031_02290ce8[2], 0x20); func_ov031_0223e2c0(1, (void*)p); }
