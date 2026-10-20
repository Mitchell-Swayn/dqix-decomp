#include <globaldefs.h>
ARM
// Original data: arm9/ov017 @ 0x21d83ec; symbol: data_ov017_021d83ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern void *KrakPotDrawFieldMenuSession_UnknownRoleZeroInitializedStorage;
extern "C" void RenderSelectionScreenControlsAndResult(void *);
// Original: arm9/ov017 @ 0x021B1CC4; symbol: func_ov017_021b1cc4; size: 0x20.
extern "C" void Resource_ProcessGlobalHandleIfPresent(void) {
    void *handle = KrakPotDrawFieldMenuSession_UnknownRoleZeroInitializedStorage;
    if (handle)
        RenderSelectionScreenControlsAndResult(handle);
}
