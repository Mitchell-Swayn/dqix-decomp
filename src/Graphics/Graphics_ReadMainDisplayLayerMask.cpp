// Reviewed original ARM access widths. MMIO addresses are original hardware literals; data target has original relocation.
#include <Memory/SafeAllocator.h>
extern "C" {extern char data_02111818[];void ClearWordAndTwoBytes(void*);}struct TypeBits{unsigned low:24;unsigned value:2;unsigned high:6;};
// Original: arm9/main @ 0x020DAF6C; symbol: func_020daf6c; size: 0x14.
extern "C" unsigned Graphics_ReadMainDisplayLayerMask(){return (*(volatile unsigned*)0x4000000&0x1f00)>>8;}
