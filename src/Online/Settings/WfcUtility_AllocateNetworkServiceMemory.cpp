#include <globaldefs.h>
ARM
extern "C" void Memory_AllocateZeroedBlock(void *, unsigned int);
// Original: arm9/ov031 @ 0x02226FC8; symbol: func_ov031_02226fc8; size: 0x10.
extern "C" void WfcUtility_AllocateNetworkServiceMemory(void *p) { Memory_AllocateZeroedBlock(p, 0x20); }
