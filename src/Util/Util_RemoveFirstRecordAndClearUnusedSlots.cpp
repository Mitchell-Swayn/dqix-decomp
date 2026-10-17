#include <globaldefs.h>
ARM
struct Record { unsigned char bytes[52]; };
extern "C" { void ClearRecordAndInitializeInvalidIndices(unsigned char*); void MI_CpuCopy8(const void*,void*,unsigned); }
// Original: arm9/main @ 0x020945AC; symbol: func_020945ac; size: 0xA8.
extern "C" void Util_RemoveFirstRecordAndClearUnusedSlots(unsigned char* p,int remaining) {
 int count=*(signed char*)(p+0x3cb);
 if(count<=0) return;
 remaining=count-1;
 for(int i=0;i<remaining;++i) MI_CpuCopy8(&((Record*)p)[i+1],&((Record*)p)[i],52);
 for(;remaining<8;++remaining) ClearRecordAndInitializeInvalidIndices((unsigned char*)&((Record*)p)[remaining]);
 if(*(signed char*)(p+0x3cb)>0) --*(signed char*)(p+0x3cb);
 if(*(signed char*)(p+0x3cb)>0) { p[0x3cd]|=1; p[0x3cd]&=~4; }
 else p[0x3cd]&=~4;
}
