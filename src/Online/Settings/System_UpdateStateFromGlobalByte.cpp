#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2250bfc; symbol: data_ov031_02250bfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage[];
extern "C" void WfcKeyboard_SetCharacterMapMode(int value);
extern "C" int WfcUtility_PlaySequenceArchiveEntry(int value);
// Original: arm9/ov031 @ 0x022247BC; symbol: func_ov031_022247bc; size: 0x30.
extern "C" void System_UpdateStateFromGlobalByte(void) {
    unsigned char *object = *(unsigned char **)WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage;
    WfcKeyboard_SetCharacterMapMode(object[0x11d] == 2 ? 0 : 2);
    WfcUtility_PlaySequenceArchiveEntry(1);
}
