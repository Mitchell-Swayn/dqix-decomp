#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021B1454; symbol: func_ov017_021b1454; size: 0x18.
extern "C" void Util_ClearBitAtOffsetA(unsigned char* p, unsigned int bit) { p[0xa] = p[0xa] & ~(1u << bit); }
