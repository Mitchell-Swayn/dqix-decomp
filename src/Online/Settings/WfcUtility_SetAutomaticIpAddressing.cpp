#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cfc; symbol: data_ov031_02290cfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02235C84; symbol: func_ov031_02235c84; size: 0x14.
extern "C" void WfcUtility_SetAutomaticIpAddressing(unsigned char value) {
    *(unsigned char *)((char *)*(void **)NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage + 0x4f5) = value;
}
