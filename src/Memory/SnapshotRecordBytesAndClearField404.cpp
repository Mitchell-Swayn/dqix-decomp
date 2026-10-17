// Reviewed original ARM arithmetic and exact access widths. MMIO literals proven directly by original assembly.
#include <Memory/SafeAllocator.h>
extern "C" {void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);}
struct Bits020a0494{unsigned low:9;unsigned value:9;unsigned high:14;};
struct Bits020a0068{unsigned value:16;unsigned high:16;};
struct Bits020a017c{unsigned low:10;unsigned value:10;unsigned high:12;};
struct Bits020a0294{unsigned low:10;unsigned value:16;unsigned high:6;};
struct Bits020a0530{unsigned value:16;unsigned high:16;};
struct Bits020a0674{unsigned value:12;unsigned high:20;};
// Original: arm9/main @ 0x0206E70C; symbol: func_0206e70c; size: 0x3C.
extern "C" void SnapshotRecordBytesAndClearField404(char* p){memcpy(p+0x334,p,0xce);*(int*)(p+0x404)=0;memcpy(p+0x40c,p+0x323,15);}
