#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cfc; symbol: data_ov031_02290cfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned *NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
extern "C" void Util_ParseFourThreeByteNumbers(void *, void *);
// Original: arm9/ov031 @ 0x02235E90; symbol: func_ov031_02235e90; size: 0x1C.
extern "C" void WfcUtility_ParseEditedSubnetMask(void *argument) {
    Util_ParseFourThreeByteNumbers(argument, (char *)NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage + 0x4f0);
}
