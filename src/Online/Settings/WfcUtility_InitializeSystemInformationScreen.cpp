#include <globaldefs.h>
extern "C" void Graphics_LoadMainBG2AndSetBackgroundPriorities();
extern "C" void System_CreateCopyAndFinalizeResource(int);
extern "C" void WfcUtility_ShowFormattedMessagePanel(int, int, int);
extern "C" void WfcUtility_DrawMacAddressAndWfcIdentifier();
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void Graphics_ConfigureMode2Masks1And0x15ThenContinueMode2();
// Original: arm9/ov031 @ 0x02228BAC; symbol: func_ov031_02228bac; size: 0x34.
extern "C" void WfcUtility_InitializeSystemInformationScreen(void) {
    Graphics_LoadMainBG2AndSetBackgroundPriorities();
    System_CreateCopyAndFinalizeResource(0x11);
    WfcUtility_ShowFormattedMessagePanel(0x3a, -1, 0);
    WfcUtility_DrawMacAddressAndWfcIdentifier();
    WfcUtility_SetMainLoopCallback(Graphics_ConfigureMode2Masks1And0x15ThenContinueMode2);
}
