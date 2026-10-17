#include <globaldefs.h>
ARM
extern "C" void FreeSharedAllocationAndClearFlagWithInterruptMask(void** p);
extern "C" void* data_ov031_02250bf4;
// Original: arm9/ov031 @ 0x02223984; symbol: func_ov031_02223984; size: 0x14.
extern "C" void func_ov031_02223984(void) { FreeSharedAllocationAndClearFlagWithInterruptMask(&data_ov031_02250bf4); }
