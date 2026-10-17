// Reviewed original ARM access widths. MMIO addresses are original hardware literals; data target has original relocation.
#include <Memory/SafeAllocator.h>
extern "C" {extern char data_02111818[];void ClearWordAndTwoBytes(void*);}struct TypeBits{unsigned low:24;unsigned value:2;unsigned high:6;};
// Original: arm9/main @ 0x020688CC; symbol: func_020688cc; size: 0x18.
extern "C" int IsByteField19D5Zero(void*,unsigned char* p){return p[0x19d5]==0;}
