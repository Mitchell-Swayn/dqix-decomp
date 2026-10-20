#include <globaldefs.h>
ARM
extern "C" int Network_IsAddressWithinConfiguredPrefix(unsigned int);
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov031 @ 0x02200754; symbol: func_ov031_02200754; size: 0x3C.
extern "C" int Network_IsAddressWithinConfiguredHostRange(unsigned int value) {
    int result = 0;
    if (Network_IsAddressWithinConfiguredPrefix(value)) {
        unsigned int required = ~*(unsigned int *)(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage + 0x1c);
        if ((required & value) == required)
            result = 1;
    }
    return result;
}
