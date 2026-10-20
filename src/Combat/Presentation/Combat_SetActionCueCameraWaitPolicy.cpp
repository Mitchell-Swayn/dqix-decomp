#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned char CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage;
extern "C" void Combat_SetPresentationTimerPausePolicy(void *, unsigned int);
// Original: arm9/ov025 @ 0x021E74D0; symbol: WriteGlobalOverlayByteAtOffset52DFromInput; size: 0x24.
// Writes the input word's low byte to the shared resource byte at offset 0x52D, then returns one.
extern "C" int Combat_SetActionCueCameraWaitPolicy(unsigned char *input) {
    unsigned char *base = *(unsigned char **)((unsigned char *)&CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0xc);
    Combat_SetPresentationTimerPausePolicy(base + 0x22c, *(unsigned int *)(input + 8));
    return 1;
}
