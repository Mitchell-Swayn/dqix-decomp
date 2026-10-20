#include <globaldefs.h>
ARM
extern "C" {
typedef void (*MainLoopCallback)(void);
void WfcUtility_SetMainLoopCallback(MainLoopCallback);
// Original data: arm9/ov031 @ 0x2290cdc; symbol: data_ov031_02290cdc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SystemResetAndStartResourceSequence_UnknownRoleZeroInitializedStorage;
void WfcUtility_StartTimedScreenFadeOut(void);
// Original: arm9/ov031 @ 0x022344EC; symbol: func_ov031_022344ec; size: 0x34.
void WfcUtility_WaitForTimedScreenFadeOut(void) {
    unsigned int next = (unsigned int)SystemResetAndStartResourceSequence_UnknownRoleZeroInitializedStorage + 1;
    SystemResetAndStartResourceSequence_UnknownRoleZeroInitializedStorage = next;
    unsigned int count = next & 0xff;
    if (count >= 0x78) WfcUtility_SetMainLoopCallback(WfcUtility_StartTimedScreenFadeOut);
}
}
