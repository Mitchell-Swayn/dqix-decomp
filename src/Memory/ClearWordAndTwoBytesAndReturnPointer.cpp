// Reviewed original ARM access widths. MMIO addresses are original hardware literals; data target has original relocation.
#include <Memory/SafeAllocator.h>
extern "C" {extern char data_02111818[];void ClearWordAndTwoBytes(void*);}struct TypeBits{unsigned low:24;unsigned value:2;unsigned high:6;};
// Original: arm9/main @ 0x020404AC; symbol: func_020404ac; size: 0x14.
extern "C" void* ClearWordAndTwoBytesAndReturnPointer(void* p){ClearWordAndTwoBytes(p);return p;}
