#include <globaldefs.h>
ARM
struct Count{unsigned low:24;unsigned high:8;};
// Original: arm9/main @ 0x020A0750; symbol: func_020a0750; size: 0x30.
extern "C" void AddToField30LowCounterClampedFFFFFF(unsigned char* p,unsigned delta){Count* h=(Count*)(p+48);unsigned sum=h->low+delta;if(sum>0xffffff)sum=0xffffff;h->low=sum;}
