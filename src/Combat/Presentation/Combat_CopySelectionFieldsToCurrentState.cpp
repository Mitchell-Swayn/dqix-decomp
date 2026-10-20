#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned char CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov025 @ 0x021E82A0; symbol: func_ov025_021e82a0; size: 0x44.
extern "C" bool Combat_CopySelectionFieldsToCurrentState(void *selection) {
    unsigned char *state = (unsigned char *)*(void **)((unsigned char *)&CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0x0C) + 0x540;
    *(unsigned short *)(state + 0x28) |= 2;
    state[0x35] = ((unsigned char *)selection)[0x0E];
    *(short *)(state + 0x2E) = *(short *)((unsigned char *)selection + 8);
    *(short *)(state + 0x30) = *(short *)((unsigned char *)selection + 0x0A);
    *(short *)(state + 0x32) = *(short *)((unsigned char *)selection + 0x0C);
    return true;
}
