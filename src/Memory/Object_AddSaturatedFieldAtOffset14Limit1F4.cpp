// Reviewed original ARM arithmetic and exact access widths. MMIO literals proven directly by original assembly.
#include <Memory/SafeAllocator.h>
extern "C" {void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);}
struct Bits020a0494{unsigned low:9;unsigned value:9;unsigned high:14;};
struct Bits020a0068{unsigned value:16;unsigned high:16;};
struct Bits020a017c{unsigned low:10;unsigned value:10;unsigned high:12;};
struct Bits020a0294{unsigned low:10;unsigned value:16;unsigned high:6;};
struct Bits020a0530{unsigned value:16;unsigned high:16;};
struct Bits020a0674{unsigned value:12;unsigned high:20;};
// Original: arm9/main @ 0x020A0494; symbol: func_020a0494; size: 0x34.
extern "C" void Object_AddSaturatedFieldAtOffset14Limit1F4(char* p,unsigned add){Bits020a0494* q=(Bits020a0494*)(p+20);unsigned v=q->value+add;if(v>500)v=500;q->value=v;}
