// Reviewed original ARM access widths. MMIO addresses are original hardware literals; data target has original relocation.
#include <Memory/SafeAllocator.h>
extern "C" {extern char data_02111818[];void ClearWordAndTwoBytes(void*);}struct TypeBits{unsigned low:24;unsigned value:2;unsigned high:6;};
// Original: arm9/main @ 0x020CF854; symbol: func_020cf854; size: 0x10.
extern "C" void IPC_StoreGlobalReplyValue(unsigned v){((unsigned*)data_02111818)[11]=v;}
