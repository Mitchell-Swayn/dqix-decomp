#include <globaldefs.h>
ARM
struct Half{unsigned low:16;unsigned high:16;};
// Original: arm9/main @ 0x020A059C; symbol: func_020a059c; size: 0x3C.
extern "C" void Statistics_AddQuestMenuSuccessCount(unsigned char* p,unsigned delta){Half* h=(Half*)(p+32);unsigned sum=h->low+delta;if(sum>65535)sum=65535;h->low=sum;}
