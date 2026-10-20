#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov031 @ 0x022006F0; symbol: func_ov031_022006f0; size: 0x40.
extern "C" int Network_IsAddressWithinConfiguredPrefix(unsigned int value) {
    int result = 1;
    if (value != 0xffffffff && value != 0x7f000001) {
        unsigned int mask = *(unsigned int *)(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage + 0x1c);
        if ((value & mask) != (*(unsigned int *)(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage + 0x50) & mask))
            result = 0;
    }
    return result;
}
