#include <globaldefs.h>
ARM
// Original: arm9/ov031:0222d3b0; Uses the shared object byte at +0x29 and two lookup tables to replace packed-word fields, preserving bits under mask 0xfe00ff00.
// Original data: arm9/ov031 @ 0x2290c94; symbol: data_ov031_02290c94.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char *WfcUtilityReleaseWirelessTextEditor_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x2248ecc; symbol: data_ov031_02248ecc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 20310000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityPositionWirelessTextEditorCursor_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x2248ed0; symbol: data_ov031_02248ed0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0817263544536271808f9eadbccbdae9.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityDrawWirelessTextEditorBuffer_UnknownRoleInitializedBytes[];

extern "C" void WfcUtility_PositionWirelessTextEditorCursor(void) {
    unsigned char *object = WfcUtilityReleaseWirelessTextEditor_UnknownRoleZeroInitializedStorage;
    unsigned int *word = *(unsigned int **)(object + 4);
    unsigned char value = object[0x29];
    unsigned int low = value & 0xf;
    unsigned int high = value >> 4;
    if (value >= 0x20) {
        high = 1;
        low = 0xf;
    }
    unsigned char lowValue = WfcUtilityDrawWirelessTextEditorBuffer_UnknownRoleInitializedBytes[low];
    unsigned int old = *word;
    unsigned char highValue = WfcUtilityPositionWirelessTextEditorCursor_UnknownRoleInitializedBytes[high];
    unsigned int shifted = (unsigned int)lowValue << 23;
    *word = (old & 0xfe00ff00) | highValue | (shifted >> 7);
}
