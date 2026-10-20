#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cfc; symbol: data_ov031_02290cfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage[];
extern "C" void Util_ParseFourThreeByteNumbers(const char *, unsigned char *);

// Original: arm9/ov031 @ 0x02235EEC; symbol: func_ov031_02235eec; size: 0x20.
extern "C" void Util_ParseFourThreeByteNumbersIntoGlobalBuffer(const char *source) {
    Util_ParseFourThreeByteNumbers(source, (unsigned char *)NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage[0] + 0x4cc);
}
