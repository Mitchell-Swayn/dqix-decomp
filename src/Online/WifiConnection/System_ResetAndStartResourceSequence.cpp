#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cdc; symbol: data_ov031_02290cdc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemResetAndStartResourceSequence_UnknownRoleZeroInitializedStorage[];
extern "C" void Graphics_LoadMainBG2ResourceBdb4AndSetPriorities();
extern "C" void System_CreateCopyAndFinalizeResource(unsigned);
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(unsigned);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void System_ConfigureDisplayAndRegisterMainLoopB();
// Original: arm9/ov031 @ 0x02234314; symbol: func_ov031_02234314; size: 0x40.
extern "C" void System_ResetAndStartResourceSequence(void) {
    SystemResetAndStartResourceSequence_UnknownRoleZeroInitializedStorage[0] = 0;
    Graphics_LoadMainBG2ResourceBdb4AndSetPriorities();
    System_CreateCopyAndFinalizeResource(8);
    Graphics_SubmitIndexedConfiguredBuffer(0x29);
    WfcUtility_PlaySequenceArchiveEntry(0x10);
    WfcUtility_SetMainLoopCallback(System_ConfigureDisplayAndRegisterMainLoopB);
}
