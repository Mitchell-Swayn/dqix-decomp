#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d20; symbol: data_ov031_02290d20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage;
extern "C" void Network_ResetAndSeedCommandState();
extern "C" void WirelessHost_ResetParentSessionAndInitialize();
// Original: arm9/ov031 @ 0x0223A718; symbol: Network_ResetCommandForAcceptedStates; size: 0x48.
// For shared states 1, 0x1a, or 0x1d, resets command state and transitions to state 2.
extern "C" int Network_ResetCommandForAcceptedStates() {
    unsigned char state = (*(unsigned char**)((char*)&Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage))[0xa90];
    if (state != 1 && state != 0x1a && state != 0x1d) return 0;
    Network_ResetAndSeedCommandState();
    WirelessHost_ResetParentSessionAndInitialize();
    (*(unsigned char**)((char*)&Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage))[0xa90] = 2;
    return 1;
}
