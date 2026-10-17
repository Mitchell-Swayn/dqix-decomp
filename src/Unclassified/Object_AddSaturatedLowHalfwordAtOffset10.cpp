#include <globaldefs.h>
ARM
struct Half{unsigned low:16;unsigned high:16;};
// Original: arm9/main @ 0x020A00D4; symbol: func_020a00d4; size: 0x3C.
extern "C" void Object_AddSaturatedLowHalfwordAtOffset10(unsigned char* p,unsigned delta){Half* h=(Half*)(p+16);unsigned sum=h->low+delta;if(sum>65535)sum=65535;h->low=sum;}
