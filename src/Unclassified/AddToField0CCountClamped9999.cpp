#include <globaldefs.h>
ARM
struct Count{unsigned low:14;unsigned value:14;unsigned high:4;};
// Original: arm9/main @ 0x020A0388; symbol: func_020a0388; size: 0x3C.
extern "C" void AddToField0CCountClamped9999(unsigned char* p,unsigned delta){Count* h=(Count*)(p+12);unsigned sum=h->value+delta;if(sum>9999)sum=9999;h->value=sum;}
