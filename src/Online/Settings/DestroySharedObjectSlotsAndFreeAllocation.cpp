#include <globaldefs.h>
ARM
extern "C" void Overlay_ClearFourSharedObjects(void);
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void **);
// Original data: arm9/ov031 @ 0x2250bf0; symbol: data_ov031_02250bf0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int OverlayClearFourSharedObjects_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02223708; symbol: DestroySharedObjectSlotsAndFreeAllocation; size: 0x18.
// Calls the helper that destroys and clears four shared object slots, then frees the shared allocation and clears its flag.
extern "C" void DestroySharedObjectSlotsAndFreeAllocation(void) {
    Overlay_ClearFourSharedObjects();
    WfcUtility_FreeAllocationAndClearPointer((void **)&OverlayClearFourSharedObjects_UnknownRoleZeroInitializedStorage);
}
