#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x0207F100; symbol: func_0207f100; size: 0x2C.
char *DisplayLayout_GetGroupByIndex(unsigned int *p,int i){if(i<0)return 0;if(*(short *)(p+1)<=i)return 0;return (char *)p[0]+(short)i*24;}
}
