#include <globaldefs.h>
ARM
// Original data: arm9/ov017 @ 0x21d83f0; symbol: data_ov017_021d83f0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned int ResourceGetSharedLoadState_UnknownRoleZeroInitializedStorage[];
extern "C" void Menu_InvokeDisplayRecordSecondVirtualPass(void *);
// Original: arm9/ov017 @ 0x021B2328; symbol: func_ov017_021b2328; size: 0x20.
extern "C" void FieldScreen_InvokeSecondVirtualOnCanvasNodes(void) {
    void *p = (void *)ResourceGetSharedLoadState_UnknownRoleZeroInitializedStorage[1];
    if (p) Menu_InvokeDisplayRecordSecondVirtualPass(p);
}
