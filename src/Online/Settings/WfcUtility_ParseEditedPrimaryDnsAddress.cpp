#include <globaldefs.h>
ARM
extern "C" int Util_ParseFourThreeByteNumbers(void*, void*);
// Original data: arm9/ov031 @ 0x2290cfc; symbol: data_ov031_02290cfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02235ECC; symbol: func_ov031_02235ecc; size: 0x20.
extern "C" int WfcUtility_ParseEditedPrimaryDnsAddress(void* a) { return Util_ParseFourThreeByteNumbers(a, (char*)NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage + 0x4c8); }
