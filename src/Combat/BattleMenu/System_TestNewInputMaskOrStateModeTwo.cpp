#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage;
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short *, unsigned);
extern "C" int Window_ClassifyTouchAgainstSelectedCanvas(void *);
// Original: arm9/ov000 @ 0x0217AB48; symbol: System_TestNewInputMaskOrStateModeTwo; size: 0x44.
// Returns true when global halfword 0x02114e30 has newly set mask 0x802 or when the state resource at +0x38 reports mode 2.
extern "C" int System_TestNewInputMaskOrStateModeTwo(const unsigned char *state) {
    int newlySelected = Input_IsKeyMaskNewlyPressed(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0x802);
    int mode = Window_ClassifyTouchAgainstSelectedCanvas(*(void **)(state + 0x38));
    return (newlySelected | (mode == 2)) != 0;
}
