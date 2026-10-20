#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov001 @ 0x216587c; symbol: data_ov001_0216587c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char ResourceDispatchGlobalPairAndReturnZero_UnknownRoleZeroInitializedStorage[];
extern "C" void Resource_DispatchValueToAlternateOrEmbeddedResource(unsigned char *p, void *target, unsigned amount);
// Original: arm9/ov001 @ 0x021599B8; symbol: func_ov001_021599b8; size: 0x24.
extern "C" int Resource_DispatchGlobalPairAndReturnZero(void) {
    Resource_DispatchValueToAlternateOrEmbeddedResource(Main_UnknownRoleZeroInitializedStorage, ResourceDispatchGlobalPairAndReturnZero_UnknownRoleZeroInitializedStorage, 0);
    return 0;
}
