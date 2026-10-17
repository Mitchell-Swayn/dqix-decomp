#include <globaldefs.h>
ARM
struct Count{unsigned low:24;unsigned high:8;};
// Original: arm9/main @ 0x020A07E0; symbol: func_020a07e0; size: 0x30.
extern "C" void AddToField3CLowCounterClampedFFFFFF(unsigned char* p,unsigned delta){Count* h=(Count*)(p+60);unsigned sum=h->low+delta;if(sum>0xffffff)sum=0xffffff;h->low=sum;}
