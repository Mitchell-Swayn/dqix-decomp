#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cfc; symbol: data_ov031_02290cfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char *NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
extern "C" void Util_ParseFourThreeByteNumbers(const char *src, unsigned char *dst);
// Original: arm9/ov031 @ 0x02235EAC; symbol: func_ov031_02235eac; size: 0x20.
extern "C" void Util_ParseGlobalFourThreeByteNumbers(const char *src) {
    Util_ParseFourThreeByteNumbers(src, (unsigned char *)(NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage + 0x4c4));
}
