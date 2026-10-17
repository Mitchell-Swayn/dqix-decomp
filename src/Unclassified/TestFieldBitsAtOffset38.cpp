#include <globaldefs.h>
ARM
extern "C" unsigned char data_021117b0[];
// Original: arm9/main @ 0x020CE114; symbol: func_020ce114; size: 0x14.
extern "C" unsigned int TestFieldBitsAtOffset38(unsigned int mask) { return *(unsigned short*)(data_021117b0+0x38)&mask; }
