#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" int WfcUtility_IsBottomButtonBarAbsentOrNotClosing();
extern "C" void Graphics_ClearIndexedMainBackgroundCharacterData(int);
extern "C" int Overlay_ProcessPendingFlag();
extern "C" void WfcUtility_DisableDisplayPlanes(unsigned engine,unsigned mask);
extern "C" void WfcUtility_GetScreenOperationArguments(unsigned* a,unsigned* b);
extern "C" void WfcUtility_SetNavigationContext(unsigned a,unsigned b);
extern "C" void WfcUtility_SetScreenOperationArguments(unsigned int a,unsigned int b);
extern "C" void WfcSettingsList_SetEntryOriginMode(unsigned char value);
extern "C" void WfcUtility_SetMainLoopCallback(void(*)(void));
extern "C" void Ov031_InitializeSecondaryTransition();
extern "C" void WfcSettingsList_InitializeScreen();
// Original: arm9/ov031 @ 0x0222E960; symbol: func_ov031_0222e960; size: 0xB4.
extern "C" void Graphics_TransitionFromIdleDisplayContexts() {
    if (WfcUtility_IsScreenTransitionBusy(1)) return;
    if (WfcUtility_IsScreenTransitionBusy(0)) return;
    if (!WfcUtility_IsBottomButtonBarAbsentOrNotClosing()) return;
    Graphics_ClearIndexedMainBackgroundCharacterData(0);
    Overlay_ProcessPendingFlag();
    WfcUtility_DisableDisplayPlanes(1, 1);
    WfcUtility_DisableDisplayPlanes(0, 0x15);
    unsigned value;
    WfcUtility_GetScreenOperationArguments(0, &value);
    if (value) {
        WfcUtility_SetNavigationContext(2, 1);
        WfcUtility_SetMainLoopCallback(Ov031_InitializeSecondaryTransition);
    } else {
        WfcUtility_SetNavigationContext(2, 0);
        WfcUtility_SetScreenOperationArguments(0, 0);
        WfcSettingsList_SetEntryOriginMode(0);
        WfcUtility_SetMainLoopCallback(WfcSettingsList_InitializeScreen);
    }
}
