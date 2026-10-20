#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void VRAMBankConfig_Initialize(void*,unsigned);
// Original: arm9/main @ 0x020979F4; symbol: func_020979f4; size: 0x10.
extern "C" void VRAMBankConfig_Reset(void* p){VRAMBankConfig_Initialize(p,0);}
