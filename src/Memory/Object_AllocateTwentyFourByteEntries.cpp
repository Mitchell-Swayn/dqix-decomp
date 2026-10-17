// Reviewed original ARM arithmetic and exact access widths. MMIO literals proven directly by original assembly.
#include <Memory/SafeAllocator.h>
extern "C" {void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);}
struct Bits020a0494{unsigned low:9;unsigned value:9;unsigned high:14;};
struct Bits020a0068{unsigned value:16;unsigned high:16;};
struct Bits020a017c{unsigned low:10;unsigned value:10;unsigned high:12;};
struct Bits020a0294{unsigned low:10;unsigned value:16;unsigned high:6;};
struct Bits020a0530{unsigned value:16;unsigned high:16;};
struct Bits020a0674{unsigned value:12;unsigned high:20;};
// Original: arm9/main @ 0x0207EFDC; symbol: func_0207efdc; size: 0x3C.
extern "C" void Object_AllocateTwentyFourByteEntries(char* p,SafeAllocator* a,int count){if(!a||count<0)return;*(short*)(p+4)=0;*(short*)(p+6)=count;*(void**)p=a->Allocate(count*24);}
