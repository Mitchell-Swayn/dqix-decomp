#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290ce8; symbol: data_ov031_02290ce8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_CreateTaskWithBorrowedContext(unsigned, void *, unsigned, unsigned);
extern "C" void Graphics_CopyPaletteToBackgroundPaletteAndApplyMode(void);
// Original: arm9/ov031 @ 0x02235060; symbol: System_StoreValueAndScheduleTimedCallback; size: 0x2C.
// Stores the input word beside the shared control state, then schedules callback 0x0223508c with delay 0x78.
extern "C" void System_StoreValueAndScheduleTimedCallback(unsigned value) {
    *(unsigned *)((char *)&WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage + 4) = value;
    WfcUtility_CreateTaskWithBorrowedContext(1, (void *)Graphics_CopyPaletteToBackgroundPaletteAndApplyMode, 0, 0x78);
}
