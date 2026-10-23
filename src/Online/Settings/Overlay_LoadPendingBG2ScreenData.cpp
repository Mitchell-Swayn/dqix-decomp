#include <globaldefs.h>
ARM
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*, unsigned);
extern "C" void LoadToMainBG2ScreenData(const void*, unsigned, unsigned);
// Original data: arm9/ov031 @ 0x2290ce8; symbol: data_ov031_02290ce8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* volatile WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02234FA4; symbol: func_ov031_02234fa4; size: 0x54.
extern "C" void Overlay_LoadPendingBG2ScreenData(void*,void*) {
    void* buffer = WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage;
    if (*(volatile unsigned char*)((char*)buffer + 0x604) == 0) return;
    _Z25CleanInvalidateCacheRangePKvj((char*)buffer + 4, 0x600);
    buffer = WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage;
    LoadToMainBG2ScreenData((char*)buffer + 4, 0, 0x600);
    buffer = WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage;
    *(volatile unsigned char*)((char*)buffer + 0x604) = 0;
}
