#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d18; symbol: data_ov031_02290d18.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[];
extern "C" unsigned int WM_GetSharedDataAddress(void *, void *, unsigned int);
// Original: arm9/ov031 @ 0x0223A288; symbol: System_ResolvePacketExchangeEntry; size: 0x28.
// Forwards the input value and two pointers at offsets 0x13E0 and 0x1C00 from the global packet object to the resolver.
extern "C" unsigned int System_ResolvePacketExchangeEntry(unsigned int value) {
    unsigned char *base = (unsigned char *)WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[1];
    return WM_GetSharedDataAddress(base + 0x13e0, base + 0x1c00, value);
}
