#include <globaldefs.h>
ARM
extern "C" void VectorizedMemset(void*, int, unsigned int);
// Original: arm9/ov023 @ 0x021F6788; symbol: func_ov023_021f6788; size: 0x24.
extern "C" void Memory_Clear22BytesAndSetTwoSentinels(unsigned char* p) { VectorizedMemset(p, 0, 0x16); *(short*)(p + 0x12) = -1; *(short*)(p + 0x14) = -1; }
