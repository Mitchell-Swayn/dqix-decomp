#include <globaldefs.h>
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short *, unsigned);
extern "C" int Window_ClassifyTouchAgainstSelectedCanvas(void *);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov000 @ 0x0217C5F4; symbol: func_ov000_0217c5f4; size: 0x44.
extern "C" int BattleMenu_TestCancelInput(void *owner) {
    int globalMask = Input_IsKeyMaskNewlyPressed(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0x802);
    int statusMatch = Window_ClassifyTouchAgainstSelectedCanvas((char *)owner + 0x188) == 2;
    return (globalMask | statusMatch) != 0;
}
