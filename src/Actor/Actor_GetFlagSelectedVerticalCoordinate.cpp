#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02041654; symbol: func_02041654; size: 0x18.
unsigned int Actor_GetFlagSelectedVerticalCoordinate(char *p){if(*(unsigned short *)(p+0x2d0)&2)return *(unsigned int *)(p+0x2d4);return *(unsigned int *)(p+0x54);}
}
