#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x020888C4; symbol: func_020888c4; size: 0x1C.
void ClearField14Flag100AndBytes60And83(char *p){*(unsigned int *)(p+0x14)&=~0x100;*(unsigned char *)(p+0x60)=0;*(unsigned char *)(p+0x83)=0;}
}
