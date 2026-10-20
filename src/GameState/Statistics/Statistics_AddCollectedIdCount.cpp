#include <globaldefs.h>
ARM
struct Count{unsigned low:9;unsigned high:23;};
// Original: arm9/main @ 0x020A03C4; symbol: func_020a03c4; size: 0x34.
extern "C" void Statistics_AddCollectedIdCount(unsigned char* p,unsigned delta){Count* h=(Count*)(p+16);unsigned sum=h->low+delta;if(sum>500)sum=500;h->low=sum;}
