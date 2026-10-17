// Reviewed original ARM access widths. MMIO addresses are original hardware literals; data target has original relocation.
#include <Memory/SafeAllocator.h>
extern "C" {extern char data_02111818[];void ClearWordAndTwoBytes(void*);}struct TypeBits{unsigned low:24;unsigned value:2;unsigned high:6;};
// Original: arm9/main @ 0x02068824; symbol: func_02068824; size: 0x1C.
extern "C" unsigned ReadTypeBitsFromOptionalPointerAtOffset18(void*,char* p){char* q=*(char**)(p+24);return q?((TypeBits*)(q+8))->value:0;}
