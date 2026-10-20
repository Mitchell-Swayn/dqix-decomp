#include <globaldefs.h>
ARM
extern "C" void Input_CopyCurrentOrPreviousTouchPoint(void *);
// Original data: arm9/ov031 @ 0x2290cf4; symbol: data_ov031_02290cf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x22491f4; symbol: data_ov031_022491f4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 55361e00.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcScrollbarGetPartBounds_UnknownRoleInitializedBytes[];
extern "C" void ApplyContextValueAndStoreByte1A(int);
// Original: arm9/ov031 @ 0x0223552C; symbol: ComputeAndApplyContextProgress; size: 0x68.
// Computes a nonnegative progress value clamped by the indexed limit, applies it, then writes global state byte +0x1D to 3.
extern "C" void ComputeAndApplyContextProgress(void) {
    unsigned short values[2];
    Input_CopyCurrentOrPreviousTouchPoint(values);
    unsigned char *object = (unsigned char *)*(void **)&WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage;
    unsigned char offset = WfcScrollbarGetPartBounds_UnknownRoleInitializedBytes[object[0x1b]];
    int result = (int)values[1] - *(unsigned short *)(object + 0x12) - offset / 2;
    if (result < 0)
        result = 0;
    else {
        int maximum = object[0x19] - offset;
        if (result >= maximum)
            result = maximum;
    }
    ApplyContextValueAndStoreByte1A(result);
    object = (unsigned char *)*(void **)&WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage;
    object[0x1d] = 3;
}
