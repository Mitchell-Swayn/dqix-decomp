#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290ce8; symbol: data_ov031_02290ce8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02234F34; symbol: func_ov031_02234f34; size: 0x18.
extern "C" void WfcUtility_MarkBackgroundTilemapDirty(void) {
    *(unsigned char *)((char *)*(void **)WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage + 0x604) = 1;
}
