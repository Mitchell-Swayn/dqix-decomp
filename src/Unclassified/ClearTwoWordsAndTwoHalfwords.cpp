#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02071BE8; symbol: func_02071be8; size: 0x18.
void ClearTwoWordsAndTwoHalfwords(unsigned int *p){p[0]=0;p[1]=0;*(short *)(p+2)=0;*(short *)((char *)p+10)=0;}
}
