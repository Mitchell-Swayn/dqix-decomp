// Reviewed original ARM access widths. MMIO addresses are original hardware literals; data target has original relocation.
#include <Memory/SafeAllocator.h>
extern "C" {extern char data_02111818[];void ClearWordAndTwoBytes(void*);}struct TypeBits{unsigned low:24;unsigned value:2;unsigned high:6;};
// Original: arm9/main @ 0x020E2BAC; symbol: func_020e2bac; size: 0x18.
extern "C" unsigned Graphics_ReadSubDisplayMode(){return (*(volatile unsigned*)0x4001000&0xe000)>>13;}
