#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x020C383C; symbol: func_020c383c; size: 0x28.
void Graphics_SetDisplayStatusVCountCompare(unsigned int v){*(volatile unsigned short *)0x04000004=(*(volatile unsigned short *)0x04000004&63)|((v<<24)>>16)|((int)(v&0x100)>>1);}
}
