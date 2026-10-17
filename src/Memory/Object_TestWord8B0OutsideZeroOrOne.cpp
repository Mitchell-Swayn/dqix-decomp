// Reviewed original ARM access widths. MMIO addresses are original hardware literals; data target has original relocation.
#include <Memory/SafeAllocator.h>
extern "C" {extern char data_02111818[];void ClearWordAndTwoBytes(void*);}struct TypeBits{unsigned low:24;unsigned value:2;unsigned high:6;};
// Original: arm9/main @ 0x02068B7C; symbol: func_02068b7c; size: 0x18.
extern "C" int Object_TestWord8B0OutsideZeroOrOne(void*,char* p){int v=*(int*)(p+0x8b0);return v!=0&&v!=1;}
