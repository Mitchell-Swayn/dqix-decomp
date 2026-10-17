#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020D771C; symbol: func_020d771c; size: 0x20.
void Object_MergeMiddleEightBitsIntoHalfwordA26(char *p){unsigned short a=*(unsigned short *)(p+0xa24)&0xff0;*(unsigned short *)(p+0xa26)|=a;}
}
