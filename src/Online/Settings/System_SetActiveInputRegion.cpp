#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2250bfc; symbol: data_ov031_02250bfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage;
extern "C" void WfcKeyboard_SetKeyHighlight(int, int);
// Original: arm9/ov031 @ 0x02224A20; symbol: System_SetActiveInputRegion; size: 0x54.
// If the requested signed selection differs from shared byte +0x11F, enables the new selection, disables the previous selection, and stores the requested byte.
extern "C" void System_SetActiveInputRegion(int selection) {
    unsigned char *shared = (unsigned char *)*(void **)&WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage;
    signed char current = *(signed char *)(shared + 0x11f);
    if (selection == current)
        return;
    WfcKeyboard_SetKeyHighlight(selection, 1);
    shared = (unsigned char *)*(void **)&WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage;
    current = *(signed char *)(shared + 0x11f);
    WfcKeyboard_SetKeyHighlight(current, 0);
    shared = (unsigned char *)*(void **)&WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage;
    shared[0x11f] = (unsigned char)selection;
}
