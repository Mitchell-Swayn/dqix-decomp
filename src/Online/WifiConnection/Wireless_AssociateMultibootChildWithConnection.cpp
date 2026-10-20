#include <globaldefs.h>
ARM
extern "C" unsigned Network_FindEnabledAddressValue(unsigned value);
extern "C" unsigned Multiboot_GetConnectedChildRecord(void);
// Original data: arm9/ov031 @ 0x2290d20; symbol: data_ov031_02290d20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char *Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223B040; symbol: func_ov031_0223b040; size: 0x3C.
extern "C" int Wireless_AssociateMultibootChildWithConnection(void *descriptor) {
    unsigned index = Network_FindEnabledAddressValue((unsigned)((char *)descriptor + 0x0a));
    if (!index) return 0;
    unsigned resource = Multiboot_GetConnectedChildRecord();
    *(unsigned *)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage + 0xaa0 + (index - 1) * 4) = resource;
    return 1;
}
