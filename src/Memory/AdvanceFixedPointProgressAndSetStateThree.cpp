// Reviewed original ARM arithmetic and exact access widths. MMIO literals proven directly by original assembly.
#include <Memory/SafeAllocator.h>
extern "C" {void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);}
struct Bits020a0494{unsigned low:9;unsigned value:9;unsigned high:14;};
struct Bits020a0068{unsigned value:16;unsigned high:16;};
struct Bits020a017c{unsigned low:10;unsigned value:10;unsigned high:12;};
struct Bits020a0294{unsigned low:10;unsigned value:16;unsigned high:6;};
struct Bits020a0530{unsigned value:16;unsigned high:16;};
struct Bits020a0674{unsigned value:12;unsigned high:20;};
// Original: arm9/main @ 0x020DDFFC; symbol: func_020ddffc; size: 0x3C.
extern "C" void AdvanceFixedPointProgressAndSetStateThree(char* p){*(int*)(p+24)+=*(int*)(p+32);if(*(int*)(p+20)<0)++*(int*)(p+20);if(*(int*)(p+24)>=0x1000){*(int*)(p+24)=0x1000;p[4]=3;}}
