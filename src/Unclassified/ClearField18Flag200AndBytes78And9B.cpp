#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020890F4; symbol: func_020890f4; size: 0x1C.
extern "C" void ClearField18Flag200AndBytes78And9B(unsigned char* p) { *(unsigned int*)(p+0x18)&=~0x200;p[0x78]=0;p[0x9b]=0; }
