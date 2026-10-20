#include <globaldefs.h>
ARM
extern "C" void MI_CpuCopy8(const void *, void *, unsigned int);
extern "C" int Network_DispatchCombinedBufferAndWait(void *, void *, unsigned int, int, int);
// Original data: arm9/ov031 @ 0x224968c; symbol: data_ov031_0224968c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex aaaa03000000080000000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char ProcessBufferAfterSixByteHeader_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02200850; symbol: ProcessBufferAfterSixByteHeader; size: 0x5C.
// Copies six constant bytes to output +6, processes the remaining buffer, and records whether the result is negative.
extern "C" void ProcessBufferAfterSixByteHeader(void *out, int length, int arg3, int arg4) {
    MI_CpuCopy8(ProcessBufferAfterSixByteHeader_UnknownRoleInitializedBytes, (char *)out + 6, 6);
    int result = Network_DispatchCombinedBufferAndWait(out, (char *)out + 6, length - 6, arg3, arg4);
    NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[0] = result < 0;
}
