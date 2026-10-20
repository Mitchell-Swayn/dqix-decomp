#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020DC008; symbol: func_020dc008; size: 0x18.
extern "C" unsigned Graphics_ReadSubModeBits8To12(){return (*(volatile unsigned*)0x04001000&0x1f00)>>8;}
