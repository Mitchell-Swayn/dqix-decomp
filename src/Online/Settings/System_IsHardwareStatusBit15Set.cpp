#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0222AE94; symbol: func_ov031_0222ae94; size: 0x20.
extern "C" unsigned int System_IsHardwareStatusBit15Set(void) { int v = *(volatile unsigned short*)0x027fffa8 & 0x8000; return (v >> 15) != 0; }
