#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2111304; symbol: data_02111304.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov031 @ 0x02207D60; symbol: Unclassified_WriteTwoNestedContextWords; size: 0x28.
// Follows the global context pointer chain and, when both nested pointers are nonnull, writes the two inputs at target offsets +0x814/+0x818.
extern "C" void Ssl_SetCurrentTrustedCertificateList(unsigned int first, unsigned int second) {
    unsigned char *base = (unsigned char *)OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[1];
    unsigned char *record = *(unsigned char **)(base + 0xa4);
    if (record) {
        unsigned char *target = *(unsigned char **)(record + 0xc);
        if (target) {
            *(unsigned int *)(target + 0x814) = first;
            *(unsigned int *)(target + 0x818) = second;
        }
    }
}
