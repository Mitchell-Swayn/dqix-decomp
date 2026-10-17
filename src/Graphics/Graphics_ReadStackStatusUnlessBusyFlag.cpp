#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x020C5680; symbol: func_020c5680; size: 0x30.
int Graphics_ReadStackStatusUnlessBusyFlag(unsigned int *p){if((*(volatile unsigned int *)0x04000600&0x4000)==0){*p=(*(volatile unsigned int *)0x04000600&0x2000)>>13;return 0;}return -1;}
}
