#include <globaldefs.h>
ARM
// Original: arm9/ov015 @ 0x02190C2C; symbol: func_ov015_02190c2c; size: 0x6C.
// Tests owner mode in inclusive range15..32; original uses18-entry switch table.
extern "C" int UI_IsOwnerModeInResourceRange(unsigned char* self) {switch(*(int*)(self+0x1a4)){
case 15:
case 16:
case 17:
case 18:
case 19:
case 20:
case 21:
case 22:
case 23:
case 24:
case 25:
case 26:
case 27:
case 28:
case 29:
case 30:
case 31:
case 32:
return 1;default:return 0;}}
