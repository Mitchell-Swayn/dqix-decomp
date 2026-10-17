#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x0205B20C; symbol: func_0205b20c; size: 0x14.
void ClearTwoWordsAndFollowingByte(unsigned int *p){p[0]=0;p[1]=0;*(unsigned char *)(p+2)=0;}
}
