#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020889B4; symbol: func_020889b4; size: 0x1C.
void ClearField14Flag8000000AndBytes62And85(char *p){*(unsigned int *)(p+20)&=~0x8000000;p[0x62]=0;p[0x85]=0;}
}
