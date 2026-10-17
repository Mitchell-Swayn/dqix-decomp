// Reviewed original ARM access widths. MMIO addresses are original hardware literals; data target has original relocation.
#include <Memory/SafeAllocator.h>
extern "C" {extern char data_02111818[];void ClearWordAndTwoBytes(void*);}struct TypeBits{unsigned low:24;unsigned value:2;unsigned high:6;};
// Original: arm9/main @ 0x02068BC4; symbol: func_02068bc4; size: 0x18.
extern "C" int Object_TestWord8BCOutsideZeroOrOne(void*,char* p){int v=*(int*)(p+0x8bc);return v!=0&&v!=1;}
