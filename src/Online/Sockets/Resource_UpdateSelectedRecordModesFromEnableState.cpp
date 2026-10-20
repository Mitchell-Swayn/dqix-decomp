#include <globaldefs.h>
ARM
extern "C" unsigned short Network_SelectUnusedEphemeralPort(void);
// Original data: arm9/main @ 0x2111304; symbol: data_02111304.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[];
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov031 @ 0x022031BC; symbol: Resource_UpdateSelectedRecordModesFromEnableState; size: 0x60.
// Updates the resource-selected record's two halfwords and two mode words, substitutes the global +0x50 value for mode 0x7f000001, and sets its final halfword from enabled or the helper result.
extern "C" void Resource_UpdateSelectedRecordModesFromEnableState(int enabled, unsigned short value, unsigned int mode) {
    unsigned char *target = *(unsigned char **)(*(unsigned char **)(OSInitThread_UnknownRoleZeroInitializedStorage_Variant2 + 4) + 0xa4);
    if (target == 0) return;
    if (mode == 0x7f000001)
        mode = *(unsigned int *)(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage + 0x50);
    *(unsigned short *)(target + 0x1a) = value;
    *(unsigned short *)(target + 0x18) = *(unsigned short *)(target + 0x1a);
    *(unsigned int *)(target + 0x20) = mode;
    *(unsigned int *)(target + 0x1c) = mode;
    if (enabled != 0)
        *(unsigned short *)(target + 0xa) = (unsigned short)enabled;
    else
        *(unsigned short *)(target + 0xa) = Network_SelectUnusedEphemeralPort();
}
