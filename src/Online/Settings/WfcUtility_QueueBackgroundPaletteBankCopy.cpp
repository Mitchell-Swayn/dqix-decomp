#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290ce8; symbol: data_ov031_02290ce8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage[];
extern "C" void Graphics_CopySixteenHalfwordsToEdgeColorRegisters(void*,void*);
extern "C" void* WfcUtility_CreateTaskWithBorrowedContext(unsigned,void (*)(void*,void*),void*,unsigned);
// Original: arm9/ov031 @ 0x02234FF8; symbol: func_ov031_02234ff8; size: 0x3C.
extern "C" void WfcUtility_QueueBackgroundPaletteBankCopy(unsigned base, unsigned index, unsigned position) {
    WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage[1] = base + (index << 5);
    WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage[2] = (position << 5) + 0x05000000;
    WfcUtility_CreateTaskWithBorrowedContext(1, &Graphics_CopySixteenHalfwordsToEdgeColorRegisters, 0, 0x78);
}
