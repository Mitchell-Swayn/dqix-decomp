#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cd8; symbol: data_ov031_02290cd8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" volatile unsigned char WfcUtilityWaitForScreenDelayAndSelectExit_UnknownRoleZeroInitializedStorage;
extern "C" void Graphics_LoadMainBG2AndSetDisplayModes(void);
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void WfcUtility_StartMainBackgroundAndObjectFadeIn(void);
// Original: arm9/ov031 @ 0x02233E4C; symbol: System_LoadMainBG2AndScheduleMode0x2DCallback; size: 0x30.
// Clears a shared flag, loads Main BG2 data, selects mode 0x2d, and registers the follow-up callback.
extern "C" void System_LoadMainBG2AndScheduleMode0x2DCallback(void) {
    WfcUtilityWaitForScreenDelayAndSelectExit_UnknownRoleZeroInitializedStorage = 0;
    Graphics_LoadMainBG2AndSetDisplayModes();
    Graphics_SubmitIndexedConfiguredBuffer(0x2d);
    WfcUtility_SetMainLoopCallback(WfcUtility_StartMainBackgroundAndObjectFadeIn);
}
