#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290ce8; symbol: data_ov031_02290ce8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char *WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage;
extern "C" void MIi_CpuCopy16(const void *, volatile void *, int);
// Original: arm9/ov031 @ 0x02234F4C; symbol: func_ov031_02234f4c; size: 0x58.
extern "C" void Overlay_CopyBlocksToGlobalTable(const void *source, int index, int halfwordCount, int blockCount) {
    volatile char *destination = WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage + 4 + index * 2;
    int i = 0;
    if (blockCount <= 0) return;
    int bytes = halfwordCount << 1;
    do {
        MIi_CpuCopy16(source, destination, bytes);
        source = (const char *)source + 0x40;
        destination += 0x40;
        i++;
    } while (i < blockCount);
}
