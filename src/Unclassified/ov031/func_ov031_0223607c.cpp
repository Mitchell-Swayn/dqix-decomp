#include <globaldefs.h>
ARM
extern "C" unsigned char* data_ov031_02290cfc;
// Original: arm9/ov031 @ 0x0223607C; symbol: func_ov031_0223607c; size: 0x18.
extern "C" unsigned int func_ov031_0223607c(unsigned int index) { volatile unsigned char* p = data_ov031_02290cfc + (index << 8); return p[0xe7]; }
