#include <globaldefs.h>
ARM
extern "C" void WirelessHost_StoreErrorUnlessTerminal(unsigned int);
extern "C" void WirelessHost_SetSystemState(int);
extern "C" int WirelessHost_SubmitProvidedModePayload(void);
extern "C" int WirelessHost_StartParentAndResetConnectedPeers(void);
// Original data: arm9/ov031 @ 0x2290d18; symbol: data_ov031_02290d18.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02239448; symbol: func_ov031_02239448; size: 0x6C.
extern "C" void WirelessHost_HandleParentParameterCompletion(void *state) {
    unsigned short value = *(unsigned short *)((char *)state + 2);
    if (value != 0) {
        WirelessHost_StoreErrorUnlessTerminal(value);
        WirelessHost_SetSystemState(9);
        return;
    }
    unsigned char *object = *(unsigned char **)(WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage + 4);
    if (*(int *)(object + 0x1000 + 0x3ac) != 0) {
        if (WirelessHost_SubmitProvidedModePayload() == 0) WirelessHost_SetSystemState(9);
        return;
    }
    if (WirelessHost_StartParentAndResetConnectedPeers() == 0) WirelessHost_SetSystemState(9);
}
