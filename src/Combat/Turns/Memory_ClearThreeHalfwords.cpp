#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02163454; symbol: func_ov000_02163454; size: 0x18.
extern "C" void Memory_ClearThreeHalfwords(char* p) { *(unsigned short*)(p + 0x6e44) = 0; *(unsigned short*)(p + 0x6e46) = 0; *(unsigned short*)(p + 0x6e48) = 0; }
