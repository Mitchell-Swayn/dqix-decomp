// Reviewed original ARM access widths. MMIO addresses are original hardware literals; data target has original relocation.
#include <Memory/SafeAllocator.h>
extern "C" {extern char data_02111818[];void ClearWordAndTwoBytes(void*);}struct TypeBits{unsigned low:24;unsigned value:2;unsigned high:6;};
// Original: arm9/main @ 0x0204A6B4; symbol: func_0204a6b4; size: 0x1C.
extern "C" void MainBackground1_SetPriority(unsigned v){volatile unsigned short* p=(volatile unsigned short*)0x400000a;*p=(*p&~3)|v;}
