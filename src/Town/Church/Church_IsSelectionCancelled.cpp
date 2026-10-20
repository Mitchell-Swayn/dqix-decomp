#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage;
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short*, unsigned int);
extern "C" int Window_ClassifyTouchAgainstSelectedCanvas(void*);
// Original: arm9/ov003 @ 0x0215B370; symbol: Unclassified_IsGlobalMask2NewOrFieldF4StateTwo; size: 0x4C.
// Returns true when global halfword mask 2 has newly changed, or when enabled and the object helper at +0xF4 returns 2.
extern "C" int Church_IsSelectionCancelled(unsigned char* self, int enabled) {
    if (Input_IsKeyMaskNewlyPressed(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 2)) return 1;
    if (enabled && Window_ClassifyTouchAgainstSelectedCanvas(self + 0xf4) == 2) return 1;
    return 0;
}
