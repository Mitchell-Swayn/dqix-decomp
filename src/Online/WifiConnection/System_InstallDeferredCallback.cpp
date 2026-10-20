#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection();
extern "C" int WfcUtility_IsModeSpriteAnimationScheduled();
extern "C" void WfcUtility_EnableBottomButtonTouch();
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_RunNextThreeInitializationHelpers(void);
// Original: arm9/ov031 @ 0x02232810; symbol: func_ov031_02232810; size: 0x34.
extern "C" void System_InstallDeferredCallback(void) {
    if (WfcUtility_GetBottomButtonSelection() == -2) return;
    if (WfcUtility_IsModeSpriteAnimationScheduled() == 1) return;
    WfcUtility_EnableBottomButtonTouch();
    WfcUtility_SetMainLoopCallback(System_RunNextThreeInitializationHelpers);
}
