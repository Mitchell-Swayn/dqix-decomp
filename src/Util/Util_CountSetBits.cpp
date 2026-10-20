#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020D1AE4; symbol: func_020d1ae4; size: 0x44.
extern "C" unsigned int Util_CountSetBits(unsigned int value) { value-=0x55555555U&(value>>1);unsigned int sum=(value&0x33333333U)+(0x33333333U&(value>>2));sum=(sum+(sum>>4))&0x0f0f0f0fU;sum+=sum>>8;return (sum+(sum>>16))&255; }
