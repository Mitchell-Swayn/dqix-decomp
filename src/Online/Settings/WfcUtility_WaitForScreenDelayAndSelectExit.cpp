#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cd8; symbol: data_ov031_02290cd8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityWaitForScreenDelayAndSelectExit_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_GetScreenOperationArguments(unsigned*, unsigned*);
extern "C" unsigned WfcUtility_GetInitialMenuSelector(void);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void System_ConfigureDisplayPlanesAndCallback(void);
extern "C" void Graphics_ConfigureMode3AfterOptionalSharedWord(void);
// Original: arm9/ov031 @ 0x02234050; symbol: func_ov031_02234050; size: 0x70.
extern "C" void WfcUtility_WaitForScreenDelayAndSelectExit(void) {
    WfcUtilityWaitForScreenDelayAndSelectExit_UnknownRoleZeroInitializedStorage++;
    if (WfcUtilityWaitForScreenDelayAndSelectExit_UnknownRoleZeroInitializedStorage < 0xb4)
        return;
    unsigned sharedWord;
    WfcUtility_GetScreenOperationArguments(0, &sharedWord);
    unsigned state = WfcUtility_GetInitialMenuSelector();
    if (state != 0 && state == 1 && sharedWord)
        WfcUtility_SetMainLoopCallback((void*)System_ConfigureDisplayPlanesAndCallback);
    else
        WfcUtility_SetMainLoopCallback((void*)Graphics_ConfigureMode3AfterOptionalSharedWord);
}
