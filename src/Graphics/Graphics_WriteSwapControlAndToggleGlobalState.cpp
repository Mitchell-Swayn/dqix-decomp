#include <globaldefs.h>
extern "C" {
extern unsigned char data_0214e4a0[];
// Original: arm9/main @ 0x020D86D0; symbol: func_020d86d0; size: 0x34.
void Graphics_WriteSwapControlAndToggleGlobalState(unsigned int a,unsigned int b){*(volatile unsigned int *)0x04000540=a|(b<<1);data_0214e4a0[0]=data_0214e4a0[0]==0?1:0;}
}
