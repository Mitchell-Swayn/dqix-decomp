#include <globaldefs.h>
ARM
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short*, unsigned);
extern "C" int Window_ClassifyTouchAgainstSelectedCanvas(void*);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov003 @ 0x0215DD00; symbol: func_ov003_0215dd00; size: 0x3C.
extern "C" int Inn_IsStayChoiceCancelled(void* self) {
    if (Input_IsKeyMaskNewlyPressed(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 2)) return 1;
    return Window_ClassifyTouchAgainstSelectedCanvas((char*)self + 0x98) == 2;
}
