#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290ce8; symbol: data_ov031_02290ce8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage[];
extern "C" void MIi_CpuCopy16(const void *, volatile void *, int);
extern "C" void WfcUtility_RequestTaskRemoval(unsigned,void*);
// Original: arm9/ov031 @ 0x0223508C; symbol: func_ov031_0223508c; size: 0x30.
extern "C" void Graphics_CopyPaletteToBackgroundPaletteAndApplyMode(void* mode,void*) {
    MIi_CpuCopy16(*(void **)(WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage + 4), (volatile void *)0x05000000, 0x200);
    WfcUtility_RequestTaskRemoval(1, mode);
}
