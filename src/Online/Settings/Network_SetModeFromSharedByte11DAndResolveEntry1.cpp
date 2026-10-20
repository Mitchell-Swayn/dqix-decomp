#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2250bfc; symbol: data_ov031_02250bfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage;
extern "C" void WfcKeyboard_SetCharacterMapMode(unsigned int);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned int);
// Original: arm9/ov031 @ 0x022247EC; symbol: Network_SetModeFromSharedByte11DAndResolveEntry1; size: 0x30.
// Sets the shared mode from whether byte +0x11d differs from one, then resolves global group entry 1.
extern "C" void Network_SetModeFromSharedByte11DAndResolveEntry1(void) {
    unsigned char value = *((unsigned char *)WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage + 0x11d);
    WfcKeyboard_SetCharacterMapMode(value != 1);
    WfcUtility_PlaySequenceArchiveEntry(1);
}
