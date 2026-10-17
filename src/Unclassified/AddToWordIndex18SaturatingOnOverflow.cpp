#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020A0858; symbol: func_020a0858; size: 0x18.
void AddToWordIndex18SaturatingOnOverflow(unsigned int *p,unsigned int v){unsigned int old=p[18];v+=old;if(v<old)v=-1;p[18]=v;}
}
