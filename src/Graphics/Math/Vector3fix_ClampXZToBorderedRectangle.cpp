// Reviewed original ARM arithmetic and exact access widths. MMIO literals proven directly by original assembly.
#include <Memory/SafeAllocator.h>
extern "C" {void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);}
struct Bits020a0494{unsigned low:9;unsigned value:9;unsigned high:14;};
struct Bits020a0068{unsigned value:16;unsigned high:16;};
struct Bits020a017c{unsigned low:10;unsigned value:10;unsigned high:12;};
struct Bits020a0294{unsigned low:10;unsigned value:16;unsigned high:6;};
struct Bits020a0530{unsigned value:16;unsigned high:16;};
struct Bits020a0674{unsigned value:12;unsigned high:20;};
// Original: arm9/main @ 0x0202630C; symbol: func_0202630c; size: 0x3C.
extern "C" void Vector3fix_ClampXZToBorderedRectangle(void*,int* v,int border){if(v[0]<=border)v[0]=border;if(v[0]>=0x100000-border)v[0]=0x100000-border;if(v[2]<=border)v[2]=border;if(v[2]>=0xc0000-border)v[2]=0xc0000-border;}
