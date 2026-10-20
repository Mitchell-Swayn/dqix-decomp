#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020DC020; symbol: func_020dc020; size: 0x14.
extern "C" unsigned Graphics_ReadMainDisplayPlanes(){return (*(volatile unsigned*)0x04000000&0x1f00)>>8;}
