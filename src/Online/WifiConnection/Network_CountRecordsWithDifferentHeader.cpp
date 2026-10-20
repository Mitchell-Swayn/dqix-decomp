#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cf8; symbol: data_ov031_02290cf8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x22491fc; symbol: data_ov031_022491fc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkUpdateWirelessScanEntryCache_UnknownRoleInitializedBytes_Variant2[];
extern "C" int RuntimeMemory_CompareByteRanges(const void *, const void *, unsigned int);
// Original: arm9/ov031 @ 0x02235984; symbol: Network_CountRecordsWithDifferentHeader; size: 0x5C.
// Compares 20 six-byte record headers with the shared value, returns the mismatch count, and outputs the table base.
extern "C" unsigned int Network_CountRecordsWithDifferentHeader(void **out) {
    unsigned char *base = *(unsigned char **)WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage + 0x1300;
    *out = base;
    unsigned int matches = 0;
    int i = 0;
    unsigned char *record = base;
    do {
        if (RuntimeMemory_CompareByteRanges(record + 0x20, NetworkUpdateWirelessScanEntryCache_UnknownRoleInitializedBytes_Variant2, 6) != 0) ++matches;
        ++i;
        record += 0x2a;
    } while (i < 20);
    return matches;
}
