#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x21833e8; symbol: data_ov000_021833e8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000020000000300000001000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char MemoryCopyConstantBlock16_UnknownRoleInitializedBytes[];
extern "C" void *memcpy(void *, const void *, unsigned int);
// Original: arm9/ov000 @ 0x02174DA4; symbol: func_ov000_02174da4; size: 0x1C.
extern "C" void Memory_CopyConstantBlock16(void *, void *dest) {
    memcpy(dest, MemoryCopyConstantBlock16_UnknownRoleInitializedBytes, 16);
}
