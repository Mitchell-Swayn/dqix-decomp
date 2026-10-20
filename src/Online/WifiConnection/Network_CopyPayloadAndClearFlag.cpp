#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cfc; symbol: data_ov031_02290cfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
extern "C" void MI_CpuCopy8(const void *src, void *dst, unsigned int length);
// Original: arm9/ov031 @ 0x02235CAC; symbol: Network_CopyPayloadAndClearFlag; size: 0x30.
// Copies 0x20 input bytes to shared data+0x440 and clears the flag at +0x4e7.
extern "C" void Network_CopyPayloadAndClearFlag(const void *src) {
    MI_CpuCopy8(src, (unsigned char *)NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage + 0x440, 0x20);
    *((unsigned char *)NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage + 0x4e7) = 0;
}
