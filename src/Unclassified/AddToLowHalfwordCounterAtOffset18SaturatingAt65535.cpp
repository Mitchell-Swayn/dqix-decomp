#include <globaldefs.h>
ARM
struct Half{unsigned low:16;unsigned high:16;};
// Original: arm9/main @ 0x020A01EC; symbol: func_020a01ec; size: 0x3C.
extern "C" void AddToLowHalfwordCounterAtOffset18SaturatingAt65535(unsigned char* p,unsigned delta){Half* h=(Half*)(p+24);unsigned sum=h->low+delta;if(sum>65535)sum=65535;h->low=sum;}
