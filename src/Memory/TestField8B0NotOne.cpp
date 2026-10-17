// Reviewed original ARM access widths. MMIO addresses are original hardware literals; data target has original relocation.
#include <Memory/SafeAllocator.h>
extern "C" {extern char data_02111818[];void ClearWordAndTwoBytes(void*);}struct TypeBits{unsigned low:24;unsigned value:2;unsigned high:6;};
// Original: arm9/main @ 0x02068768; symbol: func_02068768; size: 0x14.
extern "C" int TestField8B0NotOne(void*,char* p){return *(int*)(p+0x8b0)!=1;}
