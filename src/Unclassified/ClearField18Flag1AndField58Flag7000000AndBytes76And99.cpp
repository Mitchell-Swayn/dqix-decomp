#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020880E4; symbol: func_020880e4; size: 0x28.
void ClearField18Flag1AndField58Flag7000000AndBytes76And99(char *p){*(unsigned int *)(p+0x18)&=~0x1;*(unsigned int *)(p+0x58)&=~0x7000000;*(unsigned char *)(p+0x76)=0;*(unsigned char *)(p+0x99)=0;}
}
