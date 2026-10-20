#include <globaldefs.h>
ARM
extern "C" unsigned int Network_IsAddressWithinConfiguredPrefix(unsigned int);
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02200730; symbol: Unclassified_GetValidatedValueOrGlobalDefault; size: 0x24.
// Returns the input when the validation helper returns nonzero; otherwise returns the global word at offset +0x2C.
extern "C" unsigned int Network_SelectDestinationOrDefaultGateway(unsigned int value) {
    if (Network_IsAddressWithinConfiguredPrefix(value) == 0) value = NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[0xb];
    return value;
}
