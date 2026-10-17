#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02161BEC; symbol: func_ov000_02161bec; size: 0x20.
extern "C" void Util_IncrementByteCounterWrapAt18(unsigned char* p) { unsigned int n = p[0] + 1; p[0] = n; if ((n & 0xff) >= 0x12) p[0] = 1; }
