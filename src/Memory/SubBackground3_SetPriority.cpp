// Reviewed original ARM access widths. MMIO addresses are original hardware literals; data target has original relocation.
#include <Memory/SafeAllocator.h>
extern "C" {extern char data_02111818[];void ClearWordAndTwoBytes(void*);}struct TypeBits{unsigned low:24;unsigned value:2;unsigned high:6;};
// Original: arm9/main @ 0x0204A60C; symbol: func_0204a60c; size: 0x1C.
extern "C" void SubBackground3_SetPriority(unsigned v){volatile unsigned short* p=(volatile unsigned short*)0x400100e;*p=(*p&~3)|v;}
