#include <globaldefs.h>
ARM

extern "C" void Ssl_DeriveMasterSecretDigestBlock(void *, const void *, void *);
extern "C" void MI_CpuCopy8(const void *, void *, unsigned);
// Original data: arm9/ov031 @ 0x2249748; symbol: data_ov031_02249748.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 41000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemBuildAndCopyThreeContextRecords_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x224974c; symbol: data_ov031_0224974c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 42420000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemBuildAndCopyThreeContextRecords_UnknownRoleInitializedBytes_Variant2[];
extern "C" unsigned char System_BuildAndCopyThreeContextRecords_TextCCC[];

// Original: arm9/ov031 @ 0x02208EF0; symbol: func_ov031_02208ef0; size: 0x60.
extern "C" void System_BuildAndCopyThreeContextRecords(void *destination) {
    unsigned char records[0x30];
    Ssl_DeriveMasterSecretDigestBlock(records, SystemBuildAndCopyThreeContextRecords_UnknownRoleInitializedBytes, destination);
    Ssl_DeriveMasterSecretDigestBlock(records + 0x10, SystemBuildAndCopyThreeContextRecords_UnknownRoleInitializedBytes_Variant2, destination);
    Ssl_DeriveMasterSecretDigestBlock(records + 0x20, System_BuildAndCopyThreeContextRecords_TextCCC, destination);
    MI_CpuCopy8(records, destination, 0x30);
}
