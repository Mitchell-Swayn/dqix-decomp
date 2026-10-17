#include <globaldefs.h>
// Original: arm9/main @ 0x020E2A88; symbol: func_020e2a88; size: 0x28.
extern "C" void Graphics_SetSubWindowOneMaskAndEffectFlag(unsigned mode, int enabled) { unsigned value=*(volatile unsigned short*)0x04001048 & ~0x3f00; value |= mode << 8; if(enabled) value |=0x2000; *(volatile unsigned short*)0x04001048=value; }
