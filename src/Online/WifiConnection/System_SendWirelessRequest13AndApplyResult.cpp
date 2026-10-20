#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d18; symbol: data_ov031_02290d18.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[];
extern "C" void WirelessHost_SetSystemState(int);
extern "C" ARM unsigned WirelessCommand_InvokeRequestWithFullMaskAndModeTwo(unsigned, unsigned);
extern "C" void WirelessHost_StoreErrorUnlessTerminal(unsigned);
// Original: arm9/ov031 @ 0x022398E8; symbol: func_ov031_022398e8; size: 0x3C.
extern "C" int System_SendWirelessRequest13AndApplyResult(void) {
    WirelessHost_SetSystemState(6);
    void *base = *(void **)(WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage + 4);
    unsigned result = WirelessCommand_InvokeRequestWithFullMaskAndModeTwo((unsigned)((char *)base + 0x1E00), 0xD);
    if (result == 2) return 1;
    WirelessHost_StoreErrorUnlessTerminal(result);
    return 0;
}
