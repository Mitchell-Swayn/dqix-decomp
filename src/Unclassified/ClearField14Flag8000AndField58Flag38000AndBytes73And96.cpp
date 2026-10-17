#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02087CFC; symbol: func_02087cfc; size: 0x28.
extern "C" void ClearField14Flag8000AndField58Flag38000AndBytes73And96(unsigned char* p) { *(unsigned int*)(p+0x14)&=~0x8000; *(unsigned int*)(p+0x58)&=~0x38000;p[0x73]=0;p[0x96]=0; }
