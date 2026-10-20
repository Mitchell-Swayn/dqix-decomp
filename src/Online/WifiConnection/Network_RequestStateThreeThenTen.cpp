#include <globaldefs.h>
ARM
extern "C" void WirelessHost_SetSystemState(int);
extern "C" int WirelessCommand_InvokeFourArgumentRequestWithZeroMode(void*, unsigned, void*);
extern "C" void WirelessHost_StoreErrorUnlessTerminal(unsigned);
extern "C" void WirelessHost_HandleInitializationAndInstallIndicationCallback(void);
// Original data: arm9/ov031 @ 0x2290d18; symbol: data_ov031_02290d18.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223A060; symbol: func_ov031_0223a060; size: 0x4C.
extern "C" int Network_RequestStateThreeThenTen(void) {
    WirelessHost_SetSystemState(3);
    void* context = *(void**)((char*)&WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage + 4);
    int result = WirelessCommand_InvokeFourArgumentRequestWithZeroMode((char*)context + 0x80, (unsigned)&WirelessHost_HandleInitializationAndInstallIndicationCallback, (void*)2);
    if (result == 2) return 1;
    WirelessHost_StoreErrorUnlessTerminal((unsigned)result);
    WirelessHost_SetSystemState(10);
    return 0;
}
