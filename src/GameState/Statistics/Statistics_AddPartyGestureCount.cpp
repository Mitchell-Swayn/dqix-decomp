#include <globaldefs.h>
ARM
struct Count{unsigned low:12;unsigned value:10;unsigned high:10;};
// Original: arm9/main @ 0x020A06B0; symbol: func_020a06b0; size: 0x3C.
extern "C" void Statistics_AddPartyGestureCount(unsigned char* p,unsigned delta){Count* h=(Count*)(p+40);unsigned sum=h->value+delta;if(sum>1023)sum=1023;h->value=sum;}
