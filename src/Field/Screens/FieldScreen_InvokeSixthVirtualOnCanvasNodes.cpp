#include <globaldefs.h>
ARM
// Original data: arm9/ov017 @ 0x21d83f0; symbol: data_ov017_021d83f0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" void *ResourceGetSharedLoadState_UnknownRoleZeroInitializedStorage[];
extern "C" void Menu_InvokeDisplayObjectsFifthVirtualPass(void *object);
// Original: arm9/ov017 @ 0x021B2368; symbol: func_ov017_021b2368; size: 0x20.
extern "C" void FieldScreen_InvokeSixthVirtualOnCanvasNodes(void) {
    void *object = ResourceGetSharedLoadState_UnknownRoleZeroInitializedStorage[1];
    if (object)
        Menu_InvokeDisplayObjectsFifthVirtualPass(object);
}
