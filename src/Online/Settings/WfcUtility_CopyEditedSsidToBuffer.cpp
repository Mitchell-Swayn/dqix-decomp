#include <globaldefs.h>
ARM
extern "C" void MI_CpuCopy8(void *, const void *, unsigned int);
// Original data: arm9/ov031 @ 0x2290cfc; symbol: data_ov031_02290cfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02235F0C; symbol: Network_CopyObjectBytesToGlobalStateOffset440; size: 0x24.
// Copies 0x20 bytes from the input object to offset 0x440 of the global state object.
extern "C" void WfcUtility_CopyEditedSsidToBuffer(const void *src) {
    MI_CpuCopy8((unsigned char *)(*(unsigned int *)&NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage) + 0x440, src, 0x20);
}
