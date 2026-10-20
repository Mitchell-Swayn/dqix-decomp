#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290c70; symbol: data_ov031_02290c70.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char WfcUtilityAdvanceTimedMessageCounter_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_LoadMessageBackgroundAndLowerPriorities(void);
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void System_ConfigureDisplayAndRegisterMainLoop(void);
// Original: arm9/ov031 @ 0x0222A174; symbol: System_LoadMainBG2AndScheduleMode0x21Callback; size: 0x30.
// Clears the shared flag, loads Main BG2 data, selects mode 0x21, and registers System_ConfigureDisplayAndRegisterMainLoop.
extern "C" void System_LoadMainBG2AndScheduleMode0x21Callback(void) {
    WfcUtilityAdvanceTimedMessageCounter_UnknownRoleZeroInitializedStorage = 0;
    WfcUtility_LoadMessageBackgroundAndLowerPriorities();
    Graphics_SubmitIndexedConfiguredBuffer(0x21);
    WfcUtility_SetMainLoopCallback(System_ConfigureDisplayAndRegisterMainLoop);
}
