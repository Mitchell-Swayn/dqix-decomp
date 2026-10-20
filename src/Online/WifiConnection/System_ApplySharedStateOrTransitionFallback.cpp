#include <globaldefs.h>
ARM
extern "C" void WirelessHost_StoreErrorUnlessTerminal(unsigned int);
extern "C" void WirelessHost_SetSystemState(int);
// Original: arm9/ov031 @ 0x02239A00; symbol: func_ov031_02239a00; size: 0x24.
extern "C" void System_ApplySharedStateOrTransitionFallback(unsigned short* p) { unsigned short value = p[1]; if (value) WirelessHost_StoreErrorUnlessTerminal(value); else WirelessHost_SetSystemState(1); }
