#include <globaldefs.h>
ARM
struct Count{unsigned low:22;unsigned high:10;};
// Original: arm9/main @ 0x020A06EC; symbol: func_020a06ec; size: 0x34.
extern "C" void Statistics_AddVocationChangeCount(unsigned char* p,unsigned delta){Count* h=(Count*)(p+40);unsigned sum=h->high+delta;if(sum>1023)sum=1023;h->high=sum;}
