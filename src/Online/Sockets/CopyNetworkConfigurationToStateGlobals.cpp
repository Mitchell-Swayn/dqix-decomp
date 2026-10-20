#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x22496a4; symbol: data_ov031_022496a4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int* NetworkCleanupSocketStack_UnknownRoleInitializedBytes;
// Original data: arm9/ov031 @ 0x224c9d0; symbol: data_ov031_0224c9d0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int NetworkCleanupSocketStack_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x224c99c; symbol: data_ov031_0224c99c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int CopyNetworkConfigurationToStateGlobals_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x224c9ac; symbol: data_ov031_0224c9ac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int CopyNetworkConfigurationToStateGlobals_UnknownRoleZeroInitializedStorage_Variant2;
// Original data: arm9/ov031 @ 0x224c9e0; symbol: data_ov031_0224c9e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int NetworkSetDnsServers_UnknownRoleZeroInitializedStorage[2];
// Original data: arm9/ov031 @ 0x224e1c0; symbol: data_ov031_0224e1c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int NetworkInitializeSocketStack_UnknownRoleZeroInitializedStorage[3];
// Original: arm9/ov031 @ 0x02204F94; symbol: CopyNetworkConfigurationToStateGlobals; size: 0x6C.
// Copies five configured words into overlay state globals and sets bit 1 in shared state.
extern "C" void CopyNetworkConfigurationToStateGlobals() {
    unsigned int* p = NetworkCleanupSocketStack_UnknownRoleInitializedBytes;
    NetworkCleanupSocketStack_UnknownRoleZeroInitializedStorage = p[1];
    CopyNetworkConfigurationToStateGlobals_UnknownRoleZeroInitializedStorage = p[2];
    CopyNetworkConfigurationToStateGlobals_UnknownRoleZeroInitializedStorage_Variant2 = p[3];
    NetworkSetDnsServers_UnknownRoleZeroInitializedStorage[0] = p[4];
    NetworkSetDnsServers_UnknownRoleZeroInitializedStorage[1] = p[5];
    NetworkInitializeSocketStack_UnknownRoleZeroInitializedStorage[2] |= 2;
}
