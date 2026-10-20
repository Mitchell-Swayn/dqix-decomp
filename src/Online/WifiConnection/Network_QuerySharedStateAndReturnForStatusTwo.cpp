#include <globaldefs.h>
ARM
extern "C" int WM_EndKeySharing(void *);
extern "C" void WirelessHost_StoreErrorUnlessTerminal(unsigned value);
// Original data: arm9/ov031 @ 0x2290d18; symbol: data_ov031_02290d18.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned int WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02239924; symbol: Network_QuerySharedStateAndReturnForStatusTwo; size: 0x30.
// Queries the object at global +0x1e00; returns true for status 2, otherwise updates shared state and returns false.
extern "C" int Network_QuerySharedStateAndReturnForStatusTwo(void) {
    int result = WM_EndKeySharing((void *)(*(unsigned int *)(WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage + 1) + 0x1e00));
    if (result == 2) return 1;
    WirelessHost_StoreErrorUnlessTerminal(result);
    return 0;
}
