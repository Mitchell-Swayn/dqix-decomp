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
// Original: arm9/ov023 @ 0x021E6E20; symbol: func_ov023_021e6e20; size: 0x40.
extern "C" int Menu_TestCancelKeyOrCanvasTouchKindTwo(void* object) {
    int hasMask = Input_IsKeyMaskNewlyPressed(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 2);
    int hasMode = Window_ClassifyTouchAgainstSelectedCanvas((char*)object + 0xac) == 2;
    return (hasMask | hasMode) != 0;
}
