#include <globaldefs.h>
ARM
struct Half{unsigned low:16;unsigned high:16;};
// Original: arm9/main @ 0x020A05D8; symbol: func_020a05d8; size: 0x30.
extern "C" void Object_AddSaturatedHighHalfwordAtOffset20(unsigned char* p,unsigned delta){Half* h=(Half*)(p+32);unsigned sum=h->high+delta;if(sum>65535)sum=65535;h->high=sum;}
