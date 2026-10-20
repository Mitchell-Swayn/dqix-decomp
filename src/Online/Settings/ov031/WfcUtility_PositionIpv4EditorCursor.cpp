#include <globaldefs.h>
ARM
struct WordFields { unsigned low:8, preserved:8, selection:9, upper:7; };
struct SelectionState { unsigned unknown; unsigned* word; unsigned char pad[12]; unsigned char selector; };
extern "C" SelectionState* WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage;
extern "C" unsigned char WfcUtilityDrawIpv4EditorDigits_UnknownRoleInitializedBytes_Variant2[];
inline int ClampSelectorToThree(int value) { if (value > 3) value = 3; return value; }
// Original: arm9/ov031 @ 0x0222E048; symbol: WfcUtility_PositionIpv4EditorCursor; size: 0x54.
// Clamps shared selector to three and writes low byte 0x28 and a nine-bit selection
// field from byte 3*selector+2 of the shared three-byte-entry table.
extern "C" void WfcUtility_PositionIpv4EditorCursor() {
    SelectionState* state = WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage;
    int index = ClampSelectorToThree(state->selector);
    unsigned* word = state->word;
    unsigned fields;
    unsigned value = WfcUtilityDrawIpv4EditorDigits_UnknownRoleInitializedBytes_Variant2[index*3+2];
    fields = *word;
    *word = ((value << 23) >> 7) | ((fields & 0xfe00ff00) | 0x28);
}
