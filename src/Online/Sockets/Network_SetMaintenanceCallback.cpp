#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02200524; symbol: func_ov031_02200524; size: 0x10.
extern "C" void Network_SetMaintenanceCallback(unsigned value) {
    *(unsigned *)((char *)&NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage + 0x3c) = value;
}
