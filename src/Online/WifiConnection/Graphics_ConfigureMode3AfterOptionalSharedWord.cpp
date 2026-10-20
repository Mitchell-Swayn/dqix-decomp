#include <globaldefs.h>
ARM
extern "C" void WfcUtility_GetScreenOperationArguments(unsigned int *, unsigned int *);
extern "C" void WfcUtility_StartHeaderRightmostSpriteRetraction(unsigned int);
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void Graphics_TransitionDisplayAndSelectStoredWordCallback(void);
// Original: arm9/ov031 @ 0x02233F54; symbol: Graphics_ConfigureMode3AfterOptionalSharedWord; size: 0x58.
// Processes the optional shared word when nonzero, configures mode-3 records with masks 1 and 0x15, and installs the continuation callback.
extern "C" void Graphics_ConfigureMode3AfterOptionalSharedWord(void) {
 unsigned int value;
 WfcUtility_GetScreenOperationArguments(0, &value);
 if (value) WfcUtility_StartHeaderRightmostSpriteRetraction(value);
 WfcUtility_StartScreenBrightnessTransition(3, 1, 1, 8);
 WfcUtility_StartScreenBrightnessTransition(3, 0, 0x15, 8);
 WfcUtility_SetMainLoopCallback(Graphics_TransitionDisplayAndSelectStoredWordCallback);
}
